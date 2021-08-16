#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSqlQuery;
class QSqlTableModel;

class LogInWindow;
class MainWindow : public QMainWindow
{
    Q_OBJECT
//public slots:

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_action_login_triggered();
    void on_action_logout_triggered();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_action_add_single_book_triggered();

    void on_action_add_many_books_triggered();

    void on_action_on_ascending_order_triggered();

    void on_action_on_decending_order_triggered();

    void on_pushButton_3_clicked();

    void on_action_add_card_triggered();

    void on_action_delete_card_triggered();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *_ui;
    QSqlTableModel *_model;
    bool _admin_on;
    int _admin_id;
    int _order ;
    int _order_ref;

    enum Display_Order {ASCENDING,DESCENDING};
};
#endif // MAINWINDOW_H
