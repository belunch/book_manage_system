#pragma once
#include<QString>
#include <QtWidgets/QWidget>
#include<string>
class background
{
signals:
	void login_success();
private slots:
	void account_and_password(QString acc, QString pass);
};