#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form3d.h"
#include "formexcel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void ChangeUI(QWidget *temp_widget);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QWidget *subwidget;
    Form3D *uForm3D;
    FormExcel *uFormExcel;
};

#endif // MAINWINDOW_H
