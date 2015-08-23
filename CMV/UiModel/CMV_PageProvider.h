#ifndef WPAGEPROVIDER_H
#define WPAGEPROVIDER_H

#include <QQuickImageProvider>
#include "CMV_CurrentBook.h"

class CMV_PageProvider : public QQuickImageProvider
{
public:
    CMV_PageProvider(QSharedPointer<CMV_CurrentBook> cr);

    ~CMV_PageProvider() = default;

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
private:
    QSharedPointer<CMV_CurrentBook> currentBook;
};

#endif // WPAGEPROVIDER_H
