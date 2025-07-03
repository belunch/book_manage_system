#pragma once
#include"ui_boook_managet.h"
#include<string>
#include<QString>
#include<QMessageBox>
using namespace std;


class book_manage_win :public QWidget
{
	Q_OBJECT;
public:
    book_manage_win( QWidget* parent = nullptr);
    ~book_manage_win() {};
    void set_page(int i = 0);
    Ui::book_manage ui;
    void clear_all();
signals:
    void add_book(string name, string author_name, string cata, string ISBN, string book_id);
    void change_book(string new_book_name, string new_author_name, string new_cata, string new_ISBN, string book_id);
    void delete_book(string book_id);
    void quit();
private slots:
    void push_confer();
    void pushu_quit();
private:
    
};