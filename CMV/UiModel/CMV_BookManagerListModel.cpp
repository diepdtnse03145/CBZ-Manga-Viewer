#include "CMV_BookManagerListModel.h"
#include "CMV_BookManager.h"

CMV_BookManagerListModel::CMV_BookManagerListModel(QSharedPointer<CMV_BookManager> manager,QObject *parent) :
    QAbstractListModel(parent),
    bookManager{manager}
{

}

QHash<int, QByteArray> CMV_BookManagerListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[CoverRole] = "cover";
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";
    roles[PathRole] = "path";
    return roles;
}

int CMV_BookManagerListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return bookManager->size();
}

QVariant CMV_BookManagerListModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= bookManager->size())
        return QVariant();

    switch (role){
    case CMV_BookManagerListModel::CoverRole:
        return QStringLiteral("image://bookCover/%1").arg(index.row()); break;
    case CMV_BookManagerListModel::NameRole:
        return bookManager->name(index.row()); break;
    case CMV_BookManagerListModel::TypeRole:
        return bookManager->type(index.row()); break;
    case CMV_BookManagerListModel::SizeRole:
        return bookManager->size(index.row()); break;
    case CMV_BookManagerListModel::PathRole:
        return bookManager->path(index.row()); break;
    }

    return QVariant();
}

