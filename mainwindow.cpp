#include "mainwindow.h"
#include <iostream>
using namespace std;

#include <vector>
#include "./ui_mainwindow.h"
#include "initDatabase.h"
#include <QListWidget>
#include <QListWidgetItem>


bool adminMode = false;
std::vector<string> order;


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db foodDatabase;
    foodDatabase.addFood(QLatin1String("burger"), Food::Entree, 5.99, QLatin1String("Bun, Meat, Lettuce, Cheese, Tomato, Bacon, Onion"), QString("burger.png"));

    QVector<Food*> foods = foodDatabase.getByType(Food::Entree);

    for (Food *food : foods) {
        qInfo() << food->getName();
        QString name = food->getName();
        QListWidgetItem item1 = *new QListWidgetItem(name);

        item1.setData(1, food->getImageName());
        item1.setData(2, food->getName());
        item1.setData(3, food->getId());
        item1.setData(4, food->getIngredients());
        item1.setData(5, food->getPrice());
        item1.setData(6, food->getType());
        QIcon icon("images/" + food->getImageName());
        item1.setIcon(icon);
        QFont font("Roboto Thin", 10);
        item1.setFont(font);
        if(food->getType() == 0) {
            ui->appetizersWidget->insertItem(0,item1.clone());
        }
        if(food->getType() == 1) {
            ui->drinksWidget->insertItem(0,item1.clone());
        }
        if(food->getType() == 2) {
            ui->entreesWidget->insertItem(0,item1.clone());
        }
        if(food->getType() == 3) {
            ui->dessertsWidget->insertItem(0,item1.clone());
        }
    }
    qInfo() << foodDatabase.deleteById(14);


}

MainWindow::~MainWindow()
{
    setWindowTitle("Drag and drop from QListWidget v1");
    resize(350,250);


    delete ui;
}

void MainWindow::on_appetizers_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_drinks_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_entrees_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_desserts_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_adminButton_clicked()
{
    //ui->stackedWidget->setCurrentIndex(2);
    adminWindow->show();
    this->close();
}

void MainWindow::on_adminButton_toggled(bool checked)
{
    if(checked) {
        adminMode = true;

    }
    else {
        adminMode = false;
    }
}


void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
    std::cout << "NEW ITEM REMOVED" << endl << flush;
    // order.erase(std::remove(order.begin(), order.end(), item->text().toStdString()), order.end());
    int row = ui->listWidget_2->row(item);
    order.erase( order.begin() + row);
    delete item;
    std::cout << "Current Order: ";
    for (string i: order)
        std::cout << i << ' ';
    std::cout << "\n" << flush;


}

void MainWindow::on_appetizersWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->listWidget_2->addItem(item->clone());
    std::cout << "NEW ITEM ENTERED" << endl << flush;
    std::cout << item->text().toStdString() << endl;
    order.push_back(item->text().toStdString());
    std::cout << "Current Order: ";
    for (string i: order)
        std::cout << i << ' ';
    std::cout << "\n" << flush;
}


void MainWindow::on_dessertsWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->listWidget_2->addItem(item->clone());
    std::cout << "NEW ITEM ENTERED" << endl << flush;
    std::cout << item->text().toStdString() << endl;
    order.push_back(item->text().toStdString());
    std::cout << "Current Order: ";
    for (string i: order)
        std::cout << i << ' ';
    std::cout << "\n" << flush;
}


void MainWindow::on_drinksWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->listWidget_2->addItem(item->clone());
    std::cout << "NEW ITEM ENTERED" << endl << flush;
    std::cout << item->text().toStdString() << endl;
    order.push_back(item->text().toStdString());
    std::cout << "Current Order: ";
    for (string i: order)
        std::cout << i << ' ';
    std::cout << "\n" << flush;
}


void MainWindow::on_entreesWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->listWidget_2->addItem(item->clone());
    std::cout << "NEW ITEM ENTERED" << endl << flush;
    std::cout << item->text().toStdString() << endl;
    order.push_back(item->text().toStdString());
    std::cout << "Current Order: ";
    for (string i: order)
        std::cout << i << ' ';
    std::cout << "\n" << flush;
}

