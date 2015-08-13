#include "wpagepool.h"
#include <QtCore>
#include <QtGui>


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

QByteArray WPagePool::getPageData(const QString &id)
{
    return m_zip->fileData(id);
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
    qDebug()<<"Number of pages:"<<m_imgList.size();
}

void WPagePool::next()
{
    m_index = m_index < (m_imgList.size()-1) ? m_index + 1 : m_imgList.size() - 1;
    emit currentPageChanged();
}

void WPagePool::previous()
{
    m_index = m_index > 0 ? m_index - 1 : 0;
    emit currentPageChanged();
}

void WPagePool::gotoPage(int index)
{
    if(index < 0){
        m_index = 0;
    } else if(index > m_imgList.size()){
        m_index = m_imgList.size() - 1;
    } else {
        m_index = index;
    }
    emit currentPageChanged();
}

QString WPagePool::getCurrentPage()
{
    qDebug()<<"INDEX"<<m_index;
    return QStringLiteral("image://pages/%1").arg(m_imgList.at(m_index));
}


