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

    QString getCurrentPage();
    QImage getPageData(const QString& id);

    void next();

    CMV_CbzBook book;
    int index;
};

#endif // CMV_CURRENTBOOK_H
