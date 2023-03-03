#include "admin.h"
#include "ui_admin.h"
#include <QtSql>
#include <QSqlQuery>
#include "BestFitLine.h"
#include "initDatabase.h"
Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);


    //ui->foodTable->setModel();
    db fb;
    QVector <Feedback*> feedbackList=fb.getByMonth(Feedback::Feb);
    BESTFITLINE myLine;
    for(Feedback *feedBack:feedbackList){

    }
}

Admin::~Admin()
{
    delete ui;
}
