#pragma once
#include"ui_manager.h"
#include <QtWidgets/QWidget>
#include<string>
#include<QMessageBox>
#include"people.h"
#include"book_manage.h"
using namespace std;

class manager : public QWidget
{
Q_OBJECT

public:
    book_manage_win* book_manage_window;
    manager(QWidget* parent = nullptr);
    ~manager();

    //接受信号的处理函数
    void print_feedback(vector<string>feedbacks);
    void pring_reader(vector<user> usermessage);
    void print_book(vector<book> books);
    void return_back(bool success, string message);
    
signals:
    void data_backup();
    void data_recovery();
    void serch_by_name_sig(string key);
    void serch_by_cata_sig(string key);
    void change_password_sig(string old_pass, string new_pass);
    void log_out();
    void enter_usermessage();
    void enter_feed_back();
    void enter_book();
    
    
private slots:
    //页面切换
    void back_menu();
    void quit();
    void change_password();
    void data();
    void reader();
    void feed_back();
    void book_page();
    void push_book_add();
    void push_book_change();
    void push_book_delete();
    void back_book_main_menu();

    //向数据层发信号
    void change_pass();
    void serch_by_cata();
    void serch_by_name();
    




private:
    Ui::Manager ui;
    
};
