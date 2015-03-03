#include "form3d.h"
#include "ui_form3d.h"

Form3D::Form3D(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form3D)
{
    ui->setupUi(this);
    uMyglwidget = new Myglwidget(this);
    uMyglwidget->setGeometry(50,50,600,500);
    uMyglwidget->show();
}

Form3D::~Form3D()
{
    delete ui;
}
