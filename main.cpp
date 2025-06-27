#include "book_manage_system.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    book_manage_system window;
    //window.show();
    return app.exec();
}
