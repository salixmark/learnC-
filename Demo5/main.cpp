//#include "dialog.h"
#include<sortdialog.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Dialog w;
    SortDialog w;
    w.show();
    return a.exec();
}
