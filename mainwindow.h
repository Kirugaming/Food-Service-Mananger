#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include "customrectitem.h"
#include <QKeyEvent>
#include"admin.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_appetizers_btn_clicked();

    void on_desserts_btn_clicked();

    void on_drinks_btn_clicked();

    void on_entrees_btn_clicked();

    void on_adminButton_clicked();

    void on_adminButton_toggled(bool checked);

    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_appetizersWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_dessertsWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_drinksWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_entreesWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_entreesWidget_itemEntered(QListWidgetItem *item);

    void on_finishOrderButton_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
