#include "mainpaintwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainPaintWindow w;
    w.show();
    return a.exec();
}
