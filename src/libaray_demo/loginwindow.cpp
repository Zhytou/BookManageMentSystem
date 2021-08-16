#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>

LogInWindow::LogInWindow(QWidget *parent, bool *admin_on, int *admin_id) :
    QMainWindow(parent),
    _ui(new Ui::LogInWindow),
    _admin_on(admin_on),
    _admin_id(admin_id)
{
    _ui->setupUi(this);
    _model = new QSqlTableModel();
    _model->setTable("manage");
}

LogInWindow::~LogInWindow()
{
    delete _ui;
}

void LogInWindow::on_pushButton_clicked()
{
    QString manager_id = _ui->lineEdit->text();
    QString password = _ui->lineEdit_2->text();
    QString query_statement = " select password"
                              " from manage"
                              " where manager_id = ";
    query_statement.append(manager_id);

    QSqlQuery query;
    query.exec(query_statement);

    if (query.size() == 0) {
        QMessageBox::about(this,"登录失败","用户ID错误");
    }
    else {
        query.first();
        if(query.value(0).toString() != password) {
            QMessageBox::critical(this,"登录失败","密码错误");
        }
        else {
            QMessageBox::about(this,"登录成功","登录成功");
            *_admin_on = true;
            *_admin_id = manager_id.toInt();
            this->close();
        }
    }
}

void LogInWindow::on_pushButton_2_clicked()
{
    this->close();
}
