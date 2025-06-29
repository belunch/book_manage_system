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
	ui.welcom_line->setText("return");
}
void user_menu::push_serch()
{
	ui.welcom_line->setText("serch");
}

void user_menu::push_history()
{
	ui.welcom_line->setText("history");
}

void user_menu::push_quit()
{
	//ui.welcom_line->setText("quit");
	emit Logout();
	return_user_menu();
}

void user_menu::push_feed_back()
{
	ui.welcom_line->setText("feedback");
}

void user_menu::push_reset()
{
	ui.welcom_line->setText("reset");
}

void user_menu::return_user_menu()
{
	ui.stackedWidget->setCurrentIndex(0);
}