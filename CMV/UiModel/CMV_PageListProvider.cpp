#include "CMV_PageListProvider.h"
#include <QtCore>
#include <QtGui>
#include "CMV_Log.h"
#include "CMV_DeviceInfo.h"
#include "CMV_CurrentBook.h"

CMV_PageListProvider::CMV_PageListProvider() :
QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap CMV_PageListProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    QElapsedTimer timer;
    timer.start();

    auto img = CMV_CurrentBook::instance().getPageData(id);
    auto imgScaled = img.scaledToWidth(CMV_DeviceInfo::instance().screenWidth() / 5, Qt::SmoothTransformation);

    QPixmap pix(imgScaled.size());
    QPainter painter(&pix);
    //    painter.fillRect(pix.rect(),QColor("black"));
    painter.drawImage(QPoint{0,0},imgScaled);

    CMV_DEBUG<<"Elapsed:"<<timer.elapsed();

    return pix;
}


