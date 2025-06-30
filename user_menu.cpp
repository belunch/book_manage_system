#include"usermenu.h"

user_menu::user_menu(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.button_borrow, &QPushButton::clicked, this, &user_menu::push_borrow);
	connect(ui.button_return, &QPushButton::clicked, this, &user_menu::push_return);
	connect(ui.button_serch, &QPushButton::clicked, this, &user_menu::push_serch);
	connect(ui.button_history, &QPushButton::clicked, this, &user_menu::push_history);
	connect(ui.button_signout, &QPushButton::clicked, this, &user_menu::push_quit);
	connect(ui.button_reset_password, &QPushButton::clicked, this, &user_menu::push_reset);
	connect(ui.button_feedback, &QPushButton::clicked, this, &user_menu::push_feed_back);
	connect(ui.borrow_quit_button, &QPushButton::clicked, this, &user_menu::return_user_menu);
	connect(ui.return_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);
	connect(ui.feedback_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);
	connect(ui.serch_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);
	connect(ui.history_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);
	connect(ui.reset_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);
	ui.stackedWidget->setCurrentIndex(0);
}

user_menu::~user_menu()
{}

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