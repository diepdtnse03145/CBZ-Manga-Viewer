#ifndef CMV_PAGELISTMODEL_H
#define CMV_PAGELISTMODEL_H


#include <QAbstractListModel>
#include "CMV_CurrentBook.h"

class CMV_PageListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    CMV_PageListModel(QSharedPointer<CMV_CurrentBook>cr,QObject* parent = 0);
    ~CMV_PageListModel() = default;

    enum PageListRole{
        NameRole  = Qt::UserRole + 1
    };

public slots:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QSharedPointer<CMV_CurrentBook> currentBook;

};

#endif // CMV_PAGELISTMODEL_H
