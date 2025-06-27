#include "book_manage_system.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    backword* BackWord = new backword;
    data_process* Data_Process = new data_process(BackWord);
    book_manage_system window(Data_Process);
    //window.show();
    return app.exec();
}
