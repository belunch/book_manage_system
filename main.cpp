#include "book_manage_system.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    backword* BackWord = new backword;//������˶���
    data_process* Data_Process = new data_process(BackWord);//�����м��߼�����㣬�����Ӻ��
    book_manage_system window(Data_Process);//����ǰ�˶��󣬲������м�㡣
    //window.show();
    return app.exec();
}
