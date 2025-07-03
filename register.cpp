#include"register.h"


register_win::register_win(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.button_register, &QPushButton::clicked, this, &register_win::pre_register);
	connect(ui.quit_button, &QPushButton::clicked, this, &register_win::quit);
}

register_win::~register_win()
{

}

void register_win::clear_all()
{
	// 清空所有 QLineEdit 内容
	QList<QLineEdit*> lineEdits = this->findChildren<QLineEdit*>();
	foreach(QLineEdit * lineEdit, lineEdits) {
		lineEdit->clear();
	}
}

void register_win::pre_register()
{
	QString name, pass, ID, tele_num;
	name = ui.name_line->text();
	pass = ui.pass_line->text();
	ID = ui.id_line->text();
	tele_num = ui.telenum_line->text();
	string std_name, std_pass, std_ID, std_tele;
	std_name = name.toUtf8().constData();
	std_pass = pass.toUtf8().constData();
	std_ID = ID.toUtf8().constData();
	std_tele = tele_num.toUtf8().constData();
	if (ui.checkBox_manager->isChecked())
	{
		emit push_manager_register(std_name, std_pass, std_ID, std_tele);
	}
	else
	{
		emit push_register(std_name, std_pass, std_ID, std_tele);
	}
	
	/*
	ui.label->setText(name);//测试槽函数联通是否成功
	注册键槽函数连接正常；
	*/
 }

void register_win::print_message(bool success, std::string message)
{
	QMessageBox::information(nullptr, QString::fromUtf8("提示"), QString::fromUtf8(message));
	clear_all();
}