#include "paint2dform.h"
#include "ui_paint2dform.h"

paint2dForm::paint2dForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paint2dForm)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));
    ui->graphicsView->setScene(scene);
}

paint2dForm::~paint2dForm()
{
    delete ui;
}

void paint2dForm::on_pushButton_clicked()
{

}
