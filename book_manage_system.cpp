#include "book_manage_system.h"

book_manage_system::book_manage_system(data_process* data,QWidget *parent)
    : QWidget(parent)
{
    Data = data;
    ui.setupUi(this);
    Login_window = new Login();
    User_main_menu = new user_menu();
    Manager_main_menu = new manager();
    Login_window->show();
    connect(Login_window, &Login::Login_success, this, &book_manage_system::login_success);
    connect(User_main_menu, &user_menu::Logout, this, &book_manage_system::log_out);
    connect(Manager_main_menu, &manager::log_out, this, &book_manage_system::log_out);
    connect(Login_window, &Login::manager_Login_success, this, &book_manage_system::manager_login);
}

book_manage_system::~book_manage_system()
{}

void book_manage_system::manager_login()
{
    Login_window->hide();
    Manager_main_menu->show();
}

void book_manage_system::login_success()
{
    Login_window->hide();
    
    User_main_menu->show();
}

void book_manage_system::log_out()
{
	Manager_main_menu->hide();
    User_main_menu->hide();
    Login_window->show();
}