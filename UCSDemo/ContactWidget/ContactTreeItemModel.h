﻿#ifndef CONTACT_TREE_ITEM_MODEL_H
#define CONTACT_TREE_ITEM_MODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include "ContactDefine.h"

class TreeItem;

class ContactTreeItemModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit ContactTreeItemModel(QObject *parent = 0);
    ~ContactTreeItemModel();

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // Fetch data dynamically:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // for a editable model
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    // custom functionality:
    void importJSON(QString jsonFile);

    void refreshModel();
    void setOrganizationList(ContactList *organizationList);

private:
    void setupModelData(TreeItem *parent);
    TreeItem *item(TreeItem *item, ContactItem contract);

private:
    ContactList *m_organizationList;
    QList<ContactItem> m_privateList;
//    QMap<QString, QList> m_listMap;
    TreeItem *m_pRootItem;
};

#endif // CONTACT_TREE_ITEM_MODEL_H
