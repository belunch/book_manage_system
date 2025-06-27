#include "book_manage_system.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    backword* BackWord = new backword;//创建后端对象
    data_process* Data_Process = new data_process(BackWord);//创建中间逻辑处理层，并连接后端
    book_manage_system window(Data_Process);//创建前端对象，并连接中间层。
    //window.show();
    return app.exec();
}
