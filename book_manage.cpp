#include"book_manage.h"

book_manage_win::book_manage_win(QWidget* parent )
	:QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.button_quit, &QPushButton::clicked, this, &book_manage_win::pushu_quit);
	connect(ui.button_confer, &QPushButton::clicked, this, &book_manage_win::push_confer);
}

void book_manage_win::set_page(int i)
{
	ui.stackedWidget->setCurrentIndex(i);
}



void book_manage_win::pushu_quit()
{
	this->hide();
}
void book_manage_win::push_confer()
{
	int page = ui.stackedWidget->currentIndex();
	QString book_name, author, ISBN, book_id, cata;
	string std_book_name, std_author, std_ISBN, std_book_id, std_cata;
	switch (page)
	{
	case 1://���
		book_name = ui.add_bookname->text();
		author = ui.add_author->text();
		ISBN = ui.add_ISBN->text();
		book_id = ui.add_bookid->text();
		cata = ui.add_cata->text();

		std_book_name = book_name.toStdString();
		std_author = author.toStdString();
		std_ISBN = ISBN.toStdString();
		std_book_id = book_id.toStdString();
		std_cata = cata.toStdString();

		emit add_book(std_book_name, std_author, std_cata, std_ISBN, std_book_id);

		break;

	case 2://�޸�
		book_name = ui.change_bookname->text();
		author = ui.change_author->text();
		ISBN = ui.change_isbn->text();
		book_id = ui.change_bookid->text();
		cata = ui.change_cata->text();

		std_book_name = book_name.toStdString();
		std_author = author.toStdString();
		std_ISBN = ISBN.toStdString();
		std_book_id = book_id.toStdString();
		std_cata = cata.toStdString();

		emit add_book(std_book_name, std_author, std_cata, std_ISBN, std_book_id);

		break;
	case 3://ɾ��
		book_id = ui.delete_bookid->text();
		std_book_id = book_id.toStdString();
		emit delete_book(std_book_id);

	default:
		break;
	}
}

