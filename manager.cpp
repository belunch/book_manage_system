#include"manager.h"

manager::manager(QWidget* parent)
	: QWidget(parent)
{
	book_manage_window = new book_manage_win();
	ui.setupUi(this);
	//ҳ���л�
	connect(ui.book_manage, &QPushButton::clicked, this, &manager::book_page);
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

	connect(book_manage_window, &book_manage_win::quit, this, &manager::back_book_main_menu);
	//�����ݲ㴫
	connect(ui.change_change, &QPushButton::clicked, this, &manager::change_pass);
	connect(ui.book_serch_by_cata, &QPushButton::clicked, this, &manager::serch_by_cata);
	connect(ui.book_serch_by_name, &QPushButton::clicked, this, &manager::serch_by_name);
	connect(ui.data_databackup, &QPushButton::clicked, this, &manager::data_backup);
	connect(ui.data_datarecover, &QPushButton::clicked, this, &manager::data_recovery);

	connect(ui.book_add, &QPushButton::clicked, this, &manager::push_book_add);
	connect(ui.book_change, &QPushButton::clicked, this, &manager::push_book_change);
	connect(ui.book_delete, &QPushButton::clicked, this, &manager::push_book_delete);

	ui.stackedWidget->setCurrentIndex(0);
	
	
}
manager::~manager()
{

}

/*�л�ҳ����߼�*/

void manager::quit()
{
	emit log_out();
}

void manager::book_page()
{
	ui.stackedWidget->setCurrentIndex(1);

	emit enter_book(); // �����źţ�֪ͨ����ͼ��������
}
void manager::reader()
{
	ui.stackedWidget->setCurrentIndex(2);

	emit enter_usermessage(); // �����źţ�֪ͨ�����û���Ϣ����
}

void manager::data()
{
	ui.stackedWidget->setCurrentIndex(3);
}

void manager::feed_back()
{
	ui.stackedWidget->setCurrentIndex(4);
	emit enter_feed_back();
}
void manager::change_password()
{
	ui.stackedWidget->setCurrentIndex(5);
}
void manager::back_menu()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void manager::back_book_main_menu()//����Ƚ����⡢��book_main_window���ź����ӡ�
{}//��������Ĺ�������������ʵ����

/*�����ݲ㴫����Ϣ�����ֺ������ڴ˴���ֱ�����ź����ӵ�һ���ˣ�*/


void manager::change_pass()
{
	QString oldpass = ui.old_pass_line->text();
	QString newpass = ui.new_pass_line->text();
	QString re_newpass = ui.conflig_new_pass_line->text();
	if (newpass != re_newpass)
	{
		//����
	}
	else
	{
		string std_old_pass = oldpass.toUtf8().constData();
		string std_new_pass = newpass.toUtf8().constData();
		emit change_password_sig(std_old_pass, std_new_pass);
	}

}
void manager::serch_by_cata()
{
	QString cata = ui.lineEdit->text();
	string std_cata = cata.toUtf8().constData();
	emit serch_by_cata_sig(std_cata);
}
void manager::serch_by_name()
{
	QString name = ui.lineEdit->text();
	string std_name = name.toUtf8().constData();
	emit serch_by_name_sig(std_name);
}

void manager::push_book_add()
{
	book_manage_window->show();
	book_manage_window->set_page(0);
}

void manager::push_book_change()
{
	book_manage_window->show();
	book_manage_window->set_page(1);
}
void manager::push_book_delete()
{
	book_manage_window->show();
	book_manage_window->set_page(2);
}




/*�������ݲ������źŵĺ���*/
void manager::return_back(bool success, string message)
{
	QMessageBox::information(nullptr, QString::fromUtf8("��ʾ"), QString::fromUtf8(message));
}

