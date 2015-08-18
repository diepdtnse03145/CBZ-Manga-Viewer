#include "CMV_BookManagerListModel.h"
#include "CMV_BookManager.h"

CMV_BookManagerListModel::CMV_BookManagerListModel(QObject *parent) : QAbstractListModel(parent)
{

}

QHash<int, QByteArray> CMV_BookManagerListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[CoverRole] = "cover";
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";
    return roles;
}

int CMV_BookManagerListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return CMV_BookManager::instance().size();
}

QVariant CMV_BookManagerListModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= CMV_BookManager::instance().size())
        return QVariant();

    switch (role){
    case CMV_BookManagerListModel::CoverRole:
        return QStringLiteral("image://bookCover/%1").arg(index.row()); break;
    case CMV_BookManagerListModel::NameRole:
        return CMV_BookManager::instance().name(index.row()); break;
    case CMV_BookManagerListModel::TypeRole:
        return CMV_BookManager::instance().type(index.row()); break;
    case CMV_BookManagerListModel::SizeRole:
        return CMV_BookManager::instance().size(index.row()); break;
    }

    return QVariant();
}

