#include"manager.h"

manager::manager(QWidget* parent)
	: QWidget(parent)
{
	book_manage_window = new book_manage_win();
	ui.setupUi(this);
	//页面切换
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
	//向数据层传
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

/*切换页面的逻辑*/

void manager::quit()
{
	emit log_out();
}

void manager::book_page()
{
	ui.stackedWidget->setCurrentIndex(1);

	emit enter_book(); // 发送信号，通知进入图书管理界面
}
void manager::reader()
{
	ui.stackedWidget->setCurrentIndex(2);

	emit enter_usermessage(); // 发送信号，通知进入用户信息界面
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

void manager::back_book_main_menu()//这个比较特殊、与book_main_window的信号连接。
{}//这个函数的功能用其他方法实现了

/*向数据层传递信息（部分函数不在此处，直接用信号连接到一起了）*/


void manager::change_pass()
{
	QString oldpass = ui.old_pass_line->text();
	QString newpass = ui.new_pass_line->text();
	QString re_newpass = ui.conflig_new_pass_line->text();
	if (newpass != re_newpass)
	{
		//报错
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




/*接受数据层来的信号的函数*/
void manager::return_back(bool success, string message)
{
	QMessageBox::information(nullptr, QString::fromUtf8("提示"), QString::fromUtf8(message));
}

void manager::print_feedback(std::vector<std::string> feedbacks)
{
	// 获取表格控件
	QTableWidget* table = ui.tableWidget_3;

	// 清空表格内容但保留表头
	table->setRowCount(0);

	// 设置表格行数为反馈信息数量
	table->setRowCount(static_cast<int>(feedbacks.size()));

	// 设置列数（1列）
	table->setColumnCount(1);

	// 设置表头标签
	QStringList headers;
	/*headers << "反馈信息";*/
	table->setHorizontalHeaderLabels(headers);

	// 遍历并填充反馈信息
	for (int row = 0; row < feedbacks.size(); ++row) {
		// 创建表格项并设置文本
		QTableWidgetItem* item = new QTableWidgetItem(
			QString::fromStdString(feedbacks[row]));

		// 设置文本对齐方式（可选）
		item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);

		// 添加到表格
		table->setItem(row, 0, item);
	}

	// 调整列宽以适应内容
	table->resizeColumnToContents(0);

	// 设置列宽扩展以填充空白
	table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

	// 可选：设置行高
	table->verticalHeader()->setDefaultSectionSize(25);

	// 可选：禁用编辑
	table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void manager::pring_reader(std::vector<user> usermessage)
{
	// 获取表格控件
	QTableWidget* table = ui.tableWidget_2;  // 请确认实际控件名称

	// 清除表格之前的所有内容（包括行）
	table->setRowCount(0);

	// 设置表格列数（4列）
	table->setColumnCount(4);


	// 设置行数为用户数量
	table->setRowCount(static_cast<int>(usermessage.size()));

	// 遍历并填充用户信息
	for (int row = 0; row < usermessage.size(); ++row) {
		const user& u = usermessage[row];

		// 姓名列
		QTableWidgetItem* nameItem = new QTableWidgetItem(
			QString::fromStdString(u.user_name));
		table->setItem(row, 0, nameItem);

		// 身份证号列
		QTableWidgetItem* idItem = new QTableWidgetItem(
			QString::fromStdString(u.user_id));
		table->setItem(row, 1, idItem);

		// 手机号列
		QTableWidgetItem* phoneItem = new QTableWidgetItem(
			QString::fromStdString(u.user_tele_num));
		table->setItem(row, 2, phoneItem);

		// 欠费金额列（格式化为两位小数）
		QString fineStr = QString::number(u.fine, 'f', 2);
		QTableWidgetItem* fineItem = new QTableWidgetItem(fineStr);

		// 设置右对齐显示金额
		fineItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		table->setItem(row, 3, fineItem);
	}

	// 调整列宽以适应内容
	for (int col = 0; col < 4; ++col) {
		table->resizeColumnToContents(col);
	}

	// 设置最后一列（金额）为固定宽度，其他列自适应
	table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // 姓名
	table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive); // 身份证
	table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents); // 手机号
	table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed); // 金额
	table->setColumnWidth(3, 100);  // 设置金额列固定宽度

	// 可选：设置表格属性
	table->setSelectionBehavior(QAbstractItemView::SelectRows);  // 整行选择
	table->setEditTriggers(QAbstractItemView::NoEditTriggers);   // 禁止编辑
	table->setAlternatingRowColors(true);  // 交替行颜色
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
