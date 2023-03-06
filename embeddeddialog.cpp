// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "embeddeddialog.h"
#include "ui_embeddeddialog.h"

#include <QStyleFactory>

EmbeddedDialog::EmbeddedDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmbeddedDialog)
{
    ui->setupUi(this);



}

EmbeddedDialog::~EmbeddedDialog()
{
    delete ui;
}

void EmbeddedDialog::on_submitButton_clicked()
{
    /*
    if (!ui->foodNameEdit->text().isEmpty() || !ui->ingredientsEdit->toPlainText().isEmpty() || !ui->imgNameEdit->text().isEmpty()) {
        return;
    }
    */
    QSqlQuery q;

    q.prepare(R"(INSERT INTO Food(name, type, price, ingredients, imgName) VALUES (?, ?, ?, ?, ?))");
    q.addBindValue(ui->foodNameEdit->text());
    q.addBindValue(ui->typeEdit->currentIndex());
    q.addBindValue(ui->priceEdit->value());
    q.addBindValue(ui->ingredientsEdit->toPlainText());
    q.addBindValue(ui->imgNameEdit->text());

    if (!q.exec()) { // creates new row and null entries under specified columns (name, type, price, ingredients)
        qCritical() << q.lastError();
    }
    this->close();
}

