#include "CMV_PageListModel.h"
#include "CMV_CurrentBook.h"

CMV_PageListModel::CMV_PageListModel(QObject *parent) : QAbstractListModel(parent)
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
    return CMV_CurrentBook::instance().size();
}

QVariant CMV_PageListModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= CMV_CurrentBook::instance().size())
        return QVariant();

    switch (role){
    case CMV_PageListModel::NameRole:
        return QStringLiteral("image://pageList/%1").arg(CMV_CurrentBook::instance().pageName(index.row()));
    }

    return QVariant();
}

