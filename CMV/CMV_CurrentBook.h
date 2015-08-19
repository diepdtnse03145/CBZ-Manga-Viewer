#ifndef CMV_CURRENTBOOK_H
#define CMV_CURRENTBOOK_H

#include "CMV_CbzBook.h"

class CMV_CurrentBook
{
public:
    CMV_CurrentBook();
    ~CMV_CurrentBook();

    static inline CMV_CurrentBook& instance()
    {
         static CMV_CurrentBook i;
         return i;
    }

    QString getCurrentPage() const;
    QImage getPageData(const QString& id) const;

    void next();
    void previous();
    void gotoPage(int page);
    inline QString pageName(int index) const;
    inline int size() const;

    void setBook(QString path);

private:
    CMV_CbzBook* book;
    int index;
};

QString CMV_CurrentBook::pageName(int index) const
{
    return book->pageName(index);
}

int CMV_CurrentBook::size() const
{
    return book->size();
}


#endif // CMV_CURRENTBOOK_H
