#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.setWindowTitle("C+ compiler IDE");
    mainWindow.resize(1600, 1080);
    mainWindow.show();
    return app.exec();
}
