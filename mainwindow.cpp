#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "initDatabase.h"
#include "BestFitLine.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db foodDatabase;
    foodDatabase.addFood(QLatin1String("hotdog"), 5.99, QLatin1String("Bun, Meat, Lettuce, Cheese, Tomato, Bacon, Onion"));
    int five=5;
    foodDatabase.addFeedback(QLatin1String("2/15/2023"),five,five,five,five,five,five);
    BESTFITLINE myLine;
    myLine.addPoint(1.0,5.0);
    myLine.addPoint(2.0,4.0);
    myLine.addPoint(3.0,2.0);
    myLine.addPoint(4.0,2.0);
    myLine.addPoint(5.0,1.0);
    myLine.addPoint(6.0,3.0);
    cout<< myLine.slope();
}

MainWindow::~MainWindow()
{
    delete ui;
}

