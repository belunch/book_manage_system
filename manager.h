#pragma once
#include"ui_manager.h"
#include <QtWidgets/QWidget>


class manager : public QWidget
{
Q_OBJECT

public:
    manager(QWidget* parent = nullptr);
    ~manager();

signals:
    void log_out();
    
private slots:
    void back_menu();
    void quit();
    void change_password();
    void data();
    void reader();
    void feed_back();
    void book();
private:
    Ui::Manager ui;
};
