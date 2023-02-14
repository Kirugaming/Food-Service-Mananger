#include "mainwindow.h"
#include <iostream>
#include "./ui_mainwindow.h"


bool adminMode = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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


