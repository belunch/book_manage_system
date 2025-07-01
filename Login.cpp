#include "Login.h"

Login::Login(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.register_button, &QPushButton::clicked, this, &Login::push_register);
    connect(ui.pushButton_login, &QPushButton::clicked, this, &Login::push_Login);
    connect(ui.pushButton_quit, &QPushButton::clicked, this, &Login::push_quit);
}

Login::~Login()
{
}

void Login::push_Login()//����϶��øģ����߼������Ե�
{
    //����˴������ݷ���ֵ����
    if (ui.manager_check->isChecked())
    {
        emit manager_Login_success();
    }
    else
    {
        emit Login_success();
    }
}

void Login::push_quit()
{
    exit(0);
}