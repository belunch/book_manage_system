#pragma once

#include"people.h"
#include <QObject>
#include <QFuture>
#include <QString>
#include"backword.h"
#include<string>
#include<vector>

class data_process : public QObject {
    Q_OBJECT
public:
    data_process(backword* back, QWidget* parent = nullptr);
    void Sign_in(std::string user_name,std:: string user_key);
    void Sign_up(std::string user_name, std::string user_key, std::string user_id, std::string user_tele_num);
    void change_password(std::string old_key, std::string new_key);
    void borrow_book(std::string id);
    void return_book(std::string id);
    void serch_by_key(std::string key);
    void serch_by_cata(std::string cata);
private:
    backword* Back;
    user User;
signals:
    void return_back(bool success, std::string error_message);
    void return_bookmessage(std::vector<book>);
};
