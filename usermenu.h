#pragma once
#include"ui_user_menu.h"
#include <QtWidgets/QWidget>
#include<QtUiTools/QUiLoader>
#include <QMessageBox>
#include<QFile>
#include<QString>
#include<string>
#include<book.h>
#include<people.h>



class user_menu :public QWidget
{
    Q_OBJECT

public:
    user_menu(QWidget* parent = nullptr);
    ~user_menu();
    //处理返回信号的函数
    void print_message(bool success, std::string message);
    void print_book_message(std::vector<book>);
    void printn_history_message(std::vector<history>);
    void print_fine(float fine ,std::string message);
    void print_leavedays(int days, std::string message);

signals:
    void Logout();
    void borrow_book(std::string book_id);
    void return_book(std::string book_id);
    void serch_by_name(std::string key);
    void serch_by_cata(std::string cata);
    void serch_history();
    void reset_password(std::string old_pass, std::string new_pass);
    void commit_feedback(std::string feed_back);
    void serch_fine();
    void pay_fine();

    void enter_serch();
    void enter_fine();



private slots:
    void push_borrow();
    void push_return();
    void push_serch();
    void push_history();
    void push_quit();
    void push_reset();
    void push_feed_back();
    void push_fine();
    void return_user_menu();

    void borrow_borrow_button();
    void return_return_button();
    void serch_serch_by_name();
    void serch_serch_by_cata();
    void history_serch_history();
    void reset_reset_password();
    void commit_commit_feedback();


    
private:
    Ui::User_menu ui;



};