#include "Login.h"

Login::Login(QWidget* parent)
    : QWidget(parent)
{
    is_admin = false;
    ui.setupUi(this);
    connect(ui.register_button, &QPushButton::clicked, this, &Login::push_register);
    connect(ui.pushButton_login, &QPushButton::clicked, this, &Login::push_Login);
    connect(ui.pushButton_quit, &QPushButton::clicked, this, &Login::push_quit);
}

Login::~Login()
{
}

void Login::push_Login()//这个肯定得改，这逻辑包不对的
{
    QString account = ui.line_username->text();
    QString password = ui.lineEdit_password->text();
    string std_accout = account.toUtf8().constData();
    string std_password = password.toUtf8().constData();


    //往后端传，根据返回值继续
    if (ui.manager_check->isChecked())
    {
        is_admin = true;
        emit manager_Login_sig(std_accout,std_password);
        emit manager_Login_success();
    }
    else
    {
        is_admin = false;
        emit user_Login_sig(std_accout, std_password);
        emit Login_success();
    }
}

void Login::push_quit()
{
    exit(0);
}

void Login::return_back(bool success, string message)
{
    if (success)
    {
        if (is_admin)
        {
            emit Login_success();
        }
        else
        {
            emit manager_Login_success();
        }
    }
    else
    {
        QMessageBox::information(nullptr, QString::fromUtf8("提示"), QString::fromUtf8(message));
    }


}
