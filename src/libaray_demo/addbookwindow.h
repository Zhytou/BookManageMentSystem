#ifndef ADDBOOKWINDOW_H
#define ADDBOOKWINDOW_H

#include <QWidget>

namespace Ui {
class AddBookWindow;
}

class AddBookWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddBookWindow(QWidget *parent = nullptr);
    ~AddBookWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddBookWindow *_ui;
};

#endif // ADDBOOKWINDOW_H
