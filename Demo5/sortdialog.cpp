#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);
    ui->Second->hide();//隐藏该栏
    ui->Third->hide();
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);//设置对话框布局为固定大小
    setColumnRange('A','Z');
}

SortDialog::~SortDialog()
{
    delete ui;
}
void SortDialog::setColumnRange(QChar first, QChar last)
{
    ui->primarycombo->clear();//先清除下拉框中内容
    ui->secondcombo->clear();
    ui->thirdcombo->clear();

    ui->secondcombo->addItem(tr("None"));//在后面两个下拉框中添加None选项
    ui->thirdcombo->addItem(tr("None"));
    QChar ch = first;
    while(ch<=last)//循环添加字母
    {
        ui->primarycombo->addItem(QString(ch));//在第一个下拉框中添加ch中的字母，依次类推
        ui->secondcombo->addItem(QString(ch));
        ui->thirdcombo->addItem(QString(ch));
        ch=ch.unicode()+1;//字母往后挪一位
    }
}
