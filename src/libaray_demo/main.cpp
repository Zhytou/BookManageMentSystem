#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createConnection()) {
        std::cout << "database open failed" << std::endl;
        return 0;
    }
    MainWindow w;
    w.show();
    return a.exec();
}
