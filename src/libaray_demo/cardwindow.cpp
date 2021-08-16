#include "cardwindow.h"
#include "ui_cardwindow.h"

#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

CardWindow::CardWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardWindow)
{
    ui->setupUi(this);
}

CardWindow::~CardWindow()
{
    delete ui;
}

void CardWindow::on_pushButton_clicked()
{

    QString cno = ui->lineEdit->text();
    QString type;
    int type_index = ui->comboBox->currentIndex();
    QString owner_name = ui->lineEdit_2->text();
    QString owner_dept = ui->lineEdit_3->text();
    qDebug() << cno << ' ' << type_index << ' ' << owner_name << ' ' << owner_dept;

    if (type_index == 0) {
        type = 'T';
    }
    else {
        type = 'S';
    }
    if (cno.isEmpty() || owner_name.isEmpty() || owner_dept.isEmpty()) {
        QMessageBox::critical(this,"添加借书证错误","借书证号、借书证类型、持有人姓名及专业均不能为空");
    }
    else {
        QSqlQuery query;
        query.exec(QString("select * "
                           "from card "
                           "where cno = ").append(cno));
        if (query.size() != 0) {
            QMessageBox::critical(this,"添加借书证失败","已存在此借书证号");
        }
        else {
            query.prepare(QString("insert into card(cno,name,department,type) "
                                  "values"
                                  "(:cno,:name,:dept,:type)"));
            query.bindValue(0, cno.toInt());
            query.bindValue(1, owner_name);
            query.bindValue(2, owner_dept);
            query.bindValue(3, type);
            query.exec();
            QMessageBox::about(this,"添加借书卡成功","添加借书卡成功");
        }
    }
}

void CardWindow::on_pushButton_2_clicked()
{
    QString cno = ui->lineEdit->text();
    qDebug() << cno;

    if (cno.isEmpty()) {
        QMessageBox::critical(this,"删除借书证错误","借书证号不能为空");
    }
    else {
        QSqlQuery query;
        query.exec(QString("select * "
                           "from card "
                           "where cno = ").append(cno));
        if (query.size() == 0) {
            QMessageBox::critical(this,"删除借书证失败","不存在此借书证号");
        }
        else {
            query.exec(QString("delete from card "
                               "where cno = ").append(cno));
            QMessageBox::about(this,"删除借书卡成功","删除借书卡成功");
        }
    }
}
