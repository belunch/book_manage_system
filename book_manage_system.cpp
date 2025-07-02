#include "book_manage_system.h"

book_manage_system::book_manage_system(data_process* data,QWidget *parent)
    : QWidget(parent)
{
    Data = data;
    ui.setupUi(this);
    Login_window = new Login();
    User_main_menu = new user_menu();
    Manager_main_menu = new manager();
    Register_menu = new register_win();
    Login_window->show();
    connect(Login_window, &Login::Login_success, this, &book_manage_system::login_success);
    connect(User_main_menu, &user_menu::Logout, this, &book_manage_system::log_out);
    connect(Manager_main_menu, &manager::log_out, this, &book_manage_system::log_out);
    connect(Register_menu, &register_win::quit, this, &book_manage_system::log_out);
    connect(Login_window, &Login::manager_Login_success, this, &book_manage_system::manager_login);
    connect(Login_window, &Login::push_register, this, &book_manage_system::register_window);

    //�����ݲ�����
        //����login����window��
    connect(Login_window, &Login::user_Login_sig, Data, &data_process::Sign_in);
    /*connect(Login_window,&Login::manager_Login_sig,Data,&ata_process::)*/
    //md,�����ˣ�
        //����user_main_window��
    connect(User_main_menu, &user_menu::borrow_book, Data, &data_process::borrow_book);
    connect(User_main_menu, &user_menu::return_book, Data, &data_process::return_book);
    connect(User_main_menu, &user_menu::serch_by_name, Data, &data_process::serch_by_key);
    connect(User_main_menu, &user_menu::serch_by_cata, Data, &data_process::serch_by_cata);
    /*connect(User_main_menu, &user_menu::serch_history, Data, &data_process::serch_by_key);*/
    //md��©��
	connect(User_main_menu, &user_menu::reset_password, Data, &data_process::change_password);
	connect(User_main_menu, &user_menu::commit_feedback, Data, &data_process::submit_feedback);
	/*connect(User_main_menu, &user_menu::serch_fine, Data, &data_process::serch_fine);*///©��
	connect(User_main_menu, &user_menu::pay_fine, Data, &data_process::pay_fine);
	//����manager��
	connect(Manager_main_menu, &manager::data_backup, Data, &data_process::data_backup);
	connect(Manager_main_menu, &manager::data_recovery, Data, &data_process::data_recovery);
	connect(Manager_main_menu, &manager::serch_by_name_sig, Data, &data_process::serch_by_key);
	connect(Manager_main_menu, &manager::serch_by_cata_sig, Data, &data_process::serch_by_cata);
	connect(Manager_main_menu, &manager::change_password_sig, Data, &data_process::change_password);

	//����register��
	connect(Register_menu, &register_win::push_register, Data, &data_process::Sign_up);
	/*connect(Register_menu, &register_win::push_manager_register, Data, &data_process::Sign_up);*///������©һ��
    
    //����book_manage��
	connect(Manager_main_menu->book_manage_window, &book_manage_win::add_book, Data, &data_process::add_book);
	connect(Manager_main_menu->book_manage_window, &book_manage_win::change_book, Data, &data_process::change_book);
	connect(Manager_main_menu->book_manage_window, &book_manage_win::delete_book, Data, &data_process::delete_book);

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

void book_manage_system::register_window()
{
    Login_window->hide();

    Register_menu->show();


}

void book_manage_system::log_out()
{
	Manager_main_menu->hide();
    User_main_menu->hide();
    Register_menu->hide();
    Login_window->show();
}