/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Log_in
{
public:
    QLabel *label_LOGO;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_icon;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_user;
    QLineEdit *line_username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QCheckBox *manager_check;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_login;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_quit;

    void setupUi(QWidget *Log_in)
    {
        if (Log_in->objectName().isEmpty())
            Log_in->setObjectName("Log_in");
        Log_in->resize(649, 518);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        Log_in->setWindowIcon(icon);
        label_LOGO = new QLabel(Log_in);
        label_LOGO->setObjectName("label_LOGO");
        label_LOGO->setGeometry(QRect(20, 30, 200, 200));
        label_LOGO->setMinimumSize(QSize(200, 200));
        label_LOGO->setMaximumSize(QSize(200, 200));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(16);
        label_LOGO->setFont(font);
        label_LOGO->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(Log_in);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(250, 30, 216, 184));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_icon = new QLabel(layoutWidget);
        label_icon->setObjectName("label_icon");
        label_icon->setMinimumSize(QSize(40, 40));
        label_icon->setMaximumSize(QSize(40, 40));

        horizontalLayout_4->addWidget(label_icon);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_user = new QLabel(layoutWidget);
        label_user->setObjectName("label_user");
        label_user->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(label_user);

        line_username = new QLineEdit(layoutWidget);
        line_username->setObjectName("line_username");

        horizontalLayout_3->addWidget(line_username);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_password = new QLabel(layoutWidget);
        label_password->setObjectName("label_password");
        label_password->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_password);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");

        horizontalLayout_2->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_2);

        manager_check = new QCheckBox(layoutWidget);
        manager_check->setObjectName("manager_check");

        verticalLayout->addWidget(manager_check);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_login = new QPushButton(layoutWidget);
        pushButton_login->setObjectName("pushButton_login");

        horizontalLayout->addWidget(pushButton_login);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_quit = new QPushButton(layoutWidget);
        pushButton_quit->setObjectName("pushButton_quit");

        horizontalLayout->addWidget(pushButton_quit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Log_in);

        QMetaObject::connectSlotsByName(Log_in);
    } // setupUi

    void retranslateUi(QWidget *Log_in)
    {
        Log_in->setWindowTitle(QCoreApplication::translate("Log_in", "\347\231\273\345\275\225", nullptr));
        label_LOGO->setText(QCoreApplication::translate("Log_in", "\350\277\231\345\272\224\350\257\245\346\230\257\344\270\252LOGO\347\232\204", nullptr));
        label_icon->setText(QCoreApplication::translate("Log_in", "\344\272\272\345\244\264\345\233\276", nullptr));
        label_user->setText(QCoreApplication::translate("Log_in", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_password->setText(QCoreApplication::translate("Log_in", "\345\257\206\347\240\201\357\274\232", nullptr));
        manager_check->setText(QCoreApplication::translate("Log_in", "\346\210\221\346\230\257\347\256\241\347\220\206\345\221\230", nullptr));
        pushButton_login->setText(QCoreApplication::translate("Log_in", "\347\231\273\345\275\225", nullptr));
        pushButton_quit->setText(QCoreApplication::translate("Log_in", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Log_in: public Ui_Log_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
