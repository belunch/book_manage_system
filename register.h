#pragma once
#include"ui_register.h"
#include <QtWidgets/QWidget>
#include<string>
#include<QString>
using namespace std;


class register_win : public QWidget
{
    Q_OBJECT
public:
    register_win(QWidget* parent = nullptr);
    ~register_win();
    
signals:
    void quit();
    void push_register(string account ,string password,string ID,string tele_num );//信息处理后发出信号，提交数据层处理
    void push_manager_register(string account, string password, string ID, string tele_num);
private slots:
    void pre_register();//对输入预处理、结尾发出push_register信号；
private:
    Ui::Register ui;

};