void manager::print_feedback(std::vector<std::string> feedbacks)
{
	// ��ȡ���ؼ�
	QTableWidget* table = ui.tableWidget_3;

	// ��ձ�����ݵ�������ͷ
	table->setRowCount(0);

	// ���ñ������Ϊ������Ϣ����
	table->setRowCount(static_cast<int>(feedbacks.size()));

	// ����������1�У�
	table->setColumnCount(1);

	// ���ñ�ͷ��ǩ
	QStringList headers;
	/*headers << "������Ϣ";*/
	table->setHorizontalHeaderLabels(headers);

	// ��������䷴����Ϣ
	for (int row = 0; row < feedbacks.size(); ++row) {
		// �������������ı�
		QTableWidgetItem* item = new QTableWidgetItem(
			QString::fromStdString(feedbacks[row]));

		// �����ı����뷽ʽ����ѡ��
		item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);

		// ��ӵ����
		table->setItem(row, 0, item);
	}

	// �����п�����Ӧ����
	table->resizeColumnToContents(0);

	// �����п���չ�����հ�
	table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

	// ��ѡ�������и�
	table->verticalHeader()->setDefaultSectionSize(25);

	// ��ѡ�����ñ༭
	table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void manager::pring_reader(std::vector<user> usermessage)
{
	// ��ȡ���ؼ�
	QTableWidget* table = ui.tableWidget_2;  // ��ȷ��ʵ�ʿؼ�����

	// ������֮ǰ���������ݣ������У�
	table->setRowCount(0);

	// ���ñ��������4�У�
	table->setColumnCount(4);


	// ��������Ϊ�û�����
	table->setRowCount(static_cast<int>(usermessage.size()));

	// ����������û���Ϣ
	for (int row = 0; row < usermessage.size(); ++row) {
		const user& u = usermessage[row];

		// ������
		QTableWidgetItem* nameItem = new QTableWidgetItem(
			QString::fromStdString(u.user_name));
		table->setItem(row, 0, nameItem);

		// ���֤����
		QTableWidgetItem* idItem = new QTableWidgetItem(
			QString::fromStdString(u.user_id));
		table->setItem(row, 1, idItem);

		// �ֻ�����
		QTableWidgetItem* phoneItem = new QTableWidgetItem(
			QString::fromStdString(u.user_tele_num));
		table->setItem(row, 2, phoneItem);

		// Ƿ�ѽ���У���ʽ��Ϊ��λС����
		QString fineStr = QString::number(u.fine, 'f', 2);
		QTableWidgetItem* fineItem = new QTableWidgetItem(fineStr);

		// �����Ҷ�����ʾ���
		fineItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		table->setItem(row, 3, fineItem);
	}

	// �����п�����Ӧ����
	for (int col = 0; col < 4; ++col) {
		table->resizeColumnToContents(col);
	}

	// �������һ�У���Ϊ�̶���ȣ�����������Ӧ
	table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // ����
	table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive); // ���֤
	table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents); // �ֻ���
	table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed); // ���
	table->setColumnWidth(3, 100);  // ���ý���й̶����

	// ��ѡ�����ñ������
	table->setSelectionBehavior(QAbstractItemView::SelectRows);  // ����ѡ��
	table->setEditTriggers(QAbstractItemView::NoEditTriggers);   // ��ֹ�༭
	table->setAlternatingRowColors(true);  // ��������ɫ
}

void manager::print_book(vector<book> books)
{
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setRowCount(books.size());
	int i = 0;
	for (book that_book : books)
	{
		QString book_name = QString::fromUtf8(that_book.book_name);
		QString author_name = QString::fromUtf8(that_book.author);
		QString catalogy = QString::fromUtf8(that_book.category);
		QString ISBN = QString::fromUtf8(that_book.ISBN);
		QString in_library;
		if (that_book.in_library)
		{
			in_library = QString::fromUtf8("\xe6\x98\xaf");
		}
		else
		{
			in_library = QString::fromUtf8("\xe5\x90\xa6");
		}
		QString book_ID = QString::fromUtf8(that_book.id);
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(book_name));
		ui.tableWidget->setItem(i, 1, new QTableWidgetItem(author_name));
		ui.tableWidget->setItem(i, 2, new QTableWidgetItem(catalogy));
		ui.tableWidget->setItem(i, 3, new QTableWidgetItem(ISBN));
		ui.tableWidget->setItem(i, 4, new QTableWidgetItem(book_ID));
		ui.tableWidget->setItem(i, 5, new QTableWidgetItem(in_library));

		i++;
	}



}
