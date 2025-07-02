#pragma once
#include <QObject>
#include <QFuture>
#include<string>
#include<vector>
#include"people.h"

class backword : public QObject {
    Q_OBJECT
public:
    backword() ;
    std::vector<user>usermessage();
    bool save_user_message();
    bool can_change_password() {};
    bool can_change_password(std::string user_id, std::string new_key);
    std::vector<history> get_borrow_message();
    std::vector<book>get_book_message();
    bool borrow_out();
    bool return_success();
    bool  store_feedback(std::string user_feedback);
    std::vector<std::string> examine_feedback();
    bool calcu_fine(float fine);
    float pay_fine();
    bool restore_fine();
    bool save_user_message(user save_user);
    bool save_user_message(std::vector<user> users);
    bool Data_backups();
    bool Data_recovery();
    bool save_book(std::string book_name, std::string author_name, std::string cata, std::string ISBN, std::string book_id);
    std::vector<book>  Get_book_message();
    bool change_book_message(std::string new_book_name, std::string new_author_name, std::string new_cata, std::string new_ISBN, std::string book_id);
    bool delete_book(std::string book_id);
    bool create_tables();
signals:

};