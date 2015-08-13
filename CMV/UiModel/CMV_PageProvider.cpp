#include "CMV_PageProvider.h"
#include <QtCore>
#include <QtGui>
#include "wpagepool.h"
#include "CMV_Log.h"
#include "CMV_DeviceInfo.h"
#include "CMV_CurrentBook.h"


CMV_PageProvider::CMV_PageProvider() :
    QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap CMV_PageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(size)
    Q_UNUSED(requestedSize)

    QElapsedTimer timer;
    timer.start();

    QPixmap pix(CMV_DeviceInfo::instance().screenSize());

    QPainter painter(&pix);
    painter.setRenderHint(QPainter::Antialiasing,true);
    auto img = CMV_CurrentBook::instance().getPageData(id);

    auto imgScaled = ((img.width()/static_cast<double>(CMV_DeviceInfo::instance().screenWidth())) > (img.height()/static_cast<double>(CMV_DeviceInfo::instance().screenHeight()))) ?
                img.scaledToWidth(CMV_DeviceInfo::instance().screenWidth(),Qt::SmoothTransformation) :
                img.scaledToHeight(CMV_DeviceInfo::instance().screenHeight(),Qt::SmoothTransformation) ;

    QPoint imgPoint((CMV_DeviceInfo::instance().screenWidth() - imgScaled.width()) / 2, (CMV_DeviceInfo::instance().screenHeight()- imgScaled.height()) / 2);
    CMV_Debug<<"imgPoint:"<<imgPoint;
    painter.fillRect(QRect(0,0,CMV_DeviceInfo::instance().screenWidth(),CMV_DeviceInfo::instance().screenHeight()),QColor("black"));
    painter.drawImage(imgPoint,imgScaled);
    CMV_Debug<<"Page Size:"<<imgScaled.size();
    CMV_Debug<<"Elapsed:"<<timer.elapsed();
    return pix;
}

