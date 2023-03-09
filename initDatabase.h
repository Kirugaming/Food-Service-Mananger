#ifndef INITDATABASE_H
#define INITDATABASE_H

#include <QtSql>
#include<QDebug>
#include "editablesqlmodel.h"
#include <ctime>
#include <iostream>
const auto FOOD_SQL = QLatin1String(R"(CREATE TABLE Food(id INTEGER PRIMARY KEY AUTOINCREMENT, name varchar(255), type INTEGER, price double, ingredients varchar(255), imgName VARCHAR(255)))"); // >.<
const auto INSERT_FOOD_SQL = QLatin1String(R"(INSERT INTO Food(name, type, price, ingredients, imgName) VALUES (?, ?, ?, ?, ?))");
const auto FEEDBACK_SQL = QLatin1String(R"(CREATE TABLE Feedback(id INTEGER PRIMARY KEY AUTOINCREMENT, Date varchar(255), Food_Rating int, Speed int, Freshness int, Cleanliness int, Ambiance int, Recommend int))");
const auto INSERT_FEEDBACK_SQL = QLatin1String(R"(INSERT INTO Feedback(Date, Food_Rating, Speed, Freshness, Cleanliness, Ambiance, Recommend) VALUES (?, ?, ?, ?, ?, ?, ?))");
class Food { // food model f
private:
    int id;
    QString name;
    int type;
    double price;
    QString ingredients;
    QString imgFileName;
public:
    enum FOODTYPE {
        Appetizer = 0,
        Drink = 1,
        Entree = 2,
        Dessert = 3
    };

    Food(int id, const QString name, int type, double price, const QString ingredients, QString imgFileName) {
        this->id = id;
        this->name = name;
        this->type = type;
        this->price = price;
        this->ingredients = ingredients;
        this->imgFileName = imgFileName;
    }

    int getId() {
        return this->id;
    }

    QString getName() {
        return this->name;
    }

    int getType() {
        return this->type;
    }

    double getPrice() {
        return this->price;
    }

    QString getIngredients() {
        return this->ingredients;
    }

    QString getImageName(){
        return this->imgFileName;
    }
};

class Feedback{
private:
    QString Date;
    int Day,Month,Food_Rating,Speed,Freshness,Clean,Ambiance,Recommend;
public:
    Feedback(QString Date,int Food_Rating,int Speed,int Freshness,int Clean,int Ambiance,int Recommend){
        this->Date=Date;
        this->Food_Rating=Food_Rating;
        this->Speed=Speed;
        this->Clean=Clean;
        this->Freshness=Freshness;
        this->Ambiance=Ambiance;
        this->Recommend=Recommend;
        this->Day=Date.split(" ")[1].toInt();

    }
    QString getDate(){
        return this->Date;
    }
    int getDay(){
        return this->Day;
    }
    int getMonth(){
        return this->Month;
    }
    int getFood_Rating(){
        return this->Food_Rating;
    }
    int getSpeed(){
        return this->Speed;
    }
    int getFreshness(){
        return this->Freshness;
    }
    int getClean(){
        return this->Clean;
    }
    int getAmbiance(){
        return this->Ambiance;
    }
    int getRecommend(){
        return this->Recommend;
    }
};
class db {
public:


    db() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("kiru");
        db.setDatabaseName("resturantDB.db");
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
            qInfo() << q.lastError() << "just ignore this"; // just ingore the error if it exists
    }

    EditableSqlModel * getEditableModel() {
        EditableSqlModel *model = new EditableSqlModel();
        model->setQuery("SELECT * FROM Food");
        return model;
    }

    // When adding strings to this method use QLatin1String("string example)
    void addFood (const QString &name, int type, double price, const QString &ingredients, const QString &imgName ) {
        QSqlQuery q;
        if (!q.prepare(INSERT_FOOD_SQL)) { // creates new row and null entries under specified columns (name, type, price, ingredients)
            qCritical() << q.lastError();
        } else {
            q.addBindValue(name); // fills null entry for name column
            q.addBindValue(type); // fills null entry for type column
            q.addBindValue(price); // fills null entry for price column
            q.addBindValue(ingredients); // fills null entry for ingredients column
            q.addBindValue(imgName);

            q.exec(); // run sql code
        }
    }
    // give food enum parameter or exact num equivalent to type
    QVector<Food*> getByType (int type) {
        QSqlQuery query(QString("SELECT * FROM Food WHERE type=%1").arg(type)); // formats type into sql string for database execution
        // returns table of food entries based off the type
        QVector<Food*> foodList;
        while(query.next()) { // go through each row in table
            // add new food to list with stuff from table
            foodList.append(new Food(query.value(0).toInt(), query.value(1).toString(), query.value(2).toInt(), query.value(3).toDouble(), query.value(4).toString(), query.value(5).toString()));
        }

        return foodList;

    }

    bool deleteById (int id) {
        QSqlQuery q;
        // delete row of id
        q.prepare("DELETE FROM Food WHERE id = ?");
        q.addBindValue(id); // replace null (?) with id
        q.exec(); // run sql code
        // check if delete
        q.prepare("SELECT * FROM Food WHERE id = ?");
        q.addBindValue(id); // replace null (?) with id

        if (!q.exec()) { // run sql code and see if there isn't a error
            qCritical() << q.lastError() << "::FAILED TO DELETE FROM DB::";
            return false;
        }
        return true;
    }
    bool deletefbById (int id) {
        QSqlQuery q;
        // delete row of id
        q.prepare("DELETE FROM Feedback WHERE id = ?");
        q.addBindValue(id); // replace null (?) with id
        q.exec(); // run sql code
        // check if delete
        q.prepare("SELECT * FROM Feedback WHERE id = ?");
        q.addBindValue(id); // replace null (?) with id

        if (!q.exec()) { // run sql code and see if there isn't a error
            qCritical() << q.lastError() << "::FAILED TO DELETE FROM DB::";
            return false;
        }
        return true;
    }
    QVector<Feedback*> getByMonth(QString month){
        QSqlQuery query(QString("SELECT * FROM Feedback"));
        QVector<Feedback*> FeedbackList;
        while(query.next()){
            Feedback* fb=new Feedback(query.value(1).toString(),query.value(2).toInt(),query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt(),query.value(7).toInt());
            std::cout << "Date:";
            std::cout << fb->getDate().left(3).toStdString();
            if(fb->getDate().left(3)==month){
                FeedbackList.append(fb);
            }

        }
        return FeedbackList;
    }

    void addFeedback( int Food_Rating, int Speed, int Freshness, int Cleanliness, int Ambiance, int Recommend){
        QSqlQuery feedback;
        if(!feedback.prepare(INSERT_FEEDBACK_SQL)){
            qCritical() << feedback.lastError();
        }
        else{
            time_t now=time(0);
            QString dt=ctime(&now);
            QString format;
            format.append(dt.mid(4,3));
            format.append(" "+dt.mid(8,2));
            format.append(" "+dt.right(5));
            feedback.addBindValue(format);
            feedback.addBindValue(Food_Rating);
            feedback.addBindValue(Speed);
            feedback.addBindValue(Freshness);
            feedback.addBindValue(Cleanliness);
            feedback.addBindValue(Ambiance);
            feedback.addBindValue(Recommend);

            feedback.exec();
        }
    }
    void clearFeedback(){
        QSqlQuery(QString("DELETE * FROM Feedback"));
    }

};









#endif // INITDATABASE_H
