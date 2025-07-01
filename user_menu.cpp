#include"usermenu.h"

user_menu::user_menu(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.button_borrow, &QPushButton::clicked, this, &user_menu::push_borrow);//进入借书界面
	connect(ui.button_return, &QPushButton::clicked, this, &user_menu::push_return);//进入还书界面
	connect(ui.button_serch, &QPushButton::clicked, this, &user_menu::push_serch);//进入查询界面
	connect(ui.button_history, &QPushButton::clicked, this, &user_menu::push_history);//进入历史界面
	connect(ui.button_signout, &QPushButton::clicked, this, &user_menu::push_quit);//登出
	connect(ui.button_reset_password, &QPushButton::clicked, this, &user_menu::push_reset);//进入重置密码界面
	connect(ui.button_feedback, &QPushButton::clicked, this, &user_menu::push_feed_back);//进入反馈提交界面
	connect(ui.borrow_quit_button, &QPushButton::clicked, this, &user_menu::return_user_menu);//借书界面的返回按钮
	connect(ui.return_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//还书界面的返回按钮
	connect(ui.feedback_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//反馈界面的返回按钮
	connect(ui.serch_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//查找界面的返回按钮
	connect(ui.history_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//历史界面的返回按钮
	connect(ui.reset_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//重置密码的返回按钮

	connect(ui.borrow_borrow_button, &QPushButton::clicked, this, &user_menu::borrow_borrow_button);//连接借书界面的借书按钮和函数
	connect(ui.return_return_button, &QPushButton::clicked, this, &user_menu::return_return_button);//连接还书界面的按钮与函数
	connect(ui.serch_by_name, &QPushButton::clicked, this, &user_menu::serch_serch_by_name);//连接按书名查找按钮与函数
	connect(ui.serch_by_cata, &QPushButton::clicked, this, &user_menu::serch_serch_by_cata);
	connect(ui.history_serch, &QPushButton::clicked, this, &user_menu::history_serch_history);
	connect(ui.reset_reset, &QPushButton::clicked, this, &user_menu::reset_reset_password);
	connect(ui.feedback_feedback, &QPushButton::clicked, this, &user_menu::commit_commit_feedback);

	ui.stackedWidget->setCurrentIndex(0);
}

user_menu::~user_menu()
{}

//*********************************************************************
//以下的是切换页面按钮，不用向下面发信号；
//*********************************************************************



void user_menu::push_borrow()
{
	ui.stackedWidget->setCurrentIndex(1);
}
void user_menu::push_return()
{
	ui.stackedWidget->setCurrentIndex(2);
}
void user_menu::push_serch()
{
	ui.stackedWidget->setCurrentIndex(3);
}

void user_menu::push_history()
{
	ui.stackedWidget->setCurrentIndex(4);
}

void user_menu::push_quit()
{
	//ui.welcom_line->setText("quit");
	emit Logout();
	return_user_menu();
}

void user_menu::push_feed_back()
{
	ui.stackedWidget->setCurrentIndex(6);
}

void user_menu::push_reset()
{
	ui.stackedWidget->setCurrentIndex(5);
}

void user_menu::return_user_menu()
{
	ui.stackedWidget->setCurrentIndex(0);
}





//*********************************************************************
//以下是与按键连接的函数
//*********************************************************************


void user_menu::borrow_borrow_button()
{
	QString book_ID = ui.borrow_line_edit->text();
	std::string std_ID = book_ID.toStdString();
	emit borrow_book(std_ID);
}

void user_menu::return_return_button()
{
	QString book_ID = ui.return_line_edit->text();
	std::string std_ID = book_ID.toStdString();
	emit return_book(std_ID);
}

void user_menu::serch_serch_by_name()
{
	QString book_name_key = ui.serch_by_name->text();
	std::string std_name_key = book_name_key.toStdString();
	emit serch_by_name(std_name_key);
}

void user_menu::serch_serch_by_cata()
{
	QString book_cata = ui.serch_by_cata->text();
	std::string std_cata = book_cata.toStdString();
	emit serch_by_name(std_cata);
}

void user_menu::history_serch_history()
{
	emit serch_history();
}

void user_menu::reset_reset_password()
{
	QString old_pass, new_pass, re_new_pass;
	old_pass = ui.reset_oldpass->text();
	new_pass = ui.reset_newpass->text();
	re_new_pass = ui.reset_config_newpass->text();
	if (new_pass != re_new_pass)
	{
		//返回一个报错信号
	}
	else
	{
		std::string std_new_pass = new_pass.toStdString();
		std::string std_old_pass = old_pass.toStdString();

		emit reset_password(std_old_pass,std_new_pass);
	}
}

void user_menu::commit_commit_feedback()
{
	QString feedback = ui.textEdit->toPlainText();
	std::string std_feedback = feedback.toStdString();
	emit commit_feedback(std_feedback);
}








//*********************************************************************
//
//*********************************************************************