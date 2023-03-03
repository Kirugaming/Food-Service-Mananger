// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef EDITABLESQLMODEL_H
#define EDITABLESQLMODEL_H

#include <QSqlQueryModel>

class EditableSqlModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    EditableSqlModel(QObject *parent = nullptr);

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

private:
    bool setName(int foodId, const QString &name);
    bool setType(int foodId, const int foodType);
    bool setPrice(int foodId, const double price);
    bool setIngredients(int foodId, const QString ingredients);
    bool setImgName(int foodId, const QString imgName);
    void refresh();
};

#endif
