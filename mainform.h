#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

#include <QMenuBar>
#include <QMenu>
#include <QAction>


#include "paint2ddialog.h"
#include "paint2dform.h"
#include "paint3dform.h"
#include "frmmain.h"
#include "initform.h"
namespace Ui {
class mainForm;
}

class mainForm : public QWidget
{
    Q_OBJECT

public:
    explicit mainForm(QWidget *parent = 0);
    void changeUI(QWidget *temp_widget);
    void changeUI(QDialog *temp_dialog);
    ~mainForm();

private:
    Ui::mainForm *ui;

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void on_btnMenu_Close_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Min_clicked();

    void newobject();//新建
    void openfile();//打开
    void savefile();//保存

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    void InitStyle();
    void Initdialog();

    QPoint mousePoint;
    bool mousePressed;
    bool max;
    QRect location;
private:


    QMenuBar *menuBar;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionNew;

    paint2dDialog *upaint2dDialog;
    frmMain *ufrmMain;
    QDialog *subDialog;

    paint2dForm *upaint2dForm;
    paint3dForm *upaint3dForm;


    QWidget *subWidget;

    Myglwidget *uMyglwidget;
};

#endif // MAINFORM_H
