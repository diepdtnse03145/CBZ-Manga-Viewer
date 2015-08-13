#ifndef WPAGEPROVIDER_H
#define WPAGEPROVIDER_H

#include <QQuickImageProvider>

class CMV_PageProvider : public QQuickImageProvider
{
public:
    CMV_PageProvider();

    ~CMV_PageProvider() = default;

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
};

#endif // WPAGEPROVIDER_H
