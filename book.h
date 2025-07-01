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

	book(string name=0,string author_name=0,string cata=0,string ISBN=0,string ID=0);
	void borrrow();//only ÇÐ»»Ò»ÏÂin_library×´Ì¬£»
};