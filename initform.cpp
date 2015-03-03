#include "initform.h"
#include "ui_initform.h"


initForm::initForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::initForm)
{
    ui->setupUi(this);
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    future=QtConcurrent::run(initSystem);
    futurewatcher.setFuture(future);
    connect(&futurewatcher, SIGNAL(finished()), this, SLOT(initfinished()));


}

initForm::~initForm()
{
    delete ui;
}
void initSystem(){


    //
}

void initForm::initfinished(){

    //uinitForm->hide();

}
