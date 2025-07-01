#pragma once
#include"book.h"
#include"date.h"
#include<string>

class history
{
public:
	std::string recode_num;//Ö÷¼ü£¬µ±±àºÅ¿´´ý
	std::string book_id;
	std::string user_name;
	std::string user_id;
	date boorow_day;
	date return_day;

	history(date borrow_day);
	~history();
	void set_back_day(date return_day);
};