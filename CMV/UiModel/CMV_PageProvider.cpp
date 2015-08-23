#include "CMV_PageProvider.h"
#include <QtCore>
#include <QtGui>

#include "CMV_Log.h"
#include "CMV_DeviceInfo.h"
#include "CMV_CurrentBook.h"

CMV_PageProvider::CMV_PageProvider(QSharedPointer<CMV_CurrentBook> cr) :
    QQuickImageProvider(QQuickImageProvider::Pixmap),
    currentBook{cr}
{

}

QPixmap CMV_PageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(size)
    Q_UNUSED(requestedSize)

    CMV_ELTIMER_START(pixmap);

    QElapsedTimer timer;
    timer.start();

    QPixmap pix(CMV_DeviceInfo::instance().screenSize());

    QPainter painter(&pix);
    auto img = currentBook->getPageData(id);
    auto imgScaled = img.scaled(pix.size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QPoint imgPoint((CMV_DeviceInfo::instance().screenWidth() - imgScaled.width()) / 2, (CMV_DeviceInfo::instance().screenHeight()- imgScaled.height()) / 2);

    painter.fillRect(pix.rect(),QColor("black"));
    painter.drawImage(imgPoint,imgScaled);

    CMV_ELTIMER_STOP(pixmap);

    return pix;
}

