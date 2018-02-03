#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


///TODO add line in axes
///TODO add FolderView in DialogWindow
///TODO add "about"
