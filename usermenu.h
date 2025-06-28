#pragma once
#include"ui_user_menu.h"
#include <QtWidgets/QWidget>
#include<QtUiTools/QUiLoader>
#include<QFile>

class user_menu :public QWidget
{
    Q_OBJECT

public:
    user_menu(QWidget* parent = nullptr);
    ~user_menu();

signals:
    void Logout();


private slots:
    void push_borrow();
    void push_return();
    void push_serch();
    void push_history();
    void push_quit();
    void push_reset();
    void push_feed_back();

    
private:
    Ui::User_menu ui;

};