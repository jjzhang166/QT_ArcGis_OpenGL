#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    subwidget = NULL;
    uForm3D = new Form3D(this);
    uForm3D->move(100,50);
    uForm3D->hide();

    uFormExcel = new FormExcel(this);
    uFormExcel->move(100,50);
    uFormExcel->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ChangeUI(QWidget *temp_widget){



    if (subwidget != NULL){

        subwidget->hide();
    }

    subwidget = temp_widget;
    subwidget->show();
}
void MainWindow::on_pushButton_clicked()
{
    ChangeUI(uForm3D);
}

void MainWindow::on_pushButton_2_clicked()
{
    ChangeUI(uFormExcel);
}
