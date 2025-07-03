#pragma once

#include <QtWidgets/QWidget>
#include "ui_book_manage_system.h"
#include<Login.h>
#include"usermenu.h"
#include"manager.h"
#include"register.h"
#include"Data Processing Layer.h"
#include<string>
#include<vector>

class book_manage_system : public QWidget
{
    Q_OBJECT

public:
    book_manage_system(data_process* data,QWidget *parent = nullptr);
    ~book_manage_system();
    manager* Manager_main_menu;


signals:
	void enter_user_menu();//进入用户主界面
private slots:
    void login_success();//切换到用户主界面
    void log_out();//退出到登录界面
    void manager_login();//进入管理员主界面
    void register_window();//进入注册页面
    //这个地方差点功能、要确保在退出登录之后、系统中没有上一个用户的信息。（好像也不用、现在点击即可登录导致的）
private:
    Ui::book_manage_systemClass ui;
    data_process* Data;
    Login* Login_window;
    user_menu* User_main_menu;
    register_win* Register_menu;
};

