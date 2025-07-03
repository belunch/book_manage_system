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
    log_out();
    connect(Login_window, &Login::Login_success, this, &book_manage_system::login_success);
    connect(User_main_menu, &user_menu::Logout, this, &book_manage_system::log_out);
    connect(Manager_main_menu, &manager::log_out, this, &book_manage_system::log_out);
    connect(Register_menu, &register_win::quit, this, &book_manage_system::log_out);
    connect(Login_window, &Login::manager_Login_success, this, &book_manage_system::manager_login);
    connect(Login_window, &Login::push_register, this, &book_manage_system::register_window);
    



    //与数据层连接
    // 
    // 
	connect(this, &book_manage_system::enter_user_menu, Data,&data_process::leavedays);
        //来自login——window的
    connect(Login_window, &Login::user_Login_sig, Data, &data_process::Sign_in);
    connect(Login_window, &Login::manager_Login_sig, Data, &data_process::admin_Sign_in);
        //来自user_main_window的
    connect(User_main_menu, &user_menu::borrow_book, Data, &data_process::borrow_book);
    connect(User_main_menu, &user_menu::return_book, Data, &data_process::return_book);
    connect(User_main_menu, &user_menu::serch_by_name, Data, &data_process::serch_by_key);
    connect(User_main_menu, &user_menu::serch_by_cata, Data, &data_process::serch_by_cata);
    connect(User_main_menu, &user_menu::serch_history, Data, &data_process::view_user_history);
	connect(User_main_menu, &user_menu::reset_password, Data, &data_process::change_password);
	connect(User_main_menu, &user_menu::commit_feedback, Data, &data_process::submit_feedback);
	connect(User_main_menu, &user_menu::serch_fine, Data, &data_process::continue_pay_fine);
	connect(User_main_menu, &user_menu::pay_fine, Data, &data_process::pay_fine);
    connect(User_main_menu, &user_menu::enter_serch, Data, &data_process::view_bookmessages);
	connect(User_main_menu, &user_menu::enter_fine, Data, &data_process::continue_pay_fine);
	//来自manager的
	connect(Manager_main_menu, &manager::data_backup, Data, &data_process::data_backup);
	connect(Manager_main_menu, &manager::data_recovery, Data, &data_process::data_recovery);
	connect(Manager_main_menu, &manager::serch_by_name_sig, Data, &data_process::serch_by_key);
	connect(Manager_main_menu, &manager::serch_by_cata_sig, Data, &data_process::serch_by_cata);
	connect(Manager_main_menu, &manager::change_password_sig, Data, &data_process::admin_change_password);
    connect(Manager_main_menu, &manager::enter_usermessage, Data, &data_process::view_readers);
    connect(Manager_main_menu, &manager::enter_feed_back, Data, &data_process::examine_feedback);
	connect(Manager_main_menu, &manager::enter_book, Data, &data_process::view_bookmessages);

	//来自register的
	connect(Register_menu, &register_win::push_register, Data, &data_process::Sign_up);
	connect(Register_menu, &register_win::push_manager_register, Data, &data_process::Admin_Sign_up);
    
    //来自book_manage的
	connect(Manager_main_menu->book_manage_window, &book_manage_win::add_book, Data, &data_process::add_book);
	connect(Manager_main_menu->book_manage_window, &book_manage_win::change_book, Data, &data_process::change_book);
	connect(Manager_main_menu->book_manage_window, &book_manage_win::delete_book, Data, &data_process::delete_book);


    //与数据层连接的
    connect(Data, &data_process::return_history, User_main_menu, &user_menu::printn_history_message);
    connect(Data, &data_process::return_user_message, Manager_main_menu, &manager::pring_reader);
    connect(Data, &data_process::return_feedback, Manager_main_menu, &manager::print_feedback);
    connect(Data, &data_process::return_fine, User_main_menu, &user_menu::print_fine);
    connect(Data, &data_process::return_back, User_main_menu, &user_menu::print_leavedays);
}

book_manage_system::~book_manage_system()
{}

void book_manage_system::manager_login()//管理员登录成功
{
    Login_window->hide();
    Manager_main_menu->show();

    disconnect(Data, &data_process::return_back, NULL, NULL);
    disconnect(Data, &data_process::return_bookmessage, NULL, NULL);

    connect(Data, &data_process::return_back, Manager_main_menu,&manager::return_back);
    connect(Data, &data_process::return_bookmessage, Manager_main_menu,&manager::print_book);
}

void book_manage_system::login_success()//普通用户登录成功
{
    Login_window->hide();
    
    User_main_menu->show();

    disconnect(Data, &data_process::return_back, NULL, NULL);
    disconnect(Data, &data_process::return_bookmessage, NULL, NULL);

    connect(Data, &data_process::return_back, User_main_menu, &user_menu::print_message);
    connect(Data, &data_process::return_bookmessage, User_main_menu, &user_menu::print_book_message);

	emit enter_user_menu(); // 发送信号，通知进入用户主界面
}

void book_manage_system::register_window()//注册界面
{
    Login_window->hide();

    Register_menu->show();

    disconnect(Data, &data_process::return_back, NULL, NULL);
    disconnect(Data, &data_process::return_bookmessage, NULL, NULL);

    connect(Data, &data_process::return_back, Register_menu, &register_win::print_message);
}

void book_manage_system::log_out()//等出，返回登录界面
{
	Manager_main_menu->hide();
    User_main_menu->hide();
    Register_menu->hide();
    Login_window->show();

    //disconnect(Data, &data_process::return_history, NULL, NULL);
    disconnect(Data, &data_process::return_back, NULL, NULL);
    disconnect(Data, &data_process::return_bookmessage, NULL, NULL);
    //return_leaves只在提醒预期那块用，不用断开连接；还没做；
    //return_history好像只在用户查看历史那个地方看
    //return_usermessage只在管理员看的地方用，不用断开；
    //return_feedback只有管理员用；
    //return_fine只在返回罚款数额的地方用,这个还没做；->已完成;

    connect(Data, &data_process::return_back, Login_window, &Login::return_back);

	Login_window->clear_all();//清空登录界面
}