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

void register_win::pre_register()
{
	QString name, pass, ID, tele_num;
	name = ui.name_line->text();
	pass = ui.pass_line->text();
	ID = ui.id_line->text();
	tele_num = ui.telenum_line->text();
	string std_name, std_pass, std_ID, std_tele;
	std_name = name.toStdString();
	std_pass = pass.toStdString();
	std_ID = ID.toStdString();
	std_tele = tele_num.toStdString();
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