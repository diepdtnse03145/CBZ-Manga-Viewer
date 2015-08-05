#ifndef WPAGEPROVIDER_H
#define WPAGEPROVIDER_H

#include <QQuickImageProvider>

#include "wpagepool.h"

class WPageProvider : public QQuickImageProvider
{
public:
    WPageProvider();

    ~WPageProvider();

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

private:
};

#endif // WPAGEPROVIDER_H
