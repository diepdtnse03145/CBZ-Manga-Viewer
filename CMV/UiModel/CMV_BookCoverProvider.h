#ifndef CMV_BOOKCOVERPROVIDER_H
#define CMV_BOOKCOVERPROVIDER_H

#include <QQuickImageProvider>
#include <QSharedPointer>
#include "CMV_BookManager.h"

class CMV_BookCoverProvider : public QQuickImageProvider
{
public:
    CMV_BookCoverProvider(QSharedPointer<CMV_BookManager> manager);

    ~CMV_BookCoverProvider() = default;

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
private:
    QSharedPointer<CMV_BookManager> bookManager;
};

#endif // CMV_BOOKCOVERPROVIDER_H
