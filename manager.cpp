#include"manager.h"

manager::manager(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.book_manage, &QPushButton::clicked, this, &manager::book);
	connect(ui.reader_manage, &QPushButton::clicked, this, &manager::reader);
	connect(ui.data_manage, &QPushButton::clicked, this, &manager::data);
	connect(ui.the_feedback, &QPushButton::clicked, this, &manager::feed_back);
	connect(ui.change_password, &QPushButton::clicked, this, &manager::change_password);
	connect(ui.book_quit, &QPushButton::clicked, this, &manager::back_menu);
	connect(ui.reader_quit, &QPushButton::clicked, this, &manager::back_menu);
	connect(ui.data_quit, &QPushButton::clicked, this, &manager::back_menu);
	connect(ui.feedback_quit, &QPushButton::clicked, this, &manager::back_menu);
	connect(ui.change_quit, &QPushButton::clicked, this, &manager::back_menu);
	connect(ui.quit_button, &QPushButton::clicked, this, &manager::quit);
	ui.stackedWidget->setCurrentIndex(0);
}
manager::~manager()
{

}

void manager::quit()
{
	emit log_out();
}

void manager::book()
{
	ui.stackedWidget->setCurrentIndex(1);
}
void manager::reader()
{
	ui.stackedWidget->setCurrentIndex(2);
}

void manager::data()
{
	ui.stackedWidget->setCurrentIndex(3);
}

void manager::feed_back()
{
	ui.stackedWidget->setCurrentIndex(4);
}
void manager::change_password()
{
	ui.stackedWidget->setCurrentIndex(5);
}
void manager::back_menu()
{
	ui.stackedWidget->setCurrentIndex(0);
}