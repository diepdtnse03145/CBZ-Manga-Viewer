#ifndef CMV_CBZBOOK_H
#define CMV_CBZBOOK_H

#include "CMV_Book.h"
#include <private/qzipreader_p.h>
#include <QSharedPointer>
#include <QFileInfo>
#include <QImage>

class CMV_CbzBook : public CMV_Book
{
public:
    CMV_CbzBook(const QString& name);
    ~CMV_CbzBook();

    QString name() const;
    int size() const;
    QImage pageAt(const QString &id) const;
    QString pageName(int index) const;
    QImage cover() const;

private:
    QSharedPointer<QZipReader> zip;
    QFileInfo bookInfo;
    QImage bookCover;
};

#endif // CMV_CBZBOOK_H
