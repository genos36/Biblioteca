#include <QApplication>
#include "BibliotecaMainWindow.h"



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    BibliotecaMainWindow prova;
    prova.show();    

    return app.exec();
}


//RESOURCES += resources.qrc