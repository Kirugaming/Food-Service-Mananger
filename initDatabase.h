#ifndef INITDATABASE_H
#define INITDATABASE_H

#include <QtSql>
#include<QDebug>

const auto FOOD_SQL = QLatin1String(R"(CREATE TABLE Food(id INTEGER PRIMARY KEY AUTOINCREMENT, name varchar(255), price double, ingredients varchar(255)))"); // >.<
const auto INSERT_FOOD_SQL = QLatin1String(R"(INSERT INTO Food(name, price, ingredients) VALUES (?, ?, ?))");
const auto FEEDBACK_SQL = QLatin1String(R"(CREATE TABLE Feedback(id INTEGER PRIMARY KEY AUTOINCREMENT, Date varchar(255), Food_Rating int, Speed int, Freshness int, Cleanliness int, Ambiance int, Recommend int))");
const auto INSERT_FEEDBACK_SQL = QLatin1String(R"(INSERT INTO Feedback(Date, Food_Rating, Speed, Freshness, Cleanliness, Ambiance, Recommend) VALUES (?, ?, ?, ?, ?, ?, ?))");
class db {
public:

    db() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("kiru");
        db.setDatabaseName("resturantDB");
        db.setUserName("kiru"); // Database settings
        db.setPassword("kiru");
        bool isDbOk = db.open();
        if (!isDbOk) {
            qCritical() << "DATABASE FAILED TO INIT";
        }

        QSqlQuery q;
        if (!q.exec(FOOD_SQL)) // create table if not exist
            qInfo() << q.lastError(); // just ingore the error if it exists
        if (!q.exec(FEEDBACK_SQL)) // create table if not exist
            qInfo() << q.lastError();
    }

    // When adding strings to this method use QLatin1String("string example)
    void addFood (const QString &name, double price, const QString &ingredients ) {
        QSqlQuery q;
        if (!q.prepare(INSERT_FOOD_SQL)) { // creates new row and null entries under specified columns (name, price, ingredients)
            qCritical() << q.lastError();
        } else {
            q.addBindValue(name); // fills null entry for name column
            q.addBindValue(price); // fills null entry for price column
            q.addBindValue(ingredients); // fills null entry for ingredients column

            q.exec(); // run sql code
        }
    }
    void addFeedback(const QString &date, int &Food_Rating, int &Speed, int &Freshness, int &Cleanliness, int &Ambiance, int &Recommend){
        QSqlQuery feedback;
        if(!feedback.prepare(INSERT_FEEDBACK_SQL)){
            qCritical() << feedback.lastError();
        }
        else{
            feedback.addBindValue(date);
            feedback.addBindValue(Food_Rating);
            feedback.addBindValue(Speed);
            feedback.addBindValue(Freshness);
            feedback.addBindValue(Cleanliness);
            feedback.addBindValue(Ambiance);
            feedback.addBindValue(Recommend);

            feedback.exec();
        }
    }

};









#endif // INITDATABASE_H

