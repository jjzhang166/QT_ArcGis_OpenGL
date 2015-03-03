#include <QApplication>
#include "helper/myhelper.h"
#include "initform.h"

#include <windows.h>
#include "mainform.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    myHelper::SetUTF8Code();
    myHelper::SetStyle("black");//黑色风格
//    myHelper::SetStyle("blue");//蓝色风格
//    myHelper::SetStyle("gray");//灰色风格
//    myHelper::SetStyle("navy");//天蓝色风格
    myHelper::SetChinese();

//    initForm init;
//    init.show();


    mainForm uimain;
    uimain.show();
    return a.exec();
}
