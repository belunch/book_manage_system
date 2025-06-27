#include "book_manage_system.h"

book_manage_system::book_manage_system(data_process* data,QWidget *parent)
    : QWidget(parent)
{
    Data = data;
    ui.setupUi(this);
    Login_window = new Login();
    Login_window->show();
    connect(Login_window, &Login::Login_success, this, &book_manage_system::login_success);
}

book_manage_system::~book_manage_system()
{}

void book_manage_system::login_success()
{
    this->show();
    Login_window->hide();
    User_main_menu = new user_menu(this);
    User_main_menu->show();
}