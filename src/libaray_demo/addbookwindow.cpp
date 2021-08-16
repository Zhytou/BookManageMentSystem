#include "addbookwindow.h"
#include "ui_addbookwindow.h"

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

AddBookWindow::AddBookWindow(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::AddBookWindow)
{
    _ui->setupUi(this);
}

AddBookWindow::~AddBookWindow()
{
    delete _ui;
}

void AddBookWindow::on_pushButton_clicked()
{
    QString bno = _ui->lineEdit->text();
    QString type = _ui->lineEdit_2->text();
    QString title = _ui->lineEdit_3->text();
    QString press = _ui->lineEdit_4->text();
    QString year = _ui->lineEdit_5->text();
    QString author = _ui->lineEdit_6->text();
    QString price = _ui->lineEdit_7->text();

    if(bno.isEmpty() || type.isEmpty() || title.isEmpty() || press.isEmpty() || year.isEmpty() || price.isEmpty() || author.isEmpty()) {
        QMessageBox::critical(this,"入库错误","图书信息未填写完整");
        return ;
    }

    QSqlQuery query;
    query.prepare("select stock, total "
                  "from book "
                  "where bno=? and type=? and title=? and press=? and year=? and author=? and price=?");
    query.bindValue(0, bno.toInt());
    query.bindValue(1, type);
    query.bindValue(2, title);
    query.bindValue(3, press);
    query.bindValue(4, year);
    query.bindValue(5, author);
    query.bindValue(6, price);

    query.exec();

    // 输出调试信息
    qDebug() << "bno:" << bno << "type:" << type << "title:" << title;
    qDebug() << "press:" << press << "year:" << year << "author:" << author << "price:" << price;


    if (query.size() == 0) {
        qDebug() << "新书入库";
        query.prepare("insert into book(bno,type,title,author,year,press,price,stock,total) "
                      "values "
                      "(?, ?, ?, ?, ?, ?, ?, 1, 1)");
        query.bindValue(0, bno.toInt());
        query.bindValue(1, type);
        query.bindValue(2, title);
        query.bindValue(3, author);
        query.bindValue(4, year);
        query.bindValue(5, press);
        query.bindValue(6, price.toDouble());
    }
    else {
        qDebug() << "旧书入库";
        query.first();
        int stock = query.value(0).toInt();
        int total = query.value(1).toInt();
        query.prepare(QString("update book "
                      "set stock = ?, set total = ? "
                      "where bno = ").append(bno));
        query.bindValue(0, stock + 1);
        query.bindValue(1, total + 1);
    }
    if (query.exec()) {
        QMessageBox::about(this,"入库成功","入库成功");
        this->close();
    }
    else {
        QMessageBox::critical(this,"入库失败","信息格式错误,数据库写入失败");
    }
}

void AddBookWindow::on_pushButton_2_clicked()
{
    this->close();
}
