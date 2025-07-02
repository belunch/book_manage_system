#include"book_manage.h"

book_manage_win::book_manage_win(QWidget* parent )
	:QWidget(parent)
{
	ui.setupUi(this);

}

void book_manage_win::set_page(int i)
{
	ui.stackedWidget->setCurrentIndex(i);
}

void book_manage_win::pushu_quit()
{

}
void book_manage_win::push_confer()
{

}