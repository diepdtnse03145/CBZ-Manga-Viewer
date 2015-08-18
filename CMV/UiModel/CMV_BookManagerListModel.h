#ifndef CMV_BOOKMANAGERLISTMODEL_H
#define CMV_BOOKMANAGERLISTMODEL_H

#include <QAbstractListModel>

class CMV_BookManagerListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    CMV_BookManagerListModel(QObject* parent = 0);
    ~CMV_BookManagerListModel() = default;

    enum PageListRole{
        NameRole  = Qt::UserRole + 1,
        TypeRole,
        SizeRole,
        CoverRole
    };

public slots:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

protected:
    QHash<int, QByteArray> roleNames() const;

};

#endif // CMV_BOOKMANAGERLISTMODEL_H
