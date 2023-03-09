#include "feedbackgraphs.h"
#include <QVector>
#include <iostream>
#include "BestFitLine.h"
FeedbackGraphs::FeedbackGraphs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FeedbackGraphs)
{
    ui->setupUi(this);
    db feedbackDatabase;
    qInfo() << feedbackDatabase.deletefbById(0);
    feedbackDatabase.addFeedback(3,3,4,1,5,3);
    feedbackDatabase.addFeedback(4,2,3,1,5,1);
    BESTFITLINE myLine;
    QVector<Feedback*> fb=feedbackDatabase.getByMonth("Mar");
    for(Feedback *obj:fb){
        myLine.addPoint(obj->getDay(),obj->getFood_Rating());
        FoodPoints->append(obj->getDay(),obj->getFood_Rating());
    }
    Food_Rating->append(7,1.5);
    Food_Rating->append(fb[fb.length()-1]->getDay(),myLine.slope()*1*fb[fb.length()-1]->getDay()+myLine.intercept());
    graphChart->legend()->hide();
    graphChart->addSeries(Food_Rating);
    FoodPoints->setName("Food_Rating");
    FoodPoints->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    FoodPoints->setMarkerSize(15.0);
    graphChart->addSeries(FoodPoints);
    graphChart->createDefaultAxes();
    graphChart->setTitle("Customer Feedback");
    QChartView *chartView=new QChartView(graphChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
    resize(600,800);
    show();
}

FeedbackGraphs::~FeedbackGraphs()
{
    delete ui;
}
void FeedbackGraphs::on_adminButton_clicked(){
    Admin *admin=new Admin();
    admin-> show();
    this->close();
}
