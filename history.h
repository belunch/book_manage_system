#pragma once
#include"book.h"
#include"date.h"
#include<string>

class history
{
public:
	std::string recode_num;//����������ſ���
	std::string book_id;
	std::string user_name;
	std::string user_id;
	date boorow_day;
	date return_day;

	history(); // Ĭ�Ϲ��캯��
	history(date borrow_day);
	~history();
	void set_back_day(date return_day);
};