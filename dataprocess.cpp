#include"Data Processing Layer.h"
using namespace std;


bool is_valid_user_key(const string& user_key);
bool is_valid_id(const std::string& user_id);


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

}
void data_process::change_password(std::string old_key, std::string new_key)
{

}
void data_process::borrow_book(std::string id)
{

}
void data_process::return_book(std::string id)
{

}
void data_process::serch_by_key(std::string key)
{

}
void data_process::serch_by_cata(std::string cata)
{

}
void data_process::submit_feedback(std::string feedback)
{

}
void data_process::examine_feedback()
{

}
void data_process::return_book_cal_fine()
{

}
void data_process::pay_fine()
{

}
void data_process::view_readers()
{

}
void data_process::continue_pay_fine()
{

}
void data_process::data_backup()
{

}
void data_process::data_recovery()
{

}
void data_process::add_book(std::string book_name, std::string author_name, std::string cata, std::string ISBN, std::string book_id)
{

}
void data_process::change_book(std::string new_book_name, std::string new_author_name, std::string new_cata, std::string new_ISBN, std::string book_id)
{

}
void data_process::delete_book(std::string book_id)
{

}
/*




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
	bool have_saved = Back->save_user_message();
	if (have_saved) {
		emit return_back(true, "注册成功，请登录。");
	}
	else {
		emit return_back(false, "注册失败，请稍后再试。");
	}
}








bool is_valid_user_key(const std::string& user_key)
{
	// 长度必须6位
	if (user_tele_num.length() != 6) {
		return false;
	}
	// 全为数字
	for (char c : user_tele_num) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
}
	bool is_valid_id(const std::string & user_id) {
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

	bool is_valid_user_tele(const std::string & user_tele_num) {
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

	void data_process::change_password(std::string old_key, std::string new_key) {
		//************
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
		bool valid = 1;
		bool have_changed = Back->change_user_key(valid);
		if (have_changed) {
			emit return_back(true, "Password changed successfully.");
			return;
		}
	}
	bool is_valid_new_key(const std::string& new_key) {
		// 长度必须6位
		if (user_tele_num.length() != 6) {
			return false;
		}
		// 全为数字
		for (char c : user_tele_num) {
			if (!std::isdigit(c)) {
				return false;
			}
		}
	}


		void serch_by_key(std::string key) {
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




*/



