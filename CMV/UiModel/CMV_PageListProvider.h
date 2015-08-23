#ifndef CMV_PAGELISTPROVIDER_H
#define CMV_PAGELISTPROVIDER_H

#include <QQuickImageProvider>
#include "CMV_CurrentBook.h"

class CMV_PageListProvider : public QQuickImageProvider
{
public:
    CMV_PageListProvider(QSharedPointer<CMV_CurrentBook> cr);

    ~CMV_PageListProvider() = default;

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
private:
    QSharedPointer<CMV_CurrentBook> currentBook;

};

#endif // CMV_PAGELISTPROVIDER_H
