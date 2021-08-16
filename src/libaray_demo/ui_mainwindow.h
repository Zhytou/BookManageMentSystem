/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_login;
    QAction *action_logout;
    QAction *action_add_single_book;
    QAction *action_add_many_books;
    QAction *action_on_ascending_order;
    QAction *action_on_decending_order;
    QAction *action_add_card;
    QAction *action_delete_card;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_10;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_8;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_14;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QDateEdit *dateEdit;
    QPushButton *pushButton_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_6;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_11;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_5;
    QLabel *label_7;
    QLabel *label_5;
    QWidget *widget_5;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *lineEdit_6;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 546);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 450));
        MainWindow->setMaximumSize(QSize(850, 600));
        action_login = new QAction(MainWindow);
        action_login->setObjectName(QStringLiteral("action_login"));
        action_logout = new QAction(MainWindow);
        action_logout->setObjectName(QStringLiteral("action_logout"));
        action_add_single_book = new QAction(MainWindow);
        action_add_single_book->setObjectName(QStringLiteral("action_add_single_book"));
        action_add_many_books = new QAction(MainWindow);
        action_add_many_books->setObjectName(QStringLiteral("action_add_many_books"));
        action_on_ascending_order = new QAction(MainWindow);
        action_on_ascending_order->setObjectName(QStringLiteral("action_on_ascending_order"));
        action_on_decending_order = new QAction(MainWindow);
        action_on_decending_order->setObjectName(QStringLiteral("action_on_decending_order"));
        action_add_card = new QAction(MainWindow);
        action_add_card->setObjectName(QStringLiteral("action_add_card"));
        action_delete_card = new QAction(MainWindow);
        action_delete_card->setObjectName(QStringLiteral("action_delete_card"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(tableView);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lineEdit_10 = new QLineEdit(widget_2);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout_3->addWidget(lineEdit_10, 4, 1, 1, 1);

        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 3, 1, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_13, 2, 0, 1, 1);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 0, 1, 1, 1);

        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 5, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_12, 2, 2, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_14, 2, 5, 1, 1);

        lineEdit_9 = new QLineEdit(widget_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout_3->addWidget(lineEdit_9, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 4, 4, 1, 1);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 2, 4, 1, 1);

        dateEdit = new QDateEdit(widget_2);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout_3->addWidget(dateEdit, 6, 1, 1, 1);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy3);
        pushButton_4->setMinimumSize(QSize(0, 60));
        pushButton_4->setMaximumSize(QSize(16777215, 80));

        gridLayout_3->addWidget(pushButton_4, 6, 4, 1, 1);


        gridLayout_4->addWidget(widget_2, 1, 6, 1, 1);

        widget = new QWidget(widget_4);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        gridLayout = new QGridLayout(widget_6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_7 = new QLineEdit(widget_6);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy2.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy2);
        lineEdit_7->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lineEdit_7, 0, 4, 1, 1);

        lineEdit_11 = new QLineEdit(widget_6);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lineEdit_11, 2, 5, 1, 1);

        label = new QLabel(widget_6);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget_6);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget_6);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy4);
        lineEdit_2->setMinimumSize(QSize(80, 21));
        lineEdit_2->setMaximumSize(QSize(300, 21));

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        lineEdit = new QLineEdit(widget_6);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(80, 0));
        lineEdit->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_8 = new QLineEdit(widget_6);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setMaximumSize(QSize(80, 21));

        gridLayout->addWidget(lineEdit_8, 0, 5, 1, 1);

        lineEdit_5 = new QLineEdit(widget_6);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lineEdit_5, 2, 4, 1, 1);

        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 3, 1, 1);

        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 3, 1, 1);


        verticalLayout_2->addWidget(widget_6);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout_2 = new QGridLayout(widget_5);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit_3 = new QLineEdit(widget_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 0, 2, 1, 1);

        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 2);

        lineEdit_6 = new QLineEdit(widget_5);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        sizePolicy4.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(lineEdit_6, 2, 2, 1, 1);

        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(widget_5);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 1, 2, 1, 1);


        verticalLayout_2->addWidget(widget_5);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setAutoDefault(false);

        verticalLayout_2->addWidget(pushButton);


        gridLayout_4->addWidget(widget, 1, 5, 1, 1);


        verticalLayout_3->addWidget(widget_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action_login);
        menu->addAction(action_logout);
        menu->addSeparator();
        menu->addAction(action_add_single_book);
        menu->addAction(action_add_many_books);
        menu->addSeparator();
        menu->addAction(action_add_card);
        menu->addAction(action_delete_card);
        menu_3->addAction(action_on_ascending_order);
        menu_3->addAction(action_on_decending_order);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\233\276\344\271\246\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        action_login->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", Q_NULLPTR));
        action_logout->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\351\200\200\345\207\272", Q_NULLPTR));
        action_add_single_book->setText(QApplication::translate("MainWindow", "\345\215\225\346\234\254\345\205\245\345\272\223", Q_NULLPTR));
        action_add_many_books->setText(QApplication::translate("MainWindow", "\346\211\271\351\207\217\345\205\245\345\272\223", Q_NULLPTR));
        action_on_ascending_order->setText(QApplication::translate("MainWindow", "\345\215\207\345\272\217\346\230\276\347\244\272", Q_NULLPTR));
        action_on_decending_order->setText(QApplication::translate("MainWindow", "\351\231\215\345\272\217\346\230\276\347\244\272", Q_NULLPTR));
        action_add_card->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\200\237\344\271\246\345\215\241", Q_NULLPTR));
        action_delete_card->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\200\237\344\271\246\345\215\241", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\344\271\246\345\217\267", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246\350\257\201\345\217\267", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\351\242\204\350\256\241\345\275\222\350\277\230\346\227\266\351\227\264", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\350\277\230\344\271\246", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\200\237\344\271\246", Q_NULLPTR));
        dateEdit->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-M-d", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\200\237\344\271\246\350\256\260\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\344\271\246\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\347\261\273\345\210\253", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\344\273\267\346\240\274", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\345\271\264\344\273\275", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\344\275\234\350\200\205", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\345\207\272\347\211\210\347\244\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\344\271\246\345\220\215", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
