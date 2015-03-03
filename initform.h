#ifndef INITFORM_H
#define INITFORM_H

#include <QWidget>
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

namespace Ui {
class initForm;
}

class initForm : public QWidget
{
    Q_OBJECT

public:
    explicit initForm(QWidget *parent = 0);
    void initfinished();
    ~initForm();

private:
    Ui::initForm *ui;
    //初始化线程
    QFuture<void> future;
    QFutureWatcher<void> futurewatcher;
};
void initSystem();//初始化线程函数
#endif // INITFORM_H
