#ifndef PAINT2DFORM_H
#define PAINT2DFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QGraphicsScene>
namespace Ui {
class paint2dForm;
}

class paint2dForm : public QWidget
{
    Q_OBJECT

public:
    explicit paint2dForm(QWidget *parent = 0);
    ~paint2dForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::paint2dForm *ui;
    QStandardItemModel  *model;
    QGraphicsScene *scene;
};

#endif // PAINT2DFORM_H
