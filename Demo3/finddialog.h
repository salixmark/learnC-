#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include <QDialog> //qt中已经做好了对话框文件
class QWidget;//因为仅需要一个指针，所以写一下前置声明就行了，不需要包含整个头文件
class QLabel;//标签，显示为窗口中的文字
class QLineEdit;//一行的文本编辑
class QCheckBox;//确认框，通过用户是否标记来确认条件
class QPushButton;//按钮
class FindDialog : public QDialog //新做的对话框继承自原对话框
{
    Q_OBJECT
    //信号和槽都是Qt的宏，在类里面使用了信号和槽，就必须加上Q_OBJECT
    //这样预处理会处理信号和槽，将他们变成C++
    //每次加Q_OBJECT就需要执行一次qmake（右击总文件夹先清除再执行qmake）不然会出错
public:
    FindDialog(QWidget *parent=0);
signals://如何处理下面的两个信号暂时不做，本次只是做一个查找对话框
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);
private slots:
    void enabledFindButton(const QString &text);//激活槽
    void findClicked();//是否点击区分大小写的槽
private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;//区分大小写
    QCheckBox *backwardCheckBox;//向后查找
    QPushButton *findBUtton;//查找按钮
    QPushButton *closeButtom;//关闭按钮
};

#endif // FINDDIALOG_H
