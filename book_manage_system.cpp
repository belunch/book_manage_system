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
    



    //�����ݲ�����
    // 
    // 
	connect(this, &book_manage_system::enter_user_menu, Data,&data_process::leavedays);
        //����login����window��
    connect(Login_window, &Login::user_Login_sig, Data, &data_process::Sign_in);
    connect(Login_window, &Login::manager_Login_sig, Data, &data_process::admin_Sign_in);
        //����user_main_window��
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
	//����manager��
	connect(Manager_main_menu, &manager::data_backup, Data, &data_process::data_backup);
	connect(Manager_main_menu, &manager::data_recovery, Data, &data_process::data_recovery);
	connect(Manager_main_menu, &manager::serch_by_name_sig, Data, &data_process::serch_by_key);
	connect(Manager_main_menu, &manager::serch_by_cata_sig, Data, &data_process::serch_by_cata);
	connect(Manager_main_menu, &manager::change_password_sig, Data, &data_process::admin_change_password);
    connect(Manager_main_menu, &manager::enter_usermessage, Data, &data_process::view_readers);
    connect(Manager_main_menu, &manager::enter_feed_back, Data, &data_process::examine_feedback);
	connect(Manager_main_menu, &manager::enter_book, Data, &data_process::view_bookmessages);

	//����register��
	connect(Register_menu, &register_win::push_register, Data, &data_process::Sign_up);
	connect(Register_menu, &register_win::push_manager_register, Data, &data_process::Admin_Sign_up);
    
    //����book_manage��
	connect(Manager_main_menu->book_manage_window, &book_manage_win::add_book, Data, &data_process::add_book);
	connect(Manager_main_menu->book_manage_window, &book_manage_win::change_book, Data, &data_process::change_book);
	connect(Manager_main_menu->book_manage_window, &book_manage_win::delete_book, Data, &data_process::delete_book);


    //�����ݲ����ӵ�
    connect(Data, &data_process::return_history, User_main_menu, &user_menu::printn_history_message);
    connect(Data, &data_process::return_user_message, Manager_main_menu, &manager::pring_reader);
    connect(Data, &data_process::return_feedback, Manager_main_menu, &manager::print_feedback);
    connect(Data, &data_process::return_fine, User_main_menu, &user_menu::print_fine);
    connect(Data, &data_process::return_back, User_main_menu, &user_menu::print_leavedays);
}

book_manage_system::~book_manage_system()
{}

void book_manage_system::manager_login()//����Ա��¼�ɹ�
{
    Login_window->hide();
    Manager_main_menu->show();

    disconnect(Data, &data_process::return_back, NULL, NULL);
    disconnect(Data, &data_process::return_bookmessage, NULL, NULL);

    connect(Data, &data_process::return_back, Manager_main_menu,&manager::return_back);
    connect(Data, &data_process::return_bookmessage, Manager_main_menu,&manager::print_book);
}

void book_manage_system::login_success()//��ͨ�û���¼�ɹ�
{
    Login_window->hide();
    
    User_main_menu->show();

    disconnect(Data, &data_process::return_back, NULL, NULL);
    disconnect(Data, &data_process::return_bookmessage, NULL, NULL);

    connect(Data, &data_process::return_back, User_main_menu, &user_menu::print_message);
    connect(Data, &data_process::return_bookmessage, User_main_menu, &user_menu::print_book_message);

	emit enter_user_menu(); // �����źţ�֪ͨ�����û�������
}

void book_manage_system::register_window()//ע�����
{
    Login_window->hide();

    Register_menu->show();

    disconnect(Data, &data_process::return_back, NULL, NULL);
    disconnect(Data, &data_process::return_bookmessage, NULL, NULL);

    connect(Data, &data_process::return_back, Register_menu, &register_win::print_message);
}

void book_manage_system::log_out()//�ȳ������ص�¼����
{
	Manager_main_menu->hide();
    User_main_menu->hide();
    Register_menu->hide();
    Login_window->show();

    //disconnect(Data, &data_process::return_history, NULL, NULL);
    disconnect(Data, &data_process::return_back, NULL, NULL);
    disconnect(Data, &data_process::return_bookmessage, NULL, NULL);
    //return_leavesֻ������Ԥ���ǿ��ã����öϿ����ӣ���û����
    //return_history����ֻ���û��鿴��ʷ�Ǹ��ط���
    //return_usermessageֻ�ڹ���Ա���ĵط��ã����öϿ���
    //return_feedbackֻ�й���Ա�ã�
    //return_fineֻ�ڷ��ط�������ĵط���,�����û����->�����;

    connect(Data, &data_process::return_back, Login_window, &Login::return_back);

	Login_window->clear_all();//��յ�¼����
}