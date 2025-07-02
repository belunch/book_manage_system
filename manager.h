#pragma once
#include"ui_manager.h"
#include <QtWidgets/QWidget>
#include<string>
#include<QMessageBox>
#include"people.h"
using namespace std;

class manager : public QWidget
{
Q_OBJECT

public:
    manager(QWidget* parent = nullptr);
    ~manager();

signals:
    void data_backup();
    void data_recovery();
    void serch_by_name_sig(string key);
    void serch_by_cata_sig(string key);
    void change_password_sig(string old_pass, string new_pass);
    void log_out();
    
    
private slots:
    void back_menu();
    void quit();
    void change_password();
    void data();
    void reader();
    void feed_back();
    void book_page();

    void change_pass();
    void serch_by_cata();
    void serch_by_name();



    void print_feedback(vector<string>feedbacks);
    void pring_reader(vector<user> usermessage);
    void print_book(vector<book> books);
    void return_back(bool success,string message);
private:
    Ui::Manager ui;
};
