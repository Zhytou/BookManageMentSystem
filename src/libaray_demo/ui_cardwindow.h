/********************************************************************************
** Form generated from reading UI file 'cardwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDWINDOW_H
#define UI_CARDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *CardWindow)
    {
        if (CardWindow->objectName().isEmpty())
            CardWindow->setObjectName(QStringLiteral("CardWindow"));
        CardWindow->resize(333, 211);
        horizontalLayout = new QHBoxLayout(CardWindow);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(CardWindow);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 3, 1, 1, 1);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(CardWindow);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addWidget(widget_2);


        retranslateUi(CardWindow);

        QMetaObject::connectSlotsByName(CardWindow);
    } // setupUi

    void retranslateUi(QWidget *CardWindow)
    {
        CardWindow->setWindowTitle(QApplication::translate("CardWindow", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("CardWindow", "\345\200\237\344\271\246\350\257\201\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("CardWindow", "\345\200\237\344\271\246\350\257\201\347\261\273\345\210\253", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("CardWindow", "\350\200\201\345\270\210", Q_NULLPTR)
         << QApplication::translate("CardWindow", "\345\255\246\347\224\237", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("CardWindow", "\346\214\201\350\257\201\344\272\272\345\247\223\345\220\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("CardWindow", "\346\214\201\350\257\201\344\272\272\344\270\223\344\270\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CardWindow", "\346\267\273\345\212\240\345\200\237\344\271\246\350\257\201", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("CardWindow", "\345\210\240\351\231\244\345\200\237\344\271\246\350\257\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CardWindow: public Ui_CardWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDWINDOW_H
