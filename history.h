#pragma once
#include"book.h"
#include"date.h"
#include<string>

class history
{
	std::string recode_num;
	std::string book_id;
	std::string user_name;
	std::string user_id;
	date boorow_day;
	date return_day;
};