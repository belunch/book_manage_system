#include"Data Processing Layer.h"
using namespace std;

//前向声明
bool is_valid_user_key(const string& user_key) { return user_key.length() == 6; };
bool is_valid_id(const std::string& user_id);
bool is_valid_new_key(const std::string& new_key);
bool is_valid_user_tele(const std::string& user_tele_num);



data_process::data_process(backword* back, QWidget* pargent)
{
	Back = back;
}

void  data_process::Sign_in(std::string user_name, std::string user_key)
{
	if (user_name.empty() || user_key.empty())
	{
		emit return_back(false, "Username or password cannot be empty.");
		return;
	}
	vector<user> userlist = Back->usermessage();
	bool isMatched = false;  // 标记是否找到匹配项
	for (const auto& userObj : userlist) {
		if (userObj.user_name == user_name && userObj.user_key == user_key) {
			User = userObj;
			isMatched = true;
			break;  // 找到匹配，跳出循环
		}
	}
	if (!isMatched)
	{
		emit return_back(false, "Username or password is incorrect.");
		return;
	}
	else {
		User.user_name = user_name;
		User.user_key = user_key;
		emit return_back(true, "Login successful.");
	}
}
void data_process::Sign_up(std::string user_name, std::string user_key, std::string user_id, std::string user_tele_num)
{
	if (user_name.empty() || user_key.empty() || user_id.empty() || user_tele_num.empty())
	{
		emit return_back(false, "Username, password, ID or phone number cannot be empty.");
		return;
	}
	if (!is_valid_user_key(user_key)) {
		emit return_back(false, "密码格式错误，请重新输入。");
		return;
	}
	if (!is_valid_id(user_id)) {
		emit return_back(false, "身份证号格式错误，请重新输入。");
		return;
	}
	if (!is_valid_user_tele(user_tele_num)) {
		emit return_back(false, "手机号格式错误，请重新输入。");
		return;
	}
	vector<user> userlist = Back->usermessage();
	for (const auto& userObj : userlist) {
		if (userObj.user_name == user_name) {
			emit return_back(false, "用户已存在，请直接登录");
			return;
		}
		if (userObj.user_id == user_id) {
			emit return_back(false, "用户已存在，请直接登录");
			return;
		}
		if (userObj.user_tele_num == user_tele_num) {
			emit return_back(false, "用户已存在，请直接登录");
			return;
		}
	}
	User.user_name = user_name;
	User.user_key = user_key;
	User.user_id = user_id;
	User.user_tele_num = user_tele_num;
	vector<user> users;
	users.push_back(User);//将用户信息存入users向量中
	bool have_saved = Back->save_user_message(users);//这个地方接口不对
	if (have_saved) {
		emit return_back(true, "注册成功，请登录。");
	}
	else {
		emit return_back(false, "注册失败，请稍后再试。");
	}
}
bool is_valid_id(const std::string& user_id) {
	int len = user_id.length();
	if (len != 18) {
		return false;
	}
	// 18位身份证：前17位为数字，第18位可为数字或X
	for (int i = 0; i < 17; i++) {
		if (!std::isdigit(user_id[i])) {
			return false;
		}
	}
	// 第18位校验：允许数字或x/X（转大写校验）
	char last_char = std::toupper(user_id[17]);
	return (std::isdigit(last_char) || last_char == 'X');
}

