#pragma once

#include <QtWidgets/QWidget>
#include "ui_book_manage_system.h"
#include<Login.h>
#include"usermenu.h"

class book_manage_system : public QWidget
{
    Q_OBJECT

public:
    book_manage_system(QWidget *parent = nullptr);
    ~book_manage_system();

private slots:
    void login_success();
private:
    Ui::book_manage_systemClass ui;
    Login* Login_window;
    user_menu* User_main_menu;
};

