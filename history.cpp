#include"history.h"

history::history() : borrow_day(date()), return_day(date()) {}

history::history(date borrow_day)
{
    borrow_day = borrow_day;
}

history::~history()
{

}

void history::set_back_day(date return_day)
{
    this->return_day = return_day;
}
