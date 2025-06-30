/********************************************************************************
** Form generated from reading UI file 'user_menu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_MENU_H
#define UI_USER_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User_menu
{
public:
    QLabel *welcom_line;
    QPushButton *button_signout;
    QStackedWidget *stackedWidget;
    QWidget *page_main_menu;
    QPushButton *button_feedback;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *button_borrow;
    QPushButton *button_return;
    QPushButton *button_serch;
    QPushButton *button_history;
    QPushButton *button_reset_password;
    QWidget *page_borrow;
    QLineEdit *borrow_line_edit;
    QLabel *borrow_hint;
    QLabel *borrow_main_LOGO;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *borrow_borrow_button;
    QPushButton *borrow_quit_button;
    QWidget *page_return;
    QLineEdit *return_line_edit;
    QLabel *return_hint;
    QLabel *retur_LOGO;
    QPushButton *return_return_button;
    QPushButton *return_quit;
    QWidget *page_serch;
    QLineEdit *serch_line_edit;
    QPushButton *serch_by_name;
    QPushButton *serch_by_cata;
    QLabel *label_please;
    QTableWidget *serch_table;
    QPushButton *serch_quit;
    QWidget *page_history;
    QTableWidget *history_table;
    QLabel *history_lable;
    QPushButton *history_serch;
    QPushButton *history_quit;
    QWidget *page_reset_password;
    QPushButton *reset_reset;
    QPushButton *reset_quit;
    QLineEdit *reset_oldpass;
    QLineEdit *reset_newpass;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *reset_config_newpass;
    QWidget *page_feedback;
    QTextEdit *textEdit;
    QPushButton *feedback_feedback;
    QPushButton *feedback_quit;

    void setupUi(QWidget *User_menu)
    {
        if (User_menu->objectName().isEmpty())
            User_menu->setObjectName("User_menu");
        User_menu->resize(847, 830);
        welcom_line = new QLabel(User_menu);
        welcom_line->setObjectName("welcom_line");
        welcom_line->setGeometry(QRect(150, 20, 240, 40));
        welcom_line->setMinimumSize(QSize(240, 40));
        welcom_line->setMaximumSize(QSize(240, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(16);
        welcom_line->setFont(font);
        welcom_line->setAlignment(Qt::AlignmentFlag::AlignCenter);
        button_signout = new QPushButton(User_menu);
        button_signout->setObjectName("button_signout");
        button_signout->setGeometry(QRect(420, 30, 81, 24));
        stackedWidget = new QStackedWidget(User_menu);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(20, 60, 521, 381));
        page_main_menu = new QWidget();
        page_main_menu->setObjectName("page_main_menu");
        button_feedback = new QPushButton(page_main_menu);
        button_feedback->setObjectName("button_feedback");
        button_feedback->setGeometry(QRect(360, 320, 81, 24));
        layoutWidget = new QWidget(page_main_menu);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 10, 345, 345));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(75);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(10, 10, 10, 10);
        button_borrow = new QPushButton(layoutWidget);
        button_borrow->setObjectName("button_borrow");
        button_borrow->setMinimumSize(QSize(125, 125));
        button_borrow->setMaximumSize(QSize(125, 125));

        gridLayout->addWidget(button_borrow, 0, 0, 1, 1);

        button_return = new QPushButton(layoutWidget);
        button_return->setObjectName("button_return");
        button_return->setMinimumSize(QSize(125, 125));
        button_return->setMaximumSize(QSize(125, 125));

        gridLayout->addWidget(button_return, 0, 1, 1, 1);

        button_serch = new QPushButton(layoutWidget);
        button_serch->setObjectName("button_serch");
        button_serch->setMinimumSize(QSize(125, 125));
        button_serch->setMaximumSize(QSize(125, 125));

        gridLayout->addWidget(button_serch, 1, 0, 1, 1);

        button_history = new QPushButton(layoutWidget);
        button_history->setObjectName("button_history");
        button_history->setMinimumSize(QSize(125, 125));
        button_history->setMaximumSize(QSize(125, 125));

        gridLayout->addWidget(button_history, 1, 1, 1, 1);

        button_reset_password = new QPushButton(page_main_menu);
        button_reset_password->setObjectName("button_reset_password");
        button_reset_password->setGeometry(QRect(360, 280, 81, 24));
        stackedWidget->addWidget(page_main_menu);
        page_borrow = new QWidget();
        page_borrow->setObjectName("page_borrow");
        borrow_line_edit = new QLineEdit(page_borrow);
        borrow_line_edit->setObjectName("borrow_line_edit");
        borrow_line_edit->setGeometry(QRect(240, 200, 181, 21));
        borrow_hint = new QLabel(page_borrow);
        borrow_hint->setObjectName("borrow_hint");
        borrow_hint->setGeometry(QRect(100, 200, 131, 31));
        borrow_main_LOGO = new QLabel(page_borrow);
        borrow_main_LOGO->setObjectName("borrow_main_LOGO");
        borrow_main_LOGO->setGeometry(QRect(190, 50, 121, 131));
        QFont font1;
        font1.setPointSize(24);
        borrow_main_LOGO->setFont(font1);
        borrow_main_LOGO->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(page_borrow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 250, 341, 72));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        borrow_borrow_button = new QPushButton(widget);
        borrow_borrow_button->setObjectName("borrow_borrow_button");

        gridLayout_2->addWidget(borrow_borrow_button, 0, 0, 1, 1);

        borrow_quit_button = new QPushButton(widget);
        borrow_quit_button->setObjectName("borrow_quit_button");

        gridLayout_2->addWidget(borrow_quit_button, 1, 0, 1, 1);

        stackedWidget->addWidget(page_borrow);
        page_return = new QWidget();
        page_return->setObjectName("page_return");
        return_line_edit = new QLineEdit(page_return);
        return_line_edit->setObjectName("return_line_edit");
        return_line_edit->setGeometry(QRect(240, 120, 113, 23));
        return_hint = new QLabel(page_return);
        return_hint->setObjectName("return_hint");
        return_hint->setGeometry(QRect(150, 120, 54, 16));
        retur_LOGO = new QLabel(page_return);
        retur_LOGO->setObjectName("retur_LOGO");
        retur_LOGO->setGeometry(QRect(210, 70, 54, 16));
        return_return_button = new QPushButton(page_return);
        return_return_button->setObjectName("return_return_button");
        return_return_button->setGeometry(QRect(110, 180, 81, 24));
        return_quit = new QPushButton(page_return);
        return_quit->setObjectName("return_quit");
        return_quit->setGeometry(QRect(300, 180, 81, 24));
        stackedWidget->addWidget(page_return);
        page_serch = new QWidget();
        page_serch->setObjectName("page_serch");
        serch_line_edit = new QLineEdit(page_serch);
        serch_line_edit->setObjectName("serch_line_edit");
        serch_line_edit->setGeometry(QRect(120, 10, 113, 23));
        serch_by_name = new QPushButton(page_serch);
        serch_by_name->setObjectName("serch_by_name");
        serch_by_name->setGeometry(QRect(250, 10, 81, 24));
        serch_by_cata = new QPushButton(page_serch);
        serch_by_cata->setObjectName("serch_by_cata");
        serch_by_cata->setGeometry(QRect(350, 10, 81, 24));
        label_please = new QLabel(page_serch);
        label_please->setObjectName("label_please");
        label_please->setGeometry(QRect(30, 20, 54, 16));
        serch_table = new QTableWidget(page_serch);
        serch_table->setObjectName("serch_table");
        serch_table->setGeometry(QRect(40, 60, 401, 231));
        serch_quit = new QPushButton(page_serch);
        serch_quit->setObjectName("serch_quit");
        serch_quit->setGeometry(QRect(370, 310, 81, 24));
        stackedWidget->addWidget(page_serch);
        page_history = new QWidget();
        page_history->setObjectName("page_history");
        history_table = new QTableWidget(page_history);
        history_table->setObjectName("history_table");
        history_table->setGeometry(QRect(55, 81, 421, 231));
        history_lable = new QLabel(page_history);
        history_lable->setObjectName("history_lable");
        history_lable->setGeometry(QRect(140, 40, 111, 20));
        history_serch = new QPushButton(page_history);
        history_serch->setObjectName("history_serch");
        history_serch->setGeometry(QRect(270, 40, 81, 24));
        history_quit = new QPushButton(page_history);
        history_quit->setObjectName("history_quit");
        history_quit->setGeometry(QRect(390, 330, 81, 24));
        stackedWidget->addWidget(page_history);
        page_reset_password = new QWidget();
        page_reset_password->setObjectName("page_reset_password");
        reset_reset = new QPushButton(page_reset_password);
        reset_reset->setObjectName("reset_reset");
        reset_reset->setGeometry(QRect(320, 250, 81, 24));
        reset_quit = new QPushButton(page_reset_password);
        reset_quit->setObjectName("reset_quit");
        reset_quit->setGeometry(QRect(320, 290, 81, 24));
        reset_oldpass = new QLineEdit(page_reset_password);
        reset_oldpass->setObjectName("reset_oldpass");
        reset_oldpass->setGeometry(QRect(320, 140, 113, 23));
        reset_newpass = new QLineEdit(page_reset_password);
        reset_newpass->setObjectName("reset_newpass");
        reset_newpass->setGeometry(QRect(320, 180, 113, 23));
        label = new QLabel(page_reset_password);
        label->setObjectName("label");
        label->setGeometry(QRect(233, 140, 71, 20));
        label_2 = new QLabel(page_reset_password);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(233, 180, 71, 20));
        label_3 = new QLabel(page_reset_password);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(43, 85, 161, 211));
        label_4 = new QLabel(page_reset_password);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 210, 71, 20));
        reset_config_newpass = new QLineEdit(page_reset_password);
        reset_config_newpass->setObjectName("reset_config_newpass");
        reset_config_newpass->setGeometry(QRect(320, 210, 113, 23));
        stackedWidget->addWidget(page_reset_password);
        page_feedback = new QWidget();
        page_feedback->setObjectName("page_feedback");
        textEdit = new QTextEdit(page_feedback);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(40, 30, 461, 231));
        feedback_feedback = new QPushButton(page_feedback);
        feedback_feedback->setObjectName("feedback_feedback");
        feedback_feedback->setGeometry(QRect(80, 290, 81, 24));
        feedback_quit = new QPushButton(page_feedback);
        feedback_quit->setObjectName("feedback_quit");
        feedback_quit->setGeometry(QRect(330, 290, 81, 24));
        stackedWidget->addWidget(page_feedback);

        retranslateUi(User_menu);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(User_menu);
    } // setupUi

    void retranslateUi(QWidget *User_menu)
    {
        User_menu->setWindowTitle(QCoreApplication::translate("User_menu", "Form", nullptr));
        welcom_line->setText(QCoreApplication::translate("User_menu", "\346\254\242\350\277\216\357\274\214XXX", nullptr));
        button_signout->setText(QCoreApplication::translate("User_menu", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        button_feedback->setText(QCoreApplication::translate("User_menu", "\346\210\221\350\246\201\345\217\215\351\246\210", nullptr));
        button_borrow->setText(QCoreApplication::translate("User_menu", "\345\200\237\344\271\246", nullptr));
        button_return->setText(QCoreApplication::translate("User_menu", "\350\277\230\344\271\246", nullptr));
        button_serch->setText(QCoreApplication::translate("User_menu", "\346\237\245\350\257\242", nullptr));
        button_history->setText(QCoreApplication::translate("User_menu", "\345\200\237\351\230\205\345\216\206\345\217\262", nullptr));
        button_reset_password->setText(QCoreApplication::translate("User_menu", "\351\207\215\347\275\256\345\257\206\347\240\201", nullptr));
        borrow_hint->setText(QCoreApplication::translate("User_menu", "\350\257\267\350\276\223\345\205\245\344\271\246\347\261\215\345\224\257\344\270\200\347\264\242\345\274\225\347\240\201", nullptr));
        borrow_main_LOGO->setText(QCoreApplication::translate("User_menu", "logo", nullptr));
        borrow_borrow_button->setText(QCoreApplication::translate("User_menu", "\345\200\237\344\271\246", nullptr));
        borrow_quit_button->setText(QCoreApplication::translate("User_menu", "\351\200\200\345\207\272", nullptr));
        return_hint->setText(QCoreApplication::translate("User_menu", "TextLabel", nullptr));
        retur_LOGO->setText(QCoreApplication::translate("User_menu", "TextLabel", nullptr));
        return_return_button->setText(QCoreApplication::translate("User_menu", "\350\277\230\344\271\246", nullptr));
        return_quit->setText(QCoreApplication::translate("User_menu", "\350\277\224\345\233\236", nullptr));
        serch_by_name->setText(QCoreApplication::translate("User_menu", "\346\214\211\344\271\246\345\220\215\346\237\245\346\211\276", nullptr));
        serch_by_cata->setText(QCoreApplication::translate("User_menu", "\346\214\211\347\261\273\345\210\253\346\237\245\346\211\276", nullptr));
        label_please->setText(QCoreApplication::translate("User_menu", "\350\257\267\350\276\223\345\205\245", nullptr));
        serch_quit->setText(QCoreApplication::translate("User_menu", "\350\277\224\345\233\236", nullptr));
        history_lable->setText(QCoreApplication::translate("User_menu", "\347\202\271\345\207\273\346\237\245\350\257\242\345\220\216\346\230\276\347\244\272", nullptr));
        history_serch->setText(QCoreApplication::translate("User_menu", "\346\237\245\350\257\242", nullptr));
        history_quit->setText(QCoreApplication::translate("User_menu", "\350\277\224\345\233\236", nullptr));
        reset_reset->setText(QCoreApplication::translate("User_menu", "\347\241\256\350\256\244\351\207\215\347\275\256", nullptr));
        reset_quit->setText(QCoreApplication::translate("User_menu", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("User_menu", "\350\257\267\350\276\223\345\205\245\345\216\237\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("User_menu", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("User_menu", "LOGO", nullptr));
        label_4->setText(QCoreApplication::translate("User_menu", "\350\257\267\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201", nullptr));
        feedback_feedback->setText(QCoreApplication::translate("User_menu", "\347\241\256\350\256\244\346\217\220\344\272\244", nullptr));
        feedback_quit->setText(QCoreApplication::translate("User_menu", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_menu: public Ui_User_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MENU_H
