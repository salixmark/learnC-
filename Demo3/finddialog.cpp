#include "finddialog.h"
#include <QtWidgets>//最重要的头文件
FindDialog::FindDialog(QWidget *parent):QDialog(parent)
{
    label = new QLabel(tr("找什么(&W)"));
    //tr是qt独有的函数，可以把文本做成多语言，&W表示设置快捷键为W
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);//将label和lineEdit连接起来，使得光标出现在文本框里
    caseCheckBox = new QCheckBox(tr("区分大小写(&C)"));
    backwardCheckBox = new QCheckBox(tr("向后查找(&B)"));

    findBUtton= new QPushButton(tr("查找(&F)"));
    findBUtton->setDefault(true);//设置为缺省按钮，按回车即可使用
    findBUtton->setEnabled(false);//设为未激活状态

    closeButtom = new QPushButton(tr("关闭(&X)"));

    connect(lineEdit,SIGNAL(textChanged(QString)),
            this,SLOT(enabledFindButton(QString)));//将文本框的文本改变与激活作用连接起来

    connect(closeButtom,SIGNAL(clicked()),this,SLOT(close()));//将单击与关闭按钮连接，close()继承自Dialog

    QHBoxLayout *topLeftLayout = new QHBoxLayout;//左侧上方水平布局
    topLeftLayout->addWidget(label);//加入标签
    topLeftLayout->addWidget(lineEdit);//加入文本框

    QVBoxLayout *leftLayout = new QVBoxLayout;//左侧垂直布局
    leftLayout->addLayout(topLeftLayout);//将左侧上方的水平布局加入左侧的整体垂直布局
    leftLayout->addWidget(caseCheckBox);//加入区分大小写选项
    leftLayout->addWidget(backwardCheckBox);//加如向后查找选项；

    QVBoxLayout *rightLayout= new QVBoxLayout;//右侧垂直布局
    rightLayout->addWidget(findBUtton);//加入查找按钮
    rightLayout->addWidget(closeButtom);//加入关闭按钮
    rightLayout->addStretch();//加入一个可自由伸缩的空白框，不做任何显示，仅为左右对齐

    QHBoxLayout *mainLayout = new QHBoxLayout;//总布局
    mainLayout->addLayout(leftLayout);//加入左侧布局
    mainLayout->addLayout(rightLayout);//加入右侧布局

    setLayout(mainLayout);//将总布局加入当前对话框的布局
    setWindowTitle(tr("查找"));//设置对话框的标题
    setFixedHeight(sizeHint().height());//设置最佳高度
}
void FindDialog::enabledFindButton(const QString &text)
{
    findBUtton->setEnabled(!text.isEmpty());//如果文本框中不是空文本就激活按钮
}
void FindDialog::findClicked()//是否点击区分大小写
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ?
                Qt::CaseSensitive : Qt::CaseInsensitive;//判断是否区分大小写
    if(backwardCheckBox->isChecked())
    {
        emit findPrevious(text, cs);//发射信号
    }else{
        emit findNext(text,cs);
    }
}
