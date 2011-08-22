#include <QtGui/QApplication>
#include "gomokuwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GomokuWindow w;
    w.show();
    return a.exec();
}
