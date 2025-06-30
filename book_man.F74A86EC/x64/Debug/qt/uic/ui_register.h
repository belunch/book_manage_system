/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *register_2;
    QPushButton *quit;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(608, 506);
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 110, 191, 211));
        label_2 = new QLabel(Form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 120, 54, 16));
        label_3 = new QLabel(Form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 150, 54, 16));
        label_4 = new QLabel(Form);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(320, 190, 54, 16));
        label_5 = new QLabel(Form);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(320, 220, 54, 16));
        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(410, 110, 113, 23));
        lineEdit_2 = new QLineEdit(Form);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(410, 150, 113, 23));
        lineEdit_3 = new QLineEdit(Form);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(410, 190, 113, 23));
        lineEdit_4 = new QLineEdit(Form);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(410, 220, 113, 23));
        register_2 = new QPushButton(Form);
        register_2->setObjectName("register_2");
        register_2->setGeometry(QRect(370, 260, 81, 24));
        quit = new QPushButton(Form);
        quit->setObjectName("quit");
        quit->setGeometry(QRect(370, 290, 81, 24));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        register_2->setText(QCoreApplication::translate("Form", "\346\263\250\345\206\214", nullptr));
        quit->setText(QCoreApplication::translate("Form", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
