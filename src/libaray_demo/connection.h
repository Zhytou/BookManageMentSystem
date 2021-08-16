#ifndef CONNECTION_H
#define CONNECTION_H
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
static bool createConnection () {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("db_3180105151");       //这里输入你的数据库名
    db.setUserName("root");
    db.setPassword("125216");   //这里输入你的密码
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("无法打开数据库"),"无法创建数据库连接！ ", QMessageBox::Cancel);
        return false;
    }
    return true;
}
#endif // CONNECTION_H
