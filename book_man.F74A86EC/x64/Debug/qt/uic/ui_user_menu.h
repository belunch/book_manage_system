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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user_menu
{
public:
    QLabel *welcom_line;
    QPushButton *button_signout;
    QPushButton *button_reset_password;
    QPushButton *button_feedback;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *button_borrow;
    QPushButton *button_return;
    QPushButton *button_serch;
    QPushButton *button_history;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(667, 504);
        welcom_line = new QLabel(Form);
        welcom_line->setObjectName("welcom_line");
        welcom_line->setGeometry(QRect(150, 20, 240, 40));
        welcom_line->setMinimumSize(QSize(240, 40));
        welcom_line->setMaximumSize(QSize(240, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(16);
        welcom_line->setFont(font);
        welcom_line->setAlignment(Qt::AlignmentFlag::AlignCenter);
        button_signout = new QPushButton(Form);
        button_signout->setObjectName("button_signout");
        button_signout->setGeometry(QRect(420, 30, 81, 24));
        button_reset_password = new QPushButton(Form);
        button_reset_password->setObjectName("button_reset_password");
        button_reset_password->setGeometry(QRect(430, 350, 81, 24));
        button_feedback = new QPushButton(Form);
        button_feedback->setObjectName("button_feedback");
        button_feedback->setGeometry(QRect(430, 390, 81, 24));
        widget = new QWidget(Form);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 80, 345, 345));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(75);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(10, 10, 10, 10);
        button_borrow = new QPushButton(widget);
        button_borrow->setObjectName("button_borrow");
        button_borrow->setMinimumSize(QSize(125, 125));
        button_borrow->setMaximumSize(QSize(125, 125));

        gridLayout->addWidget(button_borrow, 0, 0, 1, 1);

        button_return = new QPushButton(widget);
        button_return->setObjectName("button_return");
        button_return->setMinimumSize(QSize(125, 125));
        button_return->setMaximumSize(QSize(125, 125));

        gridLayout->addWidget(button_return, 0, 1, 1, 1);

        button_serch = new QPushButton(widget);
        button_serch->setObjectName("button_serch");
        button_serch->setMinimumSize(QSize(125, 125));
        button_serch->setMaximumSize(QSize(125, 125));

        gridLayout->addWidget(button_serch, 1, 0, 1, 1);

        button_history = new QPushButton(widget);
        button_history->setObjectName("button_history");
        button_history->setMinimumSize(QSize(125, 125));
        button_history->setMaximumSize(QSize(125, 125));

        gridLayout->addWidget(button_history, 1, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        welcom_line->setText(QCoreApplication::translate("Form", "\346\254\242\350\277\216\357\274\214XXX", nullptr));
        button_signout->setText(QCoreApplication::translate("Form", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        button_reset_password->setText(QCoreApplication::translate("Form", "\351\207\215\347\275\256\345\257\206\347\240\201", nullptr));
        button_feedback->setText(QCoreApplication::translate("Form", "\346\210\221\350\246\201\345\217\215\351\246\210", nullptr));
        button_borrow->setText(QCoreApplication::translate("Form", "\345\200\237\344\271\246", nullptr));
        button_return->setText(QCoreApplication::translate("Form", "\350\277\230\344\271\246", nullptr));
        button_serch->setText(QCoreApplication::translate("Form", "\346\237\245\350\257\242", nullptr));
        button_history->setText(QCoreApplication::translate("Form", "\345\200\237\351\230\205\345\216\206\345\217\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ui_user_menu: public Ui_user_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MENU_H
