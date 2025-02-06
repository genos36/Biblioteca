#include "Interfaccia/BibliotecaMainWindow.h"
#include <QApplication>
int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    BibliotecaMainWindow provaMainWindow;
    provaMainWindow.show();

    return app.exec();


}