#ifndef CMV_PAGELISTPROVIDER_H
#define CMV_PAGELISTPROVIDER_H

#include <QQuickImageProvider>

class CMV_PageListProvider : public QQuickImageProvider
{
public:
    CMV_PageListProvider();

    ~CMV_PageListProvider() = default;

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

};

#endif // CMV_PAGELISTPROVIDER_H
