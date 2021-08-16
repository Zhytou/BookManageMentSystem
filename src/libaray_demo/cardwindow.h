#ifndef CARDWINDOW_H
#define CARDWINDOW_H

#include <QWidget>

namespace Ui {
class CardWindow;
}

class CardWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CardWindow(QWidget *parent = nullptr);
    ~CardWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CardWindow *ui;
};

#endif // CARDWINDOW_H
