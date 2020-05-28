#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

namespace Ui {
class SortDialog;
}

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortDialog(QWidget *parent = nullptr);
    ~SortDialog();

    void setColumnRange(QChar first,QChar last);//设置下拉框中内容
private:
    Ui::SortDialog *ui;
};

#endif // SORTDIALOG_H
