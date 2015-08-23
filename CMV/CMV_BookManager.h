#ifndef CMV_BOOKMANAGER_H
#define CMV_BOOKMANAGER_H

#include <QList>
#include "CMV_Book.h"
#include <QSharedPointer>

class QString;

class CMV_BookManager
{
public:
    CMV_BookManager();

    int size(int index);

    QString name(int index);
    QImage cover(QString name);
    QString type(int index);
    QString path(int index);

    QSharedPointer<CMV_Book> lastRead();

    inline int size(){
        return bookList.size();
    }

private:
    QList<QSharedPointer<CMV_Book>> bookList;

};

#endif // CMV_BOOKMANAGER_H
