#include"Data Processing Layer.h"

data_process::data_process(backword* back, QWidget* pargent)
{
	Back = back;
	emit return_back(, "Data processing layer initialized successfully.");
}




void  data_process::Sign_in(std::string user_name, std::string user_key)
{
	if(user_name.empty()||user_key.empty())
		{
		emit return_back(false, "Username or password cannot be empty.");
		return;
	}
		vector<user> userlist=back->usermessage();
		bool isMatched = false;  // ����Ƿ��ҵ�ƥ����
		for (const auto& userObj : userlist) {
			if (userObj.user_name == user_name && userObj.user_key == user_key) {
				isMatched = true;
				break;  // �ҵ�ƥ�䣬����ѭ��
			}
		}
		if(!isMatched)
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
		emit return_back(false, "�����ʽ�������������롣");
		return;
	}
	if (!is_valid_id(user_id)) {
		emit return_back(false, "���֤�Ÿ�ʽ�������������롣");
		return;
	}
	if (!is_valid_user_tele(user_tele_num)) {
		emit return_back(false, "�ֻ��Ÿ�ʽ�������������롣");
		return;
	}
	vector<user> userlist=back->usermessage();
		for (const auto& userObj : userlist) {
		if (userObj.user_name == user_name) {
			emit return_back(false, "�û��Ѵ��ڣ���ֱ�ӵ�¼");
			return;
		}
		if (userObj.id_card == user_id) {
			emit return_back(false, "�û��Ѵ��ڣ���ֱ�ӵ�¼");
			return;
		}
		if (userObj.telephone == user_tele_num) {
			emit return_back(false, "�û��Ѵ��ڣ���ֱ�ӵ�¼");
			return;
		}
	}
		User.user_name = user_name;
		User.user_key = user_key;
		User.user_id = user_id;
		User.user_tele_num = user_tele_num;
	bool have_saved = back->save_user_message(user);
	if(have_saved) {
		emit return_back(true, "ע��ɹ������¼��");
	} else {
		emit return_back(false, "ע��ʧ�ܣ����Ժ����ԡ�");
	}
}
	bool is_valid_user_key(const std::string& user_key) {
		// ���ȱ���6λ
		if (user_tele_num.length() != 6) {
			return false;
		}
		// ȫΪ����
		for (char c : user_tele_num) {
			if (!std::isdigit(c)) {
				return false;
			}
		}
	bool is_valid_id(const std::string& user_id) {
		int len = user_id.length();
			if ( len != 18) {
				return false;
			}
		// 18λ���֤��ǰ17λΪ���֣���18λ��Ϊ���ֻ�X
		for (int i = 0; i < 17; i++) {
			if (!std::isdigit(user_id[i])) {
				return false;
			}
		}
		// ��18λУ�飺�������ֻ�x/X��ת��дУ�飩
		char last_char = std::toupper(user_id[17]);
		return (std::isdigit(last_char) || last_char == 'X');
	}

	bool is_valid_user_tele(const std::string& user_tele_num) {
		// ���ȱ���11λ
		if (user_tele_num.length() != 11) {
			return false;
		}
		// ȫΪ����
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
		bool have_changed = back->change_user_key(valid);
		if (have_changed) {
			emit return_back(true, "Password changed successfully.");
			return;
		}
	}
	bool is_valid_new_key(const std::string& new_key) {
		// ���ȱ���6λ
		if (user_tele_num.length() != 6) {
			return false;
		}
		// ȫΪ����
		for (char c : user_tele_num) {
			if (!std::isdigit(c)) {
				return false;
			}
		}


		void serch_by_key(std::string key) {
			if (key.empty()) {
				emit return_back(false, "Search key cannot be empty.");
				return;
			}
			std::vector<book> booklist = back->Get_book_message();
			std::vector<book> books;
			// ���� booklist��ɸѡ�������� key ���鼮
			for (const book& b : booklist) {
				if (b.book_name.find(key) != std::string::npos) {
					books.push_back(b);
				}
			}
			emit return_bookmessage(books);
			return;
		}