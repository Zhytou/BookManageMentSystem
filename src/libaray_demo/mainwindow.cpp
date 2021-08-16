#include "mainwindow.h"
#include "loginwindow.h"
#include "addbookwindow.h"
#include "cardwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>

extern QString connnectionName;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _admin_on(false),
    _admin_id(-1),
    _order(ASCENDING),
    _order_ref(0)
{
    _ui->setupUi(this);
    _model = new QSqlTableModel(this);
    _model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _ui->tableView->setModel(_model);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

//查询按钮
void MainWindow::on_pushButton_clicked()
{
    _model->setTable("book");

    QString bno = _ui->lineEdit->text();
    QString type = _ui->lineEdit_2->text();
    QString title = _ui->lineEdit_3->text();
    QString press = _ui->lineEdit_4->text();
    QString min_year = _ui->lineEdit_5->text();
    QString max_year = _ui->lineEdit_11->text();
    QString author = _ui->lineEdit_6->text();
    QString min_price = _ui->lineEdit_7->text();
    QString max_price = _ui->lineEdit_8->text();
    /*调试信息
    qDebug() << "bno:" << bno << " type:" << type << " title:" << title << " press:" << press ;
    qDebug() << "year:" << year << " author:" << author;
    qDebug() << "min_price:" << min_price << " max_price:" << max_price;
    qDebug() << "min_year:" << min_year << "max_year" << max_year;
    */
    QString query_cond ;

    if (!bno.isEmpty()) {
        if(!query_cond.isEmpty()) {
            query_cond.append(" and ");
        }
        query_cond.append(QString(" bno = ").append(bno));
    }

    if (!type.isEmpty()) {
        if(!query_cond.isEmpty()) {
            query_cond.append(" and ");
        }
        query_cond.append(QString(" type = '%1' ").arg(type));
    }

    if (!title.isEmpty()) {
        if(!query_cond.isEmpty()) {
            query_cond.append(" and ");
        }
        query_cond.append(QString(" title = '%1' ").arg(title));
    }

    if (!press.isEmpty()) {
        if(!query_cond.isEmpty()) {
            query_cond.append(" and ");
        }
        query_cond.append(QString(" press = '%1' ").arg(press));
    }

    if (!min_year.isEmpty()) {
        if(!query_cond.isEmpty()) {
            query_cond.append(" and ");
        }
        query_cond.append(QString(" year >= ").append(min_year));
    }

    if (!max_year.isEmpty()) {
        if(!query_cond.isEmpty()) {
            query_cond.append(" and ");
        }
        query_cond.append(QString(" year <= ").append(max_year));
    }

    if (!author.isEmpty()) {
        if(!query_cond.isEmpty()) {
            query_cond.append(" and ");
        }
        query_cond.append(QString("author = '%1' ").arg(author));
    }

    if (min_price.size() != 0) {
        if(!query_cond.isEmpty()) {
            query_cond.append(" and ");
        }
        query_cond.append(QString(" price >= ").append(min_price));
    }

    if (max_price.size() != 0) {
        if(!query_cond.isEmpty()) {
            query_cond.append(" and ");
        }
        query_cond.append(QString(" price <= ").append(max_price));
    }
    //输出调试信息
    //qDebug() << query_cond ;
    _model->setFilter(query_cond);

    if(_order == ASCENDING) {
        _model->setSort(_order_ref,Qt::AscendingOrder);
    }
    else {
        _model->setSort(_order_ref,Qt::DescendingOrder);
    }
    _model->select();
    for (int i = 0; i < _model->columnCount(); i++)
        _ui->tableView->resizeColumnToContents(i);
}

//借书按钮
void MainWindow::on_pushButton_2_clicked()
{
    //从MainWindow获取信息
    QString cno = _ui->lineEdit_9->text();
    QString bno = _ui->lineEdit_10->text();
    QString return_date = _ui->dateEdit->text();
    QString borrow_date = QDateTime::currentDateTime().toString("yyyy-MM-dd");

    if (cno.isEmpty() || bno.isEmpty()) {
        QMessageBox::critical(this,"借书错误","借书证号和书号均不能为空");
    }
    else {
        if (!_admin_on) {
            QMessageBox::critical(this,"借书失败","当前无管理员登录");
        }
        else {
            //查询stock是否大于0
            QSqlQuery query;
            query.exec(QString("select stock "
                               "from book "
                               "where bno = ").append(bno));
            if (query.size() == 0) {
                QMessageBox::critical(this,"借书失败","不存在此书号");
            }
            else {
                query.first();
                int stock = query.value(0).toInt();

                if ( stock> 0) {
                    /*
                    //利用数据库事务，保证原子性
                    //获取当前连接上的数据库
                    QSqlDatabase db = QSqlDatabase::database();
                    //开启事务
                    if (db.transaction()) {
                        //更新book表中记录
                        query.prepare(QString("update book "
                                              "set stock = ? "
                                              "where bno = ").append(bno));
                        query.addBindValue(stock-1);
                        query.exec();

                        //添加borrow表中记录
                        query.prepare(QString("insert into borrow(cno,bno,borrow_date,return_date,manager_id) "
                                              "values "
                                              "(:bno,:cno,:borrow_date,:return_date,:manager_id)"));
                        //调试信息
                        //qDebug() << "borrow_date:" << borrow_date << "return date:" << return_date ;
                        //qDebug() << "bno:" << bno << "cno:" << cno << "manager_id:" << _admin_id ;

                        query.bindValue(0, bno.toInt());
                        query.bindValue(1, cno.toInt());
                        query.bindValue(2, borrow_date);
                        query.bindValue(3, return_date);
                        query.bindValue(4, _admin_id);
                        query.exec();

                        //提交事务
                        if (!db.commit()) {
                            db.rollback();
                            QMessageBox::critical(this,"借书失败","信息填写格式错误，数据库写入失败");
                        }
                        else{
                            QMessageBox::about(this,"借书成功","借书成功");
                        }
                    }
                    else {
                        qDebug() << "不支持事务吗？" << '\n';
                    }
                    */
                    //更新book表中记录
                    query.prepare(QString("update book "
                                          "set stock = ? "
                                          "where bno = ").append(bno));
                    query.addBindValue(stock-1);
                    query.exec();

                    //添加borrow表中记录
                    query.prepare(QString("insert into borrow(cno,bno,borrow_date,return_date,manager_id) "
                                          "values "
                                          "(:cno,:bno,:borrow_date,:return_date,:manager_id)"));
                    //调试信息
                    //qDebug() << "borrow_date:" << borrow_date << "return date:" << return_date ;
                    //qDebug() << "bno:" << bno << "cno:" << cno << "manager_id:" << _admin_id ;

                    query.bindValue(0, cno.toInt());
                    query.bindValue(1, bno.toInt());
                    query.bindValue(2, borrow_date);
                    query.bindValue(3, return_date);
                    query.bindValue(4, _admin_id);
                    query.exec();
                    QMessageBox::about(this,"借书成功","借书成功");
                }
                else {
                    query.exec(QString("select return_date "
                                       "from borrow "
                                       "where bno = ").append(bno));
                    query.first();
                    QString return_date = query.value(0).toString();
                    QMessageBox::about(this,"借书失败",QString("库存不足,最早还书日期").append(return_date));
                }
            }
        }
    }
}

//还书按钮
void MainWindow::on_pushButton_3_clicked()
{
    //从MainWindow获取信息
    QString cno = _ui->lineEdit_9->text();
    QString bno = _ui->lineEdit_10->text();
    //QString return_date = _ui->dateEdit->text();
    //QString borrow_date = QDateTime::currentDateTime().toString("yyyy-MM-dd");

    if (cno.isEmpty() || bno.isEmpty()) {
        QMessageBox::critical(this,"还书错误","借书证号和书号均不能为空");
    }
    else {
        if (!_admin_on) {
            QMessageBox::critical(this,"还书失败","当前无管理员登录");
        }
        else {
            QSqlQuery query;
            query.exec(QString("select stock "
                               "from book "
                               "where bno = ").append(bno));
            if (query.size() == 0) {
                QMessageBox::critical(this,"还书失败","不存在此书号");
            }
            else {
                query.first();
                int stock = query.value(0).toInt();
                /*
                 *事务不知道为什么执行不了，transaction之前都能返回ture，后来失败
                //利用数据库事务，保证原子性
                //获取当前连接上的数据库
                QSqlDatabase db = QSqlDatabase::database();
                //开启事务
                if (db.transaction()) {

                    //提交事务
                    if (!db.commit()) {
                        db.rollback();
                        QMessageBox::critical(this,"还书失败","信息填写格式错误，数据库删除失败");
                    }
                    else{
                    }
                }
                */
                //更新book表中记录
                query.prepare(QString("update book "
                                      "set stock = ? "
                                      "where bno = ").append(bno));
                query.addBindValue(stock+1);
                query.exec();

                //删除borrow表中记录
                query.prepare(QString("delete from borrow "
                                      "where bno = :bno and cno = :cno "
                                      "order by borrow_date "
                                      "limit 1"));
                query.bindValue(0, bno);
                query.bindValue(1, cno);
                query.exec();
                QMessageBox::about(this,"还书成功","还书成功");
            }
        }
    }
}

//查询借书记录
void MainWindow::on_pushButton_4_clicked()
{
    _model->setTable("borrow");
    QString cno = _ui->lineEdit_9->text();
    if (cno.isEmpty()) {
        QMessageBox::critical(this,"查询错误","借书证号不能为空");
    }
    else {
        _model->setFilter(QString("cno = ").append(cno));
        _model->select();
        for (int i = 0; i < _model->columnCount(); i++)
            _ui->tableView->resizeColumnToContents(i);
    }
}

void MainWindow::on_action_login_triggered()
{
    LogInWindow *w = new LogInWindow(this,&_admin_on,&_admin_id);
    w->setWindowTitle("管理员登录界面");
    w->show();
    w->setAttribute(Qt::WA_DeleteOnClose);//避免内存泄露
}

void MainWindow::on_action_logout_triggered()
{
    if (!_admin_on) {
        QMessageBox::critical(this,"管理员","当前无管理员登录");
        return ;
    }
    _admin_on = false;
    QMessageBox::about(this,"管理员","退出成功");
}


void MainWindow::on_action_add_single_book_triggered()
{
    if (!_admin_on) {
        QMessageBox::critical(this,"非管理员","不能进行单本入库操作");
        return ;
    }
    AddBookWindow *w = new AddBookWindow;
    w->setWindowTitle("单本入库");
    w->show();
    w->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::on_action_add_many_books_triggered()
{
    if (!_admin_on) {
        QMessageBox::critical(this,"非管理员","不能进行批量入库操作");
        return ;
    }
    QString pathname = QFileDialog::getOpenFileName(this,"批量入库","../");
    qDebug() << pathname ;

    QFile file(pathname);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "入库错误", "无法打开指定文件");
    }
    else {
        qDebug() << "打开文件成功";
        QSqlDatabase db = QSqlDatabase::database();
        QSqlQuery query;
        while (!file.atEnd()) {

            QString data(file.readLine());//此时data包含换行符
            data = data.trimmed();//除去data中的换行符

            qDebug() << data;
            if (data.isEmpty())
                continue;
            QStringList data_entries = data.split(',');

            query.exec(QString("select stock,total "
                               "from book "
                               "where bno = ").append(data_entries.first()));

            if (query.size() == 0) {
                //新书入库
                qDebug() << "新书入库" ;
                int bno = data_entries[0].toInt();
                QString type = data_entries[1];
                QString title = data_entries[2];
                QString author = data_entries[3];
                QString year = data_entries[4];
                QString press = data_entries[5];
                double price = data_entries[6].toDouble();
                int total = data_entries[7].toInt();
                int stock = total;
                query.prepare(QString("insert into book(bno, type, title, author, year, press, price, total, stock) "
                                      "values "
                                      "(:bno, :type, :title, :author, :year, :press, :price, :total, :stock)"));
                query.bindValue(0, bno);
                query.bindValue(1, type);
                query.bindValue(2, title);
                query.bindValue(3, author);
                query.bindValue(4, year);
                query.bindValue(5, press);
                query.bindValue(6, price);
                query.bindValue(7, total);
                query.bindValue(8, stock);
                query.exec();
            }
            else {
                //更新stock和total
                qDebug() << "旧书入库" ;
                query.first();
                int stock = query.value(0).toInt();
                int total = query.value(1).toInt();
                qDebug() << "stock = " << stock << " total=" << total << '\n';
                query.prepare(QString("update book "
                                      "set total = ? , stock = ? "
                                      "where bno = ").append(data_entries.first()));
                query.bindValue(0, total+1);
                query.bindValue(1, stock+1);

            }
        }
        if (query.exec()) {
            QMessageBox::about(this,"入库成功","批量入库成功");
        }
        else {
            QMessageBox::critical(this,"入库失败","入库文件中有记录格式错误");
        }
    }
    file.close();
}

