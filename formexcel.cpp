#include "formexcel.h"
#include "ui_formexcel.h"

FormExcel::FormExcel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormExcel)
{
    ui->setupUi(this);

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

FormExcel::~FormExcel()
{
    delete ui;
}
