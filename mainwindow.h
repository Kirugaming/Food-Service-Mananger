#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include "customrectitem.h"
#include <QKeyEvent>


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

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
