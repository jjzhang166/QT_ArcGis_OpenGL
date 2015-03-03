#include "paint3dform.h"
#include "ui_paint3dform.h"

paint3dForm::paint3dForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paint3dForm)
{
    ui->setupUi(this);

        uMyglwidget = new Myglwidget(this);
        uMyglwidget->setGeometry(50,50,600,500);
        uMyglwidget->show();
}

paint3dForm::~paint3dForm()
{
    delete ui;
}
