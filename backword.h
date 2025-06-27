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
    bool can_change_password();
    std::vector<history> get_borrow_message();
    std::vector<book>get_book_message();
signals:

};