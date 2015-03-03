#include "paint2ddialog.h"
#include "ui_paint2ddialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QAxObject>
#include <QDebug>
paint2dDialog::paint2dDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paint2dDialog)
{
    ui->setupUi(this);
    //设置窗体标题栏隐藏，嵌入其他窗口
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    model = new QStandardItemModel();
    model->setColumnCount(12);
    //表头信息显示居左
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    for(int i=0;i<12;i++){
         //ui->tableView->horizontalHeader()->setResizeMode(i,QHeaderView::Fixed);
         ui->tableView->setColumnWidth(i,46);

    }
    model->setItem(0,0,new QStandardItem(QString("%1").arg(1)));
    model->setItem(0,1,new QStandardItem(QString("%1").arg(1)));



}

paint2dDialog::~paint2dDialog()
{
    delete ui;
}

void paint2dDialog::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开表格"),"F:/QUI/files",tr("xmlfile(*.xlsx);;Allfile(*.*)"));
    if(fileName!=""){

        readExcel(fileName);
    }



//    model->setItem(0,0,new QStandardItem(QString("%1").arg(2)));
//    model->setItem(0,1,new QStandardItem(QString("%1").arg(2)));
//    this->hide();
//    this->show();

}
void paint2dDialog::readExcel(QString str_path)
{


    qDebug()<<"000"<<endl;
    QAxObject *excel = NULL;
    QAxObject *workbooks = NULL;
    QAxObject *workbook = NULL;
    excel = new QAxObject("Excel.Application");
    if (!excel)
    {
        QMessageBox::critical(this, "错误信息", "EXCEL对象丢失");
        return;
    }
    excel->dynamicCall("SetVisible(bool)", false);
    workbooks = excel->querySubObject("WorkBooks");
    workbook = workbooks->querySubObject("Open(QString, QVariant)", str_path);
    QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1);//打开第一个sheet
 //QAxObject * worksheet = workbook->querySubObject("WorkSheets");//获取sheets的集合指针
 //int intCount = worksheet->property("Count").toInt();//获取sheets的数量

    QAxObject * usedrange = worksheet->querySubObject("UsedRange");//获取该sheet的使用范围对象
    QAxObject * rows = usedrange->querySubObject("Rows");
    QAxObject * columns = usedrange->querySubObject("Columns");
    /*获取行数和列数*/
    int intRowStart = usedrange->property("Row").toInt();
    int intColStart = usedrange->property("Column").toInt();
    int intCols = columns->property("Count").toInt();
    int intRows = rows->property("Count").toInt();
    /*获取excel内容*/
    qDebug()<<"111"<<endl;
    for (int i = intRowStart; i < intRowStart + intRows; i++)  //行
    {
        for (int j = intColStart; j < intColStart + intCols; j++)  //列
        {
            QAxObject * cell = worksheet->querySubObject("Cells(int,int)", i, j );  //获取单元格
           // qDebug() << i << j << cell->property("Value");         //*****************************出问题!!!!!!
            //qDebug() << i << j <<cell->dynamicCall("Value2()").toString(); //正确
            float value = cell->dynamicCall("Value2()").toFloat();
            QString str = QString::number(value, 'f', 2);
            value = str.toFloat();
            //把量程放入二维数组
            if((i>=6&&i<=13)&&j!=1){

                arg[i-6][j-2] = value;
            }
        }
    }
    qDebug()<<"222"<<endl;
    workbook->dynamicCall("Close (Boolean)", false);
    //同样，设置值，也用dynamimcCall("SetValue(const QVariant&)", QVariant(QString("Help!")))这样才成功的。。
   // excel->dynamicCall("Quit (void)");
    delete excel;//一定要记得删除，要不线程中会一直打开excel.exe

    //放入结构体数组

    int m=0;
    for(int i= 0;i<6;i++){

        for(int k=0;k<12;k++){

            m++;
            model->setItem(i,k,new QStandardItem(QString("%1").arg(arg[i][k])));

            //qDebug()<<arg[i][k]<<endl;
        }

    }
    qDebug()<<"333"<<endl;



}
