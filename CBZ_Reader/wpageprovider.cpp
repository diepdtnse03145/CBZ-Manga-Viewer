#include "wpageprovider.h"
#include <QtCore>
#include <QtGui>
#include "wpagepool.h"


WPageProvider::WPageProvider() :
    QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

WPageProvider::~WPageProvider()
{

}

QPixmap WPageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    qDebug()<<"*size"<<*size;
    qDebug()<<"requestedSize"<<requestedSize;
    return WPagePool::getInstance()->getPagePixmap(id);
}

