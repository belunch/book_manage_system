/********************************************************************************
** Form generated from reading UI file 'manager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manager
{
public:
    QLabel *label;
    QPushButton *quit_button;
    QStackedWidget *stackedWidget;
    QWidget *page_menu;
    QPushButton *book_manage;
    QPushButton *reader_manage;
    QPushButton *change_password;
    QPushButton *data_manage;
    QPushButton *the_feedback;
    QWidget *page_book;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *book_serch_by_name;
    QPushButton *book_serch_by_cata;
    QPushButton *book_add;
    QPushButton *book_change;
    QPushButton *book_delete;
    QPushButton *book_quit;
    QWidget *page_reader;
    QTableWidget *tableWidget_2;
    QPushButton *reader_quit;
    QWidget *page_data;
    QPushButton *data_databackup;
    QPushButton *data_datarecover;
    QPushButton *data_quit;
    QWidget *page_feed_back;
    QPushButton *feedback_quit;
    QTableWidget *tableWidget_3;
    QWidget *page_change_pass;
    QLineEdit *old_pass_line;
    QLineEdit *new_pass_line;
    QLineEdit *conflig_new_pass_line;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *change_change;
    QPushButton *change_quit;
    QLabel *label_6;

    void setupUi(QWidget *Manager)
    {
        if (Manager->objectName().isEmpty())
            Manager->setObjectName("Manager");
        Manager->resize(742, 545);
        label = new QLabel(Manager);
        label->setObjectName("label");
        label->setGeometry(QRect(193, 30, 81, 20));
        quit_button = new QPushButton(Manager);
        quit_button->setObjectName("quit_button");
        quit_button->setGeometry(QRect(450, 30, 81, 24));
        stackedWidget = new QStackedWidget(Manager);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(29, 79, 591, 351));
        page_menu = new QWidget();
        page_menu->setObjectName("page_menu");
        book_manage = new QPushButton(page_menu);
        book_manage->setObjectName("book_manage");
        book_manage->setGeometry(QRect(80, 120, 81, 101));
        reader_manage = new QPushButton(page_menu);
        reader_manage->setObjectName("reader_manage");
        reader_manage->setGeometry(QRect(230, 120, 81, 111));
        change_password = new QPushButton(page_menu);
        change_password->setObjectName("change_password");
        change_password->setGeometry(QRect(420, 10, 81, 24));
        data_manage = new QPushButton(page_menu);
        data_manage->setObjectName("data_manage");
        data_manage->setGeometry(QRect(390, 120, 81, 111));
        the_feedback = new QPushButton(page_menu);
        the_feedback->setObjectName("the_feedback");
        the_feedback->setGeometry(QRect(490, 290, 101, 24));
        stackedWidget->addWidget(page_menu);
        page_book = new QWidget();
        page_book->setObjectName("page_book");
        tableWidget = new QTableWidget(page_book);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 90, 571, 261));
        lineEdit = new QLineEdit(page_book);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(100, 20, 113, 23));
        label_2 = new QLabel(page_book);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 20, 54, 16));
        book_serch_by_name = new QPushButton(page_book);
        book_serch_by_name->setObjectName("book_serch_by_name");
        book_serch_by_name->setGeometry(QRect(250, 20, 81, 24));
        book_serch_by_cata = new QPushButton(page_book);
        book_serch_by_cata->setObjectName("book_serch_by_cata");
        book_serch_by_cata->setGeometry(QRect(370, 20, 81, 24));
        book_add = new QPushButton(page_book);
        book_add->setObjectName("book_add");
        book_add->setGeometry(QRect(70, 60, 81, 24));
        book_change = new QPushButton(page_book);
        book_change->setObjectName("book_change");
        book_change->setGeometry(QRect(190, 60, 81, 24));
        book_delete = new QPushButton(page_book);
        book_delete->setObjectName("book_delete");
        book_delete->setGeometry(QRect(310, 60, 81, 24));
        book_quit = new QPushButton(page_book);
        book_quit->setObjectName("book_quit");
        book_quit->setGeometry(QRect(480, 20, 81, 24));
        stackedWidget->addWidget(page_book);
        page_reader = new QWidget();
        page_reader->setObjectName("page_reader");
        tableWidget_2 = new QTableWidget(page_reader);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(5, 61, 581, 281));
        reader_quit = new QPushButton(page_reader);
        reader_quit->setObjectName("reader_quit");
        reader_quit->setGeometry(QRect(470, 20, 81, 24));
        stackedWidget->addWidget(page_reader);
        page_data = new QWidget();
        page_data->setObjectName("page_data");
        data_databackup = new QPushButton(page_data);
        data_databackup->setObjectName("data_databackup");
        data_databackup->setGeometry(QRect(90, 73, 111, 141));
        data_datarecover = new QPushButton(page_data);
        data_datarecover->setObjectName("data_datarecover");
        data_datarecover->setGeometry(QRect(300, 73, 121, 141));
        data_quit = new QPushButton(page_data);
        data_quit->setObjectName("data_quit");
        data_quit->setGeometry(QRect(440, 20, 81, 24));
        stackedWidget->addWidget(page_data);
        page_feed_back = new QWidget();
        page_feed_back->setObjectName("page_feed_back");
        feedback_quit = new QPushButton(page_feed_back);
        feedback_quit->setObjectName("feedback_quit");
        feedback_quit->setGeometry(QRect(480, 290, 81, 24));
        tableWidget_3 = new QTableWidget(page_feed_back);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(20, 10, 551, 271));
        stackedWidget->addWidget(page_feed_back);
        page_change_pass = new QWidget();
        page_change_pass->setObjectName("page_change_pass");
        old_pass_line = new QLineEdit(page_change_pass);
        old_pass_line->setObjectName("old_pass_line");
        old_pass_line->setGeometry(QRect(380, 50, 113, 23));
        new_pass_line = new QLineEdit(page_change_pass);
        new_pass_line->setObjectName("new_pass_line");
        new_pass_line->setGeometry(QRect(380, 90, 113, 23));
        conflig_new_pass_line = new QLineEdit(page_change_pass);
        conflig_new_pass_line->setObjectName("conflig_new_pass_line");
        conflig_new_pass_line->setGeometry(QRect(380, 140, 113, 23));
        label_3 = new QLabel(page_change_pass);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 60, 54, 16));
        label_4 = new QLabel(page_change_pass);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(300, 90, 54, 16));
        label_5 = new QLabel(page_change_pass);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(283, 140, 71, 20));
        change_change = new QPushButton(page_change_pass);
        change_change->setObjectName("change_change");
        change_change->setGeometry(QRect(340, 190, 81, 24));
        change_quit = new QPushButton(page_change_pass);
        change_quit->setObjectName("change_quit");
        change_quit->setGeometry(QRect(340, 230, 81, 24));
        label_6 = new QLabel(page_change_pass);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 40, 141, 181));
        stackedWidget->addWidget(page_change_pass);

        retranslateUi(Manager);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Manager);
    } // setupUi

    void retranslateUi(QWidget *Manager)
    {
        Manager->setWindowTitle(QCoreApplication::translate("Manager", "Form", nullptr));
        label->setText(QCoreApplication::translate("Manager", "\346\254\242\350\277\216\343\200\201\347\256\241\347\220\206\345\221\230", nullptr));
        quit_button->setText(QCoreApplication::translate("Manager", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        book_manage->setText(QCoreApplication::translate("Manager", "\345\233\276\344\271\246\347\256\241\347\220\206", nullptr));
        reader_manage->setText(QCoreApplication::translate("Manager", "\350\257\273\350\200\205\344\277\241\346\201\257\344\270\200\350\247\210", nullptr));
        change_password->setText(QCoreApplication::translate("Manager", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        data_manage->setText(QCoreApplication::translate("Manager", "\347\263\273\347\273\237\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        the_feedback->setText(QCoreApplication::translate("Manager", "\346\237\245\347\234\213\345\217\215\351\246\210", nullptr));
        label_2->setText(QCoreApplication::translate("Manager", "\350\257\267\350\276\223\345\205\245", nullptr));
        book_serch_by_name->setText(QCoreApplication::translate("Manager", "\346\214\211\344\271\246\345\220\215\346\237\245\346\211\276", nullptr));
        book_serch_by_cata->setText(QCoreApplication::translate("Manager", "\346\214\211\347\261\273\345\210\253\346\237\245\346\211\276", nullptr));
        book_add->setText(QCoreApplication::translate("Manager", "\345\242\236\345\212\240", nullptr));
        book_change->setText(QCoreApplication::translate("Manager", "\344\277\256\346\224\271", nullptr));
        book_delete->setText(QCoreApplication::translate("Manager", "\345\210\240\351\231\244", nullptr));
        book_quit->setText(QCoreApplication::translate("Manager", "\350\277\224\345\233\236", nullptr));
        reader_quit->setText(QCoreApplication::translate("Manager", "\350\277\224\345\233\236", nullptr));
        data_databackup->setText(QCoreApplication::translate("Manager", "\346\225\260\346\215\256\345\244\207\344\273\275", nullptr));
        data_datarecover->setText(QCoreApplication::translate("Manager", "\346\225\260\346\215\256\346\201\242\345\244\215", nullptr));
        data_quit->setText(QCoreApplication::translate("Manager", "\350\277\224\345\233\236", nullptr));
        feedback_quit->setText(QCoreApplication::translate("Manager", "\350\277\224\345\233\236", nullptr));
        label_3->setText(QCoreApplication::translate("Manager", "\345\216\237\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("Manager", "\346\226\260\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("Manager", "\350\257\267\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201", nullptr));
        change_change->setText(QCoreApplication::translate("Manager", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        change_quit->setText(QCoreApplication::translate("Manager", "\351\200\200\345\207\272", nullptr));
        label_6->setText(QCoreApplication::translate("Manager", "LOGO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manager: public Ui_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_H
