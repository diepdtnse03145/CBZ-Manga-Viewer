#ifndef CMV_PAGELISTMODEL_H
#define CMV_PAGELISTMODEL_H


#include <QAbstractListModel>

class CMV_PageListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    CMV_PageListModel(QObject* parent = 0);
    ~CMV_PageListModel() = default;

    enum PageListRole{
        NameRole  = Qt::UserRole + 1
    };

public slots:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

protected:
    QHash<int, QByteArray> roleNames() const;

};

#endif // CMV_PAGELISTMODEL_H
