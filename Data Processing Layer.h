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
    void submit_feedback(std::string feedback);
    void examine_feedback();
    void return_book_cal_fine();
    void pay_fine();
    void view_readers();
    void continue_pay_fine();
    void data_backup();
    void data_recovery();
    void add_book(std::string book_name, std::string author_name, std::string cata, std::string ISBN,std::string book_id );
    void change_book(std::string new_book_name, std::string new_author_name, std::string new_cata, std::string new_ISBN, std::string book_id);
    void delete_book(std::string book_id);
    void admin_Sign_in(string admin_name, string admin_key);
    void Admin_Sign_up(std::string admin_name, std::string admin_key, std::string admin_id, std::string admin_tele_num);
    void admin_change_password(std::string old_key, std::string new_key); 
    void view_user_history();
    void view_bookmessages(); 
    void leavedays();
private:
    backword* Back;
    user User;
    admin Admin;
signals:

    void return_leavedays(int days, std::string message);
    void return_history(std::vector<history> history);
    void return_user_message(std::vector<user>);
    void return_back(bool success, std::string error_message);
    void return_bookmessage(std::vector<book>);
	void return_feedback(std::vector<std::string> feedbacks);
	void return_fine(float fine,std::string);
	
    
    

};
