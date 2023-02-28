#include "admin.h"
#include "ui_admin.h"
#include <QtSql>

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    //QSqlQuery *query;
    //query->prepare("SELECT ")
    //ui->foodTable->setModel();
}

Admin::~Admin()
{
    delete ui;
}
