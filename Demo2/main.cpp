#include "mainwindow.h"
#include <QHBoxLayout>//水平布局框
#include <QApplication>
#include <QSlider>//滑块
#include <QSpinBox>//数字微调
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window = new QWidget;//新建窗口
    window->setWindowTitle("Enter Your Age");//设置窗口标题
    QSpinBox *spinBox =new QSpinBox;//新建数字微调框
    QSlider *slider = new QSlider(Qt::Horizontal);//新建滑块,需要括号里面的语句，不然滑块会竖直分布
    spinBox->setRange(0,130);//设置范围
    slider->setRange(0,130);
    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));//建立信号和槽的连接
    QObject::connect(slider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));//使得滑块和数字框同步
    spinBox->setValue(30);//设置初值
    QHBoxLayout *layout = new QHBoxLayout;//设置水平布局
    layout->addWidget(spinBox);//将数字微调框加入水平布局，先加入的显示在左侧
    layout->addWidget(slider);//滑块加入水平布局
    window->setLayout(layout);//水平布局加入窗口
    window->show();//显示窗口
    return a.exec();
}
