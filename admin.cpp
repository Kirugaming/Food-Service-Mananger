#include "admin.h"
#include "ui_admin.h"
#include <QtSql>
#include <QDebug>

#include "embeddeddialog.h"

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);




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


void Admin::on_addFoodButton_clicked()
{
    EmbeddedDialog *addFood = new EmbeddedDialog;
    addFood->show();
}


void Admin::on_refresh_clicked()
{
    ui->menuTableView->setModel(menu.getEditableModel());
    ui->menuTableView->show();
    qInfo() << "refreshed";
}

