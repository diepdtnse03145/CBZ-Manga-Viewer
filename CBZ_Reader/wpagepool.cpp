#include "wpagepool.h"
#include <QtCore>
#include <QtGui>

#define SCR_WIDTH (640)
#define SCR_HEIDTH (960)

WPagePool* WPagePool::m_pInstance = nullptr;

WPagePool::WPagePool(QObject *parent) :
    QObject(parent),
    m_index{}
{

}

WPagePool::~WPagePool()
{
    delete m_zip;
}

bool WPagePool::contains(const QString &id)
{
    return m_imgList.contains(id);
}

QPixmap WPagePool::getPagePixmap(const QString &id)
{
    QPixmap pix(SCR_WIDTH,SCR_HEIDTH);
    pix.loadFromData(m_zip->fileData(id),"JPG");
    qDebug()<<"PIX:"<<pix.size();
    return pix;
}

WPagePool *WPagePool::getInstance()
{
    return m_pInstance ? m_pInstance : (m_pInstance = new WPagePool);
}

void WPagePool::setSource(const QString &source)
{
    m_zip = new QZipReader(source);
    for (const auto ite : m_zip->fileInfoList()){
        m_imgList << ite.filePath;
    }
}

void WPagePool::next()
{
    m_index > m_imgList.size() ? m_index = m_imgList.size() : ++m_index;
    emit currentPageChanged();
}

void WPagePool::previous()
{
    m_index < 0 ? m_index = 0 : --m_index;
    emit currentPageChanged();
}

void WPagePool::gotoPage(int index)
{
    index > m_imgList.size() ? m_index = m_imgList.size() : m_index = index;
    emit currentPageChanged();
}

QString WPagePool::getCurrentPage()
{
    qDebug()<<"INDEX"<<m_index;
    return QStringLiteral("image://pages/%1").arg(m_imgList.at(m_index));
}

