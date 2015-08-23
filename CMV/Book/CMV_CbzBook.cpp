#include "CMV_CbzBook.h"
#include <QtCore>
#include <QtGui>
#include "CMV_Log.h"

CMV_CbzBook::CMV_CbzBook(const QString &path) :
    CMV_Book(),
    zip(QSharedPointer<QZipReader>::create(path)),
    bookInfo(path)
{
    bookCover.loadFromData(zip->fileData(pageName(0)),"JPG");
}

CMV_CbzBook::~CMV_CbzBook()
{

}

QString CMV_CbzBook::name() const
{
    return bookInfo.baseName();
}

int CMV_CbzBook::size() const
{
    return zip->fileInfoList().size();
}

QImage CMV_CbzBook::pageAt(const QString& id) const
{
    QImage img;
    CMV_ELTIMER_START(zipTimer);
    auto data = zip->fileData(id);
    CMV_ELTIMER_STOP(zipTimer);
    CMV_ELTIMER_START(imgTimer);
    img.loadFromData(data,"JPG");
    CMV_ELTIMER_STOP(imgTimer);
    return img;
}

QString CMV_CbzBook::pageName(int index) const
{
    return zip->fileInfoList()[index].filePath;
}

QImage CMV_CbzBook::cover() const
{
    return bookCover;
}

QString CMV_CbzBook::path() const
{
    return bookInfo.absoluteFilePath();
}



