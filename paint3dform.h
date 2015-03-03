#ifndef PAINT3DFORM_H
#define PAINT3DFORM_H

#include <QWidget>
#include "opengl/glwidhet.h"
namespace Ui {
class paint3dForm;
}

class paint3dForm : public QWidget
{
    Q_OBJECT

public:
    explicit paint3dForm(QWidget *parent = 0);
    ~paint3dForm();

private:
    Ui::paint3dForm *ui;
    Myglwidget *uMyglwidget;
};

#endif // PAINT3DFORM_H
