// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QtSql>
#include <QDebug>

#include "editablesqlmodel.h"

EditableSqlModel::EditableSqlModel(QObject *parent)
    : QSqlQueryModel(parent)
{
}

//! [0]
Qt::ItemFlags EditableSqlModel::flags(
        const QModelIndex &index) const
{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    if (index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5)
        flags |= Qt::ItemIsEditable;
    return flags;
}
//! [0]

//! [1]
bool EditableSqlModel::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
    if (index.column() < 1 || index.column() > 5)
        return false;

    QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
    int id = data(primaryKeyIndex).toInt();

    //clear();

    bool ok;
    if (index.column() == 1) {
        ok = setName(id, value.toString());
    } else if (index.column() == 2) {
        ok = setType(id, value.toInt());
    }else if (index.column() == 3) {
        ok = setPrice(id, value.toDouble());
    }else if (index.column() == 4) {
        ok = setIngredients(id, value.toString());
    }else if (index.column() == 5) {
        ok = setImgName(id, value.toString());
    }
    refresh();
    return ok;
}
//! [2]

void EditableSqlModel::refresh()
{
    setQuery("select * from Food");
    /*
    setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
    */
}

//! [1]
bool EditableSqlModel::setName(int foodId, const QString &name)
{
    QSqlQuery query;
    query.prepare("update Food set name = ? where id = ?");
    query.addBindValue(name);
    query.addBindValue(foodId);

    return query.exec();
}
//! [2]
bool EditableSqlModel::setType(int foodId, const int foodType)
{
    QSqlQuery query;
    query.prepare("update Food set type = ? where id = ?");
    query.addBindValue(foodType);
    query.addBindValue(foodId);

    return query.exec();
}
//! [3]
bool EditableSqlModel::setPrice(int foodId, const double price)
{
    QSqlQuery query;
    query.prepare("update Food set price = ? where id = ?");
    query.addBindValue(price);
    query.addBindValue(foodId);

    return query.exec();
}
//! [4]
bool EditableSqlModel::setIngredients(int foodId, const QString ingredients)
{
    QSqlQuery query;
    query.prepare("update Food set ingredients = ? where id = ?");
    query.addBindValue(ingredients);
    query.addBindValue(foodId);

    return query.exec();
}
//! [5]
bool EditableSqlModel::setImgName(int foodId, const QString imgName)
{
    QSqlQuery query;
    query.prepare("update Food set imgName = ? where id = ?");
    query.addBindValue(imgName);
    query.addBindValue(foodId);

    return query.exec();
}

