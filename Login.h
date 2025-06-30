#pragma once
#include"ui_Login.h"
#include <QtWidgets/QWidget>


class Login : public QWidget
{
Q_OBJECT

public:
    Login(QWidget * parent = nullptr);
    ~Login();

signals:
    void manager_Login_success();
    void Login_success();
private slots:
    void push_Login();
    void push_quit();
private:
    Ui::Log_in ui;
};