#include "CMV_PageListModel.h"
#include "CMV_CurrentBook.h"

CMV_PageListModel::CMV_PageListModel(QSharedPointer<CMV_CurrentBook> cr, QObject *parent) :
    QAbstractListModel(parent),
    currentBook{cr}
{

}

QHash<int, QByteArray> CMV_PageListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "pageName";
    return roles;
}

int CMV_PageListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return currentBook->size();
}

QVariant CMV_PageListModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= currentBook->size())
        return QVariant();

    switch (role){
    case CMV_PageListModel::NameRole:
        return QStringLiteral("image://pageList/%1").arg(currentBook->pageName(index.row()));
    }

    return QVariant();
}

