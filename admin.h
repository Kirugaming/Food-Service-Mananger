#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QTableView>
#include "mainwindow.h"
#include "initDatabase.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    db menu;
    ~Admin();



private slots:
    void on_customerButton_clicked();

    void on_addFoodButton_clicked();

    void on_refresh_clicked();

    void on_graphsButton_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
