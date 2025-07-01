#include"book.h"

book::book(string name, string author_name, string cata, string ISBN_in, string ID)
{
	book_name = name;
	author = author_name;
	category = cata;
	ISBN = ISBN_in;
	id = ID;
	in_library = true;
}

void book::borrrow()
{

}
