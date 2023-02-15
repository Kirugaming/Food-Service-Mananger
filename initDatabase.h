#ifndef INITDATABASE_H
#define INITDATABASE_H

#include <QtSql>
#include<QDebug>

const auto FOOD_SQL = QLatin1String(R"(CREATE TABLE Food(id INTEGER PRIMARY KEY AUTOINCREMENT, name varchar(255), type INTEGER, price double, ingredients varchar(255)))"); // >.<
const auto INSERT_FOOD_SQL = QLatin1String(R"(INSERT INTO Food(name, type, price, ingredients) VALUES (?, ?, ?, ?))");

class Food { // food model f
private:
    int id;
    QString name;
    int type;
    double price;
    QString ingredients;
public:

    Food(int id, const QString name, int type, double price, const QString ingredients) {
        this->id = id;
        this->name = name;
        this->type = type;
        this->price = price;
        this->ingredients = ingredients;
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
};

class db {
public:
    enum FOODTYPE {
        Appetizer = 0,
        Drink = 1,
        Entree = 2,
        Dessert = 3
    };

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
            qInfo() << q.lastError() << "just ignore this"; // just ingore the error if it exists
    }

    // When adding strings to this method use QLatin1String("string example)
    void addFood (const QString &name, int type, double price, const QString &ingredients ) {
        QSqlQuery q;
        if (!q.prepare(INSERT_FOOD_SQL)) { // creates new row and null entries under specified columns (name, type, price, ingredients)
            qCritical() << q.lastError();
        } else {
            q.addBindValue(name); // fills null entry for name column
            q.addBindValue(type); // fills null entry for type column
            q.addBindValue(price); // fills null entry for price column
            q.addBindValue(ingredients); // fills null entry for ingredients column

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
            foodList.append(new Food(query.value(0).toInt(), query.value(1).toString(), query.value(2).toInt(), query.value(3).toDouble(), query.value(4).toString()));
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
            qCritical() << q.lastError();
            return false;
        }
        return true;
    }


private:

};







#endif // INITDATABASE_H

