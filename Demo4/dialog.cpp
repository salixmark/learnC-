#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    //正则表达式,中括号按顺序限制输入内容格式，大括号限制第二个数字的个数为0-2个
    ui->lineEdit->setValidator(new QRegExpValidator(regExp,this));
    //QRegExpValidator是正则表达式验证器（验证行输入），this指当前对话框窗口
    //QRegExpValidator是this的子对象，qt在删除对话框时会一并删除子对象，不用多写delte了
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::textChanged()
{
    ui->pushButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}//当文本框内输入规定内容时激活按钮
