#ifndef FORMEXCEL_H
#define FORMEXCEL_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class FormExcel;
}

class FormExcel : public QWidget
{
    Q_OBJECT

public:
    explicit FormExcel(QWidget *parent = 0);
    ~FormExcel();

private:
    Ui::FormExcel *ui;
    QStandardItemModel *model;
};

#endif // FORMEXCEL_H
