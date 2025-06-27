#pragma once
#include"ui_user_menu.h"
#include <QtWidgets/QWidget>

class user_menu :public QWidget
{
    Q_OBJECT

public:
    user_menu(QWidget* parent = nullptr);
    ~user_menu();

private slots:
    void push_borrow();
    void push_return();
    void push_serch();
    void push_history();
    void push_quit();
    void push_reset();
    void push_feed_back();

    
private:
    Ui::ui_user_menu ui;
};