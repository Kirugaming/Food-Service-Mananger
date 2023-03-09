#ifndef FEEDBACKGRAPHS_H
#define FEEDBACKGRAPHS_H

#include <QMainWindow>
#include "admin.h"
#include <QtCharts>
#include "ui_feedbackgraphs.h"
#include "initDatabase.h"

namespace Ui {
class FeedbackGraphs;
}

class FeedbackGraphs : public QMainWindow
{
    Q_OBJECT


public:
    QLineSeries *Food_Rating=new QLineSeries();
    QScatterSeries *FoodPoints=new QScatterSeries();
    QLineSeries *Speed=new QLineSeries();
    QLineSeries *Fresh=new QLineSeries();
    QLineSeries *Clean=new QLineSeries();
    QLineSeries *Recommend=new QLineSeries();
    QChart *graphChart= new QChart();
    explicit FeedbackGraphs(QWidget *parent = nullptr);
    ~FeedbackGraphs();

private slots:
    void on_adminButton_clicked();

private:
    Ui::FeedbackGraphs *ui;
};


#endif // FEEDBACKGRAPHS_H
