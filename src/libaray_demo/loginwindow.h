#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LogInWindow;
}

class QSqlTableModel;
class LogInWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
public:
    explicit LogInWindow(QWidget *parent = nullptr, bool *admin_on = nullptr, int *admin_id = nullptr);
    ~LogInWindow();

private:
    Ui::LogInWindow *_ui;
    QSqlTableModel *_model;
    bool* _admin_on;
    int* _admin_id;
};

#endif // LOGINWINDOW_H
