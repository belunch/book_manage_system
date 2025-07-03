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
	connect(ui.button_fine, &QPushButton::clicked, this, &user_menu::push_fine);//进入罚款缴纳界面

	connect(ui.borrow_quit_button, &QPushButton::clicked, this, &user_menu::return_user_menu);//借书界面的返回按钮
	connect(ui.return_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//还书界面的返回按钮
	connect(ui.feedback_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//反馈界面的返回按钮
	connect(ui.serch_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//查找界面的返回按钮
	connect(ui.history_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//历史界面的返回按钮
	connect(ui.reset_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//重置密码的返回按钮
	connect(ui.button_fine_quit, &QPushButton::clicked, this, &user_menu::return_user_menu);//交罚款界面的返回按钮

	connect(ui.borrow_borrow_button, &QPushButton::clicked, this, &user_menu::borrow_borrow_button);//连接借书界面的借书按钮和函数
	connect(ui.return_return_button, &QPushButton::clicked, this, &user_menu::return_return_button);//连接还书界面的按钮与函数
	connect(ui.serch_by_name, &QPushButton::clicked, this, &user_menu::serch_serch_by_name);//连接按书名查找按钮与函数
	connect(ui.serch_by_cata, &QPushButton::clicked, this, &user_menu::serch_serch_by_cata);
	connect(ui.history_serch, &QPushButton::clicked, this, &user_menu::history_serch_history);
	connect(ui.reset_reset, &QPushButton::clicked, this, &user_menu::reset_reset_password);
	connect(ui.feedback_feedback, &QPushButton::clicked, this, &user_menu::commit_commit_feedback);
	connect(ui.button_fine_confirm, &QPushButton::clicked, this, &user_menu::pay_fine);

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
	ui.serch_table->setRowCount(0);
	ui.serch_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.serch_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.serch_table->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.serch_table->horizontalHeader()->setStretchLastSection(true);
	//测试用内容
	//ui.serch_table->setRowCount(5);
	//ui.serch_table->setItem(0, 0, new QTableWidgetItem(QString::fromLocal8Bit("中文内容")));
	//ui.serch_table->setItem(0, 1, new QTableWidgetItem("25"));
	//ui.serch_table->setItem(0, 2, new QTableWidgetItem("男"));

	//ui.serch_table->setItem(1, 0, new QTableWidgetItem("李四"));
	//ui.serch_table->setItem(1, 1, new QTableWidgetItem("30"));
	//ui.serch_table->setItem(1, 2, new QTableWidgetItem("女"));

	//QMessageBox::information(nullptr, "提示", "这是一条信息提示");

	//book book_1("小王的故事", "小王", "爱情", "LOVE_1", "001");
	//book book_2("小美的复仇", "小美", "动作", "action_1", "010");
	//vector<book> books;
	//books.push_back(book_1);
	//books.push_back(book_2);
	//print_book_message(books);


}

void user_menu::push_history()
{
	ui.stackedWidget->setCurrentIndex(4);

	//测试用
	//vector<history> historys;
	//date day1;
	//day1.year = 1989;
	//day1.month = 12;
	//day1.day = 14;
	//history History(day1);
	//History.boorow_day = day1;
	//History.return_day = day1;
	//History.book_id = "001";
	//historys.push_back(History);
	//History.book_id = "010";
	//historys.push_back(History);
	//printn_history_message(historys);
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

void user_menu::push_fine()
{
	ui.stackedWidget->setCurrentIndex(7);

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
	std::string std_ID = book_ID.toUtf8().constData();
	emit borrow_book(std_ID);
}

void user_menu::return_return_button()
{
	QString book_ID = ui.return_line_edit->text();
	std::string std_ID = book_ID.toUtf8().constData();
	emit return_book(std_ID);
}

void user_menu::serch_serch_by_name()
{
	QString book_name_key = ui.serch_by_name->text();
	std::string std_name_key = book_name_key.toUtf8().constData();
	emit serch_by_name(std_name_key);
}

void user_menu::serch_serch_by_cata()
{
	QString book_cata = ui.serch_by_cata->text();
	std::string std_cata = book_cata.toUtf8().constData();
	emit serch_by_cata(std_cata);
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
		print_message(false, "两次输入的密码必须相同");
	}
	else
	{
		std::string std_new_pass = new_pass.toUtf8().constData();
		std::string std_old_pass = old_pass.toUtf8().constData();

		emit reset_password(std_old_pass,std_new_pass);
	}
}

void user_menu::commit_commit_feedback()
{
	QString feedback = ui.textEdit->toPlainText();
	std::string std_feedback = feedback.toUtf8().constData();
	emit commit_feedback(std_feedback);
}









//*********************************************************************
//以下函数是与数据层的信号连接的
//*********************************************************************

void user_menu::print_message(bool success, std::string message)
{
	//QMessageBox::information(nullptr, "提示", "这是一条信息提示");
	//QString::fromLocal8Bit("中文内容")
	QMessageBox::information(nullptr, QString::fromUtf8("提示"), QString::fromUtf8(message));

}

void user_menu::print_book_message(std::vector<book> books)
{
	//测试用内容
//ui.serch_table->setRowCount(5);
//ui.serch_table->setItem(0, 0, new QTableWidgetItem(QString::fromLocal8Bit("中文内容")));
//ui.serch_table->setItem(0, 1, new QTableWidgetItem("25"));
//ui.serch_table->setItem(0, 2, new QTableWidgetItem("男"));
	ui.serch_table->setRowCount(0);
	ui.serch_table->setRowCount(books.size());
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
		ui.serch_table->setItem(i, 0, new QTableWidgetItem(book_name));
		ui.serch_table->setItem(i, 1, new QTableWidgetItem(author_name));
		ui.serch_table->setItem(i, 2, new QTableWidgetItem(catalogy));
		ui.serch_table->setItem(i, 3, new QTableWidgetItem(in_library));
		ui.serch_table->setItem(i, 4, new QTableWidgetItem(book_ID));

		i++;
	}



}


void user_menu::printn_history_message(std::vector<history> histories) {

	ui.history_table->setRowCount(0);
	// 设置表格行数为历史记录数量
	ui.history_table->setRowCount(static_cast<int>(histories.size()));

	// 遍历每条历史记录
	for (int row = 0; row < histories.size(); ++row) {
		const history& h = histories[row];

		// 第一列：书名（显示book_id）
		QTableWidgetItem* bookItem = new QTableWidgetItem(QString::fromStdString(h.book_id));
		ui.history_table->setItem(row, 0, bookItem);

		// 第二列：借出日期（格式化为"年-月-日"）
		QString borrowDate = QString("%1-%2-%3")
			.arg(h.borrow_day.year)
			.arg(h.borrow_day.month, 2, 10, QLatin1Char('0'))  // 固定2位宽度，补零
			.arg(h.borrow_day.day, 2, 10, QLatin1Char('0'));
		QTableWidgetItem* borrowItem = new QTableWidgetItem(borrowDate);
		ui.history_table->setItem(row, 1, borrowItem);

		// 第三列：还书日期（检查有效性并格式化）
		QTableWidgetItem* returnItem = nullptr;
		if (h.return_day.year > 0) { // 假设year>0表示有效日期
			QString returnDate = QString("%1-%2-%3")
				.arg(h.return_day.year)
				.arg(h.return_day.month, 2, 10, QLatin1Char('0'))
				.arg(h.return_day.day, 2, 10, QLatin1Char('0'));
			returnItem = new QTableWidgetItem(returnDate);
		}
		else {
			returnItem = new QTableWidgetItem("未归还");
		}
		ui.history_table->setItem(row, 2, returnItem);
	}
}

void user_menu::print_fine(float fine, std::string message)
{
	
		// 保留 2 位小数
	ui.finelabel->setText(QString::number(fine, 'f', 2));
	
}

void user_menu::print_leavedays(int days, std::string message)
{
	QString prompt = QString("提示：您有一本书在 %1 天后逾期").arg(days);
	QMessageBox::information(this, "逾期提醒", prompt);
}
