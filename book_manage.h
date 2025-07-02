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
signals:
    void add_book(string name, string author_name, string cata, string ISBN, string book_id);
private slots:
    void push_confer();
    void pushu_quit();
private:
    Ui::book_manage ui;
};