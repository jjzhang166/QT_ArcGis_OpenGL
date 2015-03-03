
#include "opengl/glwidhet.h"

#include <QtGui>
#include <QtCore>
#include <QtOpenGL>
#include <math.h>

#include <QTimer>

#include<gl/glu.h>
short Myglwidget::n=200;
GLfloat Myglwidget::PI = 3.1415926536f;

Myglwidget::Myglwidget(QWidget *parent) :
        QGLWidget(parent)

{


    QTimer *timer = new QTimer(this);

    //button_rotate = new QPushButton(tr("rotate"),this);

    fullscreen = false;
    short angle = 18;
    for(short i=0;i<5;i++){
        Point[i][0]=cos(angle * PI/180);
        Point[i][1]=sin(angle * PI/180);
        Point[i][2]=0.0;
        angle+=72;

    }

    //connect(button_rotate,SIGNAL(clicked()),this,SLOT(rotate_clicked()));
    connect(timer,SIGNAL(timeout()),this,SLOT(rotate_clicked()));
    timer->start(10);
}

//这是对虚函数，这里是重写该函数
void Myglwidget::initializeGL()
{
    //setGeometry(100, 100, 640, 480);//设置窗口初始位置和大小
    //glShadeModel(GL_FLAT);//设置阴影平滑模式
    glShadeModel(GL_SMOOTH);

    glClearColor(0, 0, 0, 0);//改变窗口的背景颜色，不过我这里貌似设置后并没有什么效果
    glClearDepth(1.0);//设置深度缓存
    glEnable(GL_DEPTH_TEST);//允许深度测试
    glDepthFunc(GL_LEQUAL);//设置深度测试类型
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//进行透视校正

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,Point);


}

void Myglwidget::paintGL()
{


    makeList();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //glClear()函数在这里就是对initializeGL()函数中设置的颜色和缓存深度等起作用


    /*三角形*/
        glTranslatef(1.0,0.0,-6.0);
        glBegin(GL_TRIANGLES);
        glColor3f(0.0,0.0,1.0);//蓝
        glVertex3f(0.0,1.0,0.0);
        glColor3f(1.0,0.0,0.0);//红
        glVertex3f(-1.0,-1.0,0.0);
        glColor3f(0.0,1.0,0.0);//绿
        glVertex3f(1.0,-1.0,0.0);
        glEnd();

        /*五角星*/
        glLoadIdentity();
        glTranslatef(2.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
                glArrayElement(1);
                glArrayElement(4);
                glArrayElement(2);
                glArrayElement(0);
                glArrayElement(3);
        glEnd();

        /*圆形*/
        glLoadIdentity();
        glTranslatef(3.0,0.0,0.0);
        glBegin(GL_POLYGON);
            GLfloat part;
            for(short i=0;i<n;i++){
                part = 1.0/n*i;
                glColor3f(1.0,part,part);
                glVertex3f(1*cos(2*PI*part),1*sin(2*PI*part),0.0);
            }
        glEnd();

    glLoadIdentity();//重置当前的模型观察矩阵？不是很理解！
    glTranslatef(-1.5,0.0,-6.0);
    glRotatef(rTri,0.0,1.0,0.0);
    glCallList(list);

    glLoadIdentity();//
    glTranslatef(1.5,0.0,-7.0);
    glRotatef(rQuad,1.0,1.0,1.0);
    glCallList(list+1);


}

//该程序是设置opengl场景透视图，程序中至少被执行一次(程序启动时).
void Myglwidget::resizeGL(int width, int height)
{
    if(0 == height)
        height = 1;//防止一条边为0
    glViewport(0, 0, (GLint)width, (GLint)height);//重置当前视口，本身不是重置窗口的，只不过是这里被Qt给封装好了
    glMatrixMode(GL_PROJECTION);//选择投影矩阵
    glLoadIdentity();//重置选择好的投影矩阵
    gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);//建立透视投影矩阵
    glMatrixMode(GL_MODELVIEW);//以下2句和上面出现的解释一样
    glLoadIdentity();




}
void Myglwidget::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
        //F1键为全屏和普通屏显示切换键
        case Qt::Key_F1:
            fullscreen = !fullscreen;
            if(fullscreen)
                showFullScreen();
            else
            {
                setGeometry(300, 150, 640, 480);
                showNormal();
            }
            updateGL();
            break;
        //Ese为退出程序键
        case Qt::Key_Escape:
            close();
    }
}

Myglwidget::~Myglwidget()
{
   //
}


void Myglwidget::makeList(){

        list = glGenLists(2);
        glNewList(list,GL_COMPILE);
        glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0,1.0,0.0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(-1.0,-1.0,1.0);
        glColor3f(1.0,0.0,1.0);
        glVertex3f(1.0,-1.0,1.0);

        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0,1.0,0.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(1.0,-1.0,-1.0);

        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0,1.0,0.0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(1.0,-1.0,-1.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-1.0,-1.0,-1.0);

        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0,1.0,0.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(-1.0,-1.0,1.0);

        glEnd();
        glEndList();


    glNewList(list + 1,GL_COMPILE);
        glBegin(GL_QUADS);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(1.0,1.0,-1.0);
        glVertex3f(-1.0,1.0,-1.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(1.0,1.0,1.0);


        glColor3f(1.0,0.5,0.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(1.0,-1.0,-1.0);


        glColor3f(1.0,0.0,0.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);


        glColor3f(1.0,1.0,0.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,1.0,-1.0);
        glVertex3f(1.0,1.0,-1.0);


        glColor3f(0.0,0.0,1.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(-1.0,1.0,-1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,-1.0,1.0);


        glColor3f(1.0,0.0,1.0);
        glVertex3f(1.0,1.0,-1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,-1.0);

        glEnd();
        glEndList();

}
//下载纹理
void Myglwidget::loadGLTextures(){

    QImage tex, buffer;

    QString fileNmae("：texture%1.bmp");

    glGenTextures(6, &texture[0]);//开辟3个纹理内存，索引指向texture[0]

    for(short i=0;i<6;i++){

        buffer.load(fileNmae.arg(i+1));

        tex = QGLWidget::convertToGLFormat( buffer );

        glBindTexture(GL_TEXTURE_2D, texture[i]);//将创建的纹理内存指向的内容绑定到纹理对象GL_TEXTURE_2D上，经过这句代码后，以后对GL_TEXTURE_2D的操作的任何操作都同时对应与它所绑定的纹理对象

        glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());//开始真正创建纹理数据

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//当所显示的纹理比加载进来的纹理小时，采用GL_NEAREST的方法来处理 GL_NEAREST方式速度非常快，因为它不是真正的滤波，所以占用内存非常小，速度就快了

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//当所显示的纹理比加载进来的纹理大时，采用GL_NEAREST的方法来处理

    }
}

void Myglwidget::rotate_clicked(){
 //qDebug()<<"test"<<endl;
    rTri+=1;
    rQuad+=1;
    update();
}
