#include "CMV_BookCoverProvider.h"
#include <QtCore>
#include <QtGui>
#include "CMV_Log.h"
#include "CMV_DeviceInfo.h"
#include "CMV_BookManager.h"

CMV_BookCoverProvider::CMV_BookCoverProvider() :
QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap CMV_BookCoverProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    QElapsedTimer timer;
    timer.start();

    QPixmap pix(100,100);

    QPainter painter(&pix);
    auto img = CMV_BookManager::instance().cover(id);

    auto imgScaled = img.scaled(pix.size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QPoint imgPoint((100 - imgScaled.width()) / 2, (100 - imgScaled.height()) / 2);
    painter.fillRect(pix.rect(),QColor("white"));
    painter.drawImage(imgPoint,imgScaled);

    CMV_DEBUG<<"Elapsed:"<<timer.elapsed();

    return pix;
}


