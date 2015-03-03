#ifndef PAINT2DDIALOG_H
#define PAINT2DDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
namespace Ui {
class paint2dDialog;
}

class paint2dDialog : public QDialog
{
    Q_OBJECT

public:
    explicit paint2dDialog(QWidget *parent = 0);
    ~paint2dDialog();

private slots:
    void on_pushButton_clicked();

public:
    QStandardItemModel  *model;
    float arg[8][12];
private:


    void readExcel(QString str_path);

private:
    Ui::paint2dDialog *ui;
};

#endif // PAINT2DDIALOG_H
