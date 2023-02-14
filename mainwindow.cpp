#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "initDatabase.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db foodDatabase;
    foodDatabase.addFood(QLatin1String("hotdog"), db::Entree, 5.99, QLatin1String("Bun, Meat, Lettuce, Cheese, Tomato, Bacon, Onion"));

    QVector<Food*> foods = foodDatabase.getByType(db::Entree);

    for (Food *food : foods) {
        qInfo() << food->getName();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

