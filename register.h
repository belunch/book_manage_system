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
    void push_register(string account ,string password,string ID,string tele_num );//��Ϣ����󷢳��źţ��ύ���ݲ㴦��
    void push_manager_register(string account, string password, string ID, string tele_num);
private slots:
    void pre_register();//������Ԥ������β����push_register�źţ�
private:
    Ui::Register ui;

};