bool is_valid_user_tele(const std::string& user_tele_num) {
	// 长度必须11位
	if (user_tele_num.length() != 11) {
		return false;
	}
	// 全为数字
	for (char c : user_tele_num) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
}
void data_process::change_password(std::string old_key, std::string new_key)
{
	if (old_key.empty() || new_key.empty()) {
		emit return_back(false, "Old password or new password cannot be empty.");
		return;
	}
	if (old_key != User.user_key) {
		emit return_back(false, "Old password is incorrect.");
		return;
	}
	if (old_key == new_key) {
		emit return_back(false, "New password cannot be the same as old password.");
		return;
	}
	if (!is_valid_new_key(new_key)) {
		emit return_back(false, "New password must be 6 digits.");
		return;
	}
	User.user_key = new_key;
	bool have_changed = Back->can_change_password(User.user_id,new_key);
	if (have_changed) {
		emit return_back(true, "Password changed successfully.");
		return;
	}
}
bool is_valid_new_key(const std::string& new_key) {
	// 长度必须6位
	if (new_key.length() != 6) {
		return false;
	}
	// 全为数字
	for (char c : new_key) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
}
void data_process::borrow_book(std::string id)
{if (id.empty()) {
		emit return_back(false, "Book ID cannot be empty.");
		return;
	}
	if( User.fine > 0) {
		emit return_back(false, "You have unpaid fines, please pay them before borrowing books.");
		return;
	} 
	std::vector<history> historylist = Back->get_borrow_message();
	bool book_borrowed = false;
	for (const auto& record : historylist) {
		if (record.book_id == id && record.return_day.year==0 ) {
			book_borrowed = true;
			break;
		}
	}
	if (book_borrowed) {
		emit return_back(false, "The book is already borrowed and not returned yet, cannot borrow again.");
		return;
	}
	for (const auto& record : historylist) {
		if (record.user_id == User.user_id && record.return_day.year==0) {
			book_borrowed = true;
			break;
		}
	}
	if (book_borrowed) {
		emit return_back(false, "You have already borrowed a book and cannot borrow another one at the moment.");
		return;
	}
	bool have_borrowed = Back->borrow_out(id,User.user_id);//这好像也少参数
	if (have_borrowed) {
		emit return_back(true, "Book borrowed successfully.");
		return;
	}
	else {
		emit return_back(false," Failed to borrow book, please try again later.");
	}
}
void data_process::return_book(std::string id)
{
	vector<history> historylist = Back->get_borrow_message();
	for (const auto& record : historylist) {
		if (record.book_id == id && record.return_day.year==0) {
			if(record.user_id != User.user_id) {
				emit return_back(false, "This book was not borrowed by you, cannot return.");
				return;
			}
			if (User.fine == 0) {
				bool have_returned = Back->return_success(id,User.user_id);//少参数，靠设计做的太辣鸡了
				if (have_returned) {
					emit return_back(true, "Book returned successfully.");
					return;
				}
				else {
					emit return_back(false, "Failed to return book, please try again later.");
					return;
				}
			}
			else {
				emit return_back(true, "You have unpaid fines. Please pay them as soon as possible.");
				return; 
			}
		}
	}
	
	emit return_back(false, "This book has not been borrowed or has already been returned.");
	return;
		
	//emit return_back(false, "systrem have something wrong ,please turn to staff.");

}
void data_process::serch_by_key(std::string key)//这个参数传递有问题
{
	if (key.empty()) {
		emit return_back(false, "Search key cannot be empty.");
		return;
	}
	std::vector<book> booklist = Back->Get_book_message();
	std::vector<book> books;
	// 遍历 booklist，筛选书名包含 key 的书籍
	for (const book& b : booklist) {
		if (b.book_name.find(key) != std::string::npos) {
			books.push_back(b);
		}
	}
	emit return_bookmessage(books);
	return;
}
void data_process::serch_by_cata(std::string cata)//这个参数也有问题
{
	if (cata.empty()) {
		emit return_back(false, "Category cannot be empty.");
		return;
	}
	std::vector<book> booklist = Back->Get_book_message();
	std::vector<book> books;
	// 遍历 booklist，筛选书籍类别为 cata 的书籍
	for (const book& b : booklist) {
		if (b.category == cata) {
			books.push_back(b);
		}
	}
	emit return_bookmessage(books);
	return;
}
void data_process::submit_feedback(std::string feedback)//参数有问题
{
	if (feedback.empty()) {
		emit return_back(false, "Feedback cannot be empty.");
		return;
	}
	bool have_saved = Back->store_feedback(User.user_name,feedback);
	if (have_saved) {
		emit return_back(true, "Feedback submitted successfully.");
	} else {
		emit return_back(false, "Failed to submit feedback, please try again later.");
	}
	 
}
void data_process::examine_feedback()
{   std::vector<std::string> feedbacks = Back->examine_feedback();
	if (feedbacks.empty()) {
		emit return_back(false,"No feedback available at the moment.");
		return;
	}
	// 如果有反馈，直接返回
emit return_feedback(feedbacks);
return;
}

