#pragma once
#include"ui_Login.h"
#include <QtWidgets/QWidget>
#include<string>
#include<QMessageBox>
using namespace std;


class Login : public QWidget
{
Q_OBJECT

public:
    Login(QWidget * parent = nullptr);
    ~Login();
    void return_back(bool, string);

signals:
    void push_register();
    void manager_Login_sig(string account,string password);
    void user_Login_sig(string account , string password);
    void Login_success();
    void manager_Login_success();
private slots:
    void push_Login();
    void push_quit();
    
    
    
private:
    bool is_admin;
    Ui::Log_in ui;
    
    
};