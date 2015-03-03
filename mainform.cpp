#include "mainform.h"
#include "ui_mainform.h"
#include "helper/iconhelper.h"
#include "helper/myhelper.h"

#include <QFileDialog>
mainForm::mainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainForm)
{
    ui->setupUi(this);

    myHelper::FormInCenter(this);



    this->InitStyle();
    this->Initdialog();


}

mainForm::~mainForm()
{
    delete ui;
}
void mainForm::InitStyle(){

    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    location = this->geometry();
    max = false;
    mousePressed = false;

    //安装事件监听器,让标题栏识别鼠标双击
    ui->lab_Title->installEventFilter(this);

    IconHelper::Instance()->SetIcon(ui->btnMenu_Close, QChar(0xf00d), 10);
    IconHelper::Instance()->SetIcon(ui->btnMenu_Max, QChar(0xf096), 10);
    IconHelper::Instance()->SetIcon(ui->btnMenu_Min, QChar(0xf068), 10);
    IconHelper::Instance()->SetIcon(ui->btnMenu, QChar(0xf0c9), 10);
    IconHelper::Instance()->SetIcon(ui->lab_Ico, QChar(0xf015), 12);

    //创建菜单栏
    menuBar = new QMenuBar(ui->Widget_menu);
    menuBar->setGeometry(QRect(0, 0, 2000, 23));
    QMenu* menu = menuBar->addMenu(tr("&文件"));

    actionNew = menu->addAction(tr("&新建"));
    actionOpen = menu->addAction(tr("&打开"));
    actionOpen->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    actionSave = menu->addAction(tr("&保存"));

    connect(actionNew, SIGNAL(triggered()),this, SLOT(newobject()));
    connect(actionOpen, SIGNAL(triggered()),this, SLOT(openfile()));
    connect(actionSave, SIGNAL(triggered()),this, SLOT(savefile()));





}

void mainForm::Initdialog(){

    //初始化
    subDialog = NULL;
    subWidget = NULL;
    //dialog
    upaint2dDialog = new paint2dDialog(this);
    upaint2dDialog->setGeometry(100,50,750,550);
    upaint2dDialog->hide();
    //widget
    ufrmMain = new frmMain;
    //ufrmMain->setGeometry(0,50,480,360);
    ufrmMain->hide();

    upaint2dForm = new paint2dForm(this);
    upaint2dForm->setGeometry(100,50,750,550);
    upaint2dForm->hide();

    upaint3dForm = new paint3dForm(this);
    upaint3dForm->setGeometry(100,80,750,550);
    upaint3dForm->hide();


}
bool mainForm::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        this->on_btnMenu_Max_clicked();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void mainForm::mouseMoveEvent(QMouseEvent *e)
{
    if (mousePressed && (e->buttons() && Qt::LeftButton) && !max) {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}

void mainForm::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void mainForm::mouseReleaseEvent(QMouseEvent *)
{
    mousePressed = false;
}

void mainForm::on_btnMenu_Close_clicked()
{
    qApp->exit();
}

void mainForm::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
        IconHelper::Instance()->SetIcon(ui->btnMenu_Max, QChar(0xf096), 10);
        ui->btnMenu_Max->setToolTip("最大化");


    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        IconHelper::Instance()->SetIcon(ui->btnMenu_Max, QChar(0xf079), 10);
        ui->btnMenu_Max->setToolTip("还原");
    }
    max = !max;
}

void mainForm::on_btnMenu_Min_clicked()
{
    this->showMinimized();
}


void mainForm::newobject(){

    //新建

    qDebug()<<"new"<<endl;

}
void mainForm::openfile(){

    //打开
    QString fileName = QFileDialog::getOpenFileName(this, tr(""),"file",tr("xmlfile(*.xml);;Allfile(*.*)"));
    if(fileName!=""){


    }

}
void mainForm::savefile(){
   //保存

    QString filename = QFileDialog::getSaveFileName(this,"保存指令文件",".","Xml Files(*.xml)");

    if(filename!=""){

    }
}

void mainForm::changeUI(QWidget *temp_widget){


    if (subDialog != NULL){

        subDialog->hide();
    }
    if (subWidget != NULL){

        subWidget->hide();
    }

    subWidget = temp_widget;
    subWidget->show();

}
void mainForm::changeUI(QDialog *temp_dialog){

    if (subWidget != NULL){

        subWidget->hide();
    }
    if (subDialog != NULL){

        subDialog->hide();
    }

    subDialog = temp_dialog;
    subDialog->show();

}
void mainForm::on_pushButton_clicked()
{

    changeUI(upaint2dForm);
    //upaint2dForm->show();
    //this->setFocus();
}

void mainForm::on_pushButton_2_clicked()
{
    changeUI(upaint2dDialog);

}

void mainForm::on_pushButton_3_clicked()
{
    ufrmMain->show();
}

void mainForm::on_pushButton_4_clicked()
{
    changeUI(upaint3dForm);
    //upaint3dForm->show();
}