void data_process::return_book_cal_fine()//这个函数是干啥的来着？还没有连接
{
	date today;
	today = date::getCurrentDate();//这个函数需要重写->已完成
	std::vector<history> historylist = Back->get_borrow_message();
	if (historylist.empty()) {
		emit return_back(false, "No borrow records found.");
		return;
	}
	for (const auto& record : historylist) {
		//对每一个未归还记录查找
		if (record.user_id == User.user_id && record.return_day.year == 0 ) {
			int diff = record.borrow_day.daysTo(today);//这个函数要重写->已完成
			User.fine = 0.0;
			if (diff > 30) {
				User.fine = (diff - 30) * 0.2;//0.2来着吗
			}
			else {
				User.fine = 0.0;
			}
			emit return_fine(User.fine, "Fine calculated successfully.");
			return;
		}
	}
	emit return_back(false, "No borrow records found for the user.");
}
	void data_process::pay_fine(){
		if (User.fine <= 0) {
			emit return_back(false, "You have no fines to pay.");
			return;
		}
		bool have_paid = Back->restore_fine();
		if (have_paid) {
			emit return_back(true, "Fine paid successfully.");
			return;
		}
		else {
			emit return_back(false, "Failed to pay fine, please try again later.");
			return;
		}
	}
	void data_process::view_readers()
	{
		vector<user> userlist = Back->usermessage();
		if (userlist.empty()) {
			emit return_back(false, "No readers available.");
			return;
		}
		emit return_user_message(userlist);
		return;
	}
	void data_process::continue_pay_fine()//还未实现
	{

	}
	void data_process::data_backup()
	{
		bool have_saved = Back->Data_backups();
		if (have_saved) {
			emit return_back(true, "Data backup successful.");
		}
		else {
			emit return_back(false, "Data backup failed, please try again later.");
		}
	}

void data_process::data_recovery()
{
	bool have_recovered = Back->Data_recovery();
	if(have_recovered) {
		emit return_back(true, "Data recovery successful.");
	} else {
		emit return_back(false, "Data recovery failed, please try again later.");
	}
	return;
}
void data_process::add_book(std::string book_name, std::string author_name, std::string cata, std::string ISBN, std::string book_id)
{
	if(book_name.empty() || author_name.empty() || cata.empty() || ISBN.empty() || book_id.empty()) {
		emit return_back(false, "Book name, author name, category, ISBN or book ID cannot be empty.");
		return;
	}
	bool have_saved = Back->save_book(book_name, author_name, cata, ISBN, book_id);
	if(have_saved) {
		emit return_back(true, "Book added successfully.");
		return;
	}
	else {
		emit return_back(false, "Failed to add book, please try again later.");
		return;
	}
	
}
void data_process::change_book(std::string new_book_name, std::string new_author_name, std::string new_cata, std::string new_ISBN, std::string book_id)
{
	if(new_book_name.empty() || new_author_name.empty() || new_cata.empty() || new_ISBN.empty() || book_id.empty()) {
		emit return_back(false, "New book name, author name, category, ISBN or book ID cannot be empty.");
		return;
	}
	bool have_changed = Back->change_book_message(new_book_name, new_author_name, new_cata, new_ISBN, book_id);
	if (have_changed) {
		emit return_back(true, "Book information changed successfully.");
		return;
	} else {
		emit return_back(false, "Failed to change book information, please try again later.");
		return;
	}
}
void data_process::delete_book(std::string book_id)
{
	if (book_id.empty()) {
		emit return_back(false, "Book ID cannot be empty.");
		return;
	}
	vector<book> booklist = Back->Get_book_message();
	for (const auto& b : booklist) {
		if (b.id == book_id) {
			bool have_deleted = Back->delete_book(book_id);
			if (have_deleted) {
				emit return_back(true, "Book deleted successfully.");
				return;
			}
			else {
				emit return_back(false, "Failed to delete book, please try again later.");
				return;
			}
		}
	}
	emit return_back(false, "Book not found.");
	return;

}

