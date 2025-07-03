#pragma once
#include<string>
using namespace std;

class book
{
public:
	bool in_library;
	std::string book_name;
	std::string author;
	std::string category;
	std::string ISBN;
	std::string id;

	book(std::string name = "", std::string author_name = "", std::string cata = "", std::string ISBN = "", std::string ID = "");
	void borrrow();//only ÇÐ»»Ò»ÏÂin_library×´Ì¬£»
};