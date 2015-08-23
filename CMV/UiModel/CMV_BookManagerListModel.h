#ifndef CMV_BOOKMANAGERLISTMODEL_H
#define CMV_BOOKMANAGERLISTMODEL_H

#include <QAbstractListModel>
#include "CMV_BookManager.h"

class CMV_BookManagerListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    CMV_BookManagerListModel(QSharedPointer<CMV_BookManager> manager,QObject* parent = 0);
    ~CMV_BookManagerListModel() = default;

    enum PageListRole{
        NameRole  = Qt::UserRole + 1,
        TypeRole,
        SizeRole,
        CoverRole,
        PathRole
    };

public slots:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

protected:
    QHash<int, QByteArray> roleNames() const;
    QSharedPointer<CMV_BookManager> bookManager;
};

#endif // CMV_BOOKMANAGERLISTMODEL_H
