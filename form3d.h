#ifndef FORM3D_H
#define FORM3D_H

#include <QWidget>
#include "opengl/glwidhet.h"
namespace Ui {
class Form3D;
}

class Form3D : public QWidget
{
    Q_OBJECT

public:
    explicit Form3D(QWidget *parent = 0);
    ~Form3D();

private:
    Ui::Form3D *ui;
    Myglwidget *uMyglwidget;
};

#endif // FORM3D_H
