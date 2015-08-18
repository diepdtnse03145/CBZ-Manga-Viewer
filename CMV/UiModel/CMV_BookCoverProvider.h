#ifndef CMV_BOOKCOVERPROVIDER_H
#define CMV_BOOKCOVERPROVIDER_H

#include <QQuickImageProvider>

class CMV_BookCoverProvider : public QQuickImageProvider
{
public:
    CMV_BookCoverProvider();

    ~CMV_BookCoverProvider() = default;

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

};

#endif // CMV_BOOKCOVERPROVIDER_H
