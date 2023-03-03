#include "admin.h"
#include "ui_admin.h"
#include <QtSql>
#include <QDebug>
#include "initDatabase.h"

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);




    db menu;

    this->ui->menuTableView->setModel(menu.getEditableModel());
    this->ui->menuTableView->show();


}


Admin::~Admin()
{
    delete ui;
}

void Admin::on_customerButton_clicked()
{
    MainWindow *customerMode = new MainWindow();
    customerMode->show();
    this->close();
}

