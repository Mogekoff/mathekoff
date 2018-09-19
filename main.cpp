#include "startupwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartupWindow sw;
    sw.show();
    return a.exec();
}
