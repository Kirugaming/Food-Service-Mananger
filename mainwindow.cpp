#include "mainwindow.h"
#include <iostream>
using namespace std;

#include "./ui_mainwindow.h"
#include "initDatabase.h"


bool adminMode = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db foodDatabase;
    foodDatabase.addFood(QLatin1String("hotdog"), 5.99, QLatin1String("Bun, Meat, Lettuce, Cheese, Tomato, Bacon, Onion"));
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
    ui->stackedWidget->setCurrentIndex(2);
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



void MainWindow::on_listWidget_2_itemEntered(QListWidgetItem *item)
{
    std::cout << "Item added\n";
    QStringList myStringList;
    for (int i = 0; i < 5; ++i)
        myStringList.append(item->text());
    std::cout << &myStringList;
    std::cout << "\n";
}


void MainWindow::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    std::cout << "Item clicked\n";
}

