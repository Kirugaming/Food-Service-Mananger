#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QTableView>
#include "mainwindow.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();



private slots:
    void on_customerButton_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
