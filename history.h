#pragma once
#include"book.h"
#include"date.h"
#include<string>

class history
{
public:
	std::string recode_num;//主键，当编号看待
	std::string book_id;
	std::string user_name;
	std::string user_id;
	date boorow_day;
	date return_day;

	history(); // 默认构造函数
	history(date borrow_day);
	~history();
	void set_back_day(date return_day);
};