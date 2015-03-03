#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H
#include <QtGui>
#include <QtOpenGL>
#include <QTimerEvent>
#include <QPushButton>

class Myglwidget : public QGLWidget
{
    Q_OBJECT

public:
     Myglwidget(QWidget *parent = 0);
    ~Myglwidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void keyPressEvent(QKeyEvent *e);
    bool fullscreen;

    void makeList();
   // void timerEvent(QTimerEvent *e);
    void loadGLTextures();

public slots:

    void rotate_clicked();
private:

    GLfloat Point[5][3];

    static  short n;
    static  GLfloat PI;

    GLfloat rTri;
    GLfloat rQuad;
    GLuint list;

    GLuint texture[6];

    QPushButton *button_rotate;

};



#endif // MYGLWIDGET_H
