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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
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
    QWidget *page;

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
        stackedWidget->setGeometry(QRect(40, 60, 521, 381));
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
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);

        retranslateUi(User_menu);

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
    } // retranslateUi

};

namespace Ui {
    class User_menu: public Ui_User_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MENU_H
