#ifndef INITDATABASE_H
#define INITDATABASE_H

#include <QtSql>
#include<QDebug>

const auto FOOD_SQL = QLatin1String(R"(CREATE TABLE Food(id INTEGER PRIMARY KEY AUTOINCREMENT, name varchar(255), price double, ingredients varchar(255)))"); // >.<
const auto INSERT_FOOD_SQL = QLatin1String(R"(INSERT INTO Food(name, price, ingredients) VALUES (?, ?, ?))");

class db {
public:

    db() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("kiru");
        db.setDatabaseName("resturantDB");
        db.setUserName("kiru"); // creating database
        db.setPassword("kiru");
        bool isDbOk = db.open();
        if (!isDbOk) {
            qCritical() << "DATABASE FAILED TO INIT";
        }

        QSqlQuery q;
        if (!q.exec(FOOD_SQL))
            qInfo() << q.lastError();
    }

    void addFood (const QString &name, double price, const QString &ingredients ) {
        QSqlQuery q;
        if (!q.prepare(INSERT_FOOD_SQL)) {
            qCritical() << q.lastError();
        } else {
            q.addBindValue(name);
            q.addBindValue(price);
            q.addBindValue(ingredients);

            q.exec();
        }
    }
};









#endif // INITDATABASE_H

