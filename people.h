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
};

class admin :public people
{
    std::string admin_name;
    std::string admin_key;
    std::string admin_id;
    std::string admin_tele_num;
};