void MainWindow::on_action_on_ascending_order_triggered()
{
    _order = ASCENDING;
    int curCol = _ui->tableView->currentIndex().column();
    if (curCol == -1) {
        QMessageBox::critical(this,"设置失败","请先选中一列");
    }
    else {
        _order_ref = curCol;
        QMessageBox::about(this,"设置成功","再次点击查询来更新升序显示");
    }

}

void MainWindow::on_action_on_decending_order_triggered()
{
    _order = DESCENDING;
    int curCol = _ui->tableView->currentIndex().column();
    if (curCol == -1) {
        QMessageBox::critical(this,"设置失败","请先选中一列");
    }
    else {
        _order_ref = curCol;
        QMessageBox::about(this,"设置成功","再次点击查询来更新降序显示");
    }
}

void MainWindow::on_action_add_card_triggered()
{
    if (!_admin_on) {
        QMessageBox::critical(this,"添加借书证错误","非管理员不能进行添加借书证操作");
        return ;
    }
    CardWindow *w = new CardWindow;
    w->setWindowTitle("借书证管理");
    w->show();
    w->setAttribute(Qt::WA_DeleteOnClose);;
}

void MainWindow::on_action_delete_card_triggered()
{
    if (!_admin_on) {
        QMessageBox::critical(this,"删除借书证错误","非管理员不能进行删除借书证操作");
        return ;
    }
    CardWindow *w = new CardWindow;
    w->setWindowTitle("借书证管理");
    w->show();
    w->setAttribute(Qt::WA_DeleteOnClose);;
}

