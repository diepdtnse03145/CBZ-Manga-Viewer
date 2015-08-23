#include "CMV_PageListProvider.h"
#include <QtCore>
#include <QtGui>
#include "CMV_Log.h"
#include "CMV_DeviceInfo.h"
#include "CMV_CurrentBook.h"

CMV_PageListProvider::CMV_PageListProvider(QSharedPointer<CMV_CurrentBook>cr) :
    QQuickImageProvider(QQuickImageProvider::Pixmap),
    currentBook{cr}
{

}

QPixmap CMV_PageListProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    CMV_ELTIMER_START(pixmap);

    auto img = currentBook->getPageData(id);
    auto imgScaled = img.scaledToWidth(CMV_DeviceInfo::instance().screenWidth() / 5, Qt::SmoothTransformation);

    QPixmap pix(imgScaled.size());
    QPainter painter(&pix);
    painter.drawImage(QPoint{0,0},imgScaled);

    CMV_ELTIMER_STOP(pixmap);

    return pix;
}


