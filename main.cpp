#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("Food Service App");
    // w.resize(700,700);
    w.show();
    return a.exec();
}
