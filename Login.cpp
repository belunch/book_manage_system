#include "Login.h"

Login::Login(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton_login, &QPushButton::clicked, this, &Login::push_Login);
    connect(ui.pushButton_quit, &QPushButton::clicked, this, &Login::push_quit);
}

Login::~Login()
{
}

void Login::push_Login()
{
    //����˴������ݷ���ֵ����


    emit Login_success();
}

void Login::push_quit()
{
    exit(0);
}