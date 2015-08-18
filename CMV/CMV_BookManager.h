#ifndef CMV_BOOKMANAGER_H
#define CMV_BOOKMANAGER_H

#include <QList>
#include "CMV_CbzBook.h"

class QString;

class CMV_BookManager
{
public:
    CMV_BookManager();

    static inline CMV_BookManager& instance()
    {
         static CMV_BookManager i;
         return i;
    }

    int size(int index);

    QString name(int index);
    QImage cover(QString name);
    QString type(int index);
    inline int size(){
        return bookList.size();
    }

private:
    QList<CMV_CbzBook> bookList;

};

#endif // CMV_BOOKMANAGER_H
