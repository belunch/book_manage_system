#pragma once
#include"history.h"
#include <string>


class people
{

};

class user :public people
{
public:
    std::string user_name;
    std::string user_key;
    std::string user_id;
    std::string user_tele_num;
    float fine;
    user() : fine(0.0f) {}


    /*
    �о���Щ��������̫���ã�����Ҫ�Ļ��Լ���ӣ����ڲ����϶��ǶԲ��ϵġ�
    void borrow_book();
    void return_book();
    std::vector<book> serch_book_by_name();
    std::vector<book> serch_book_by_catalogy();
    std::vector<history> serch_history();
    bool pay_fine();
    void submint_feedback(std::string feedback);
    */

    

};

class admin :public people
{
public:
    std::string admin_name;
    std::string admin_key;
    std::string admin_id;
    std::string admin_tele_num;

    
};