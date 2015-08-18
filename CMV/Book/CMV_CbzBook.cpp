#include "CMV_CbzBook.h"
#include <QtCore>
#include <QtGui>

CMV_CbzBook::CMV_CbzBook(const QString &name) :
    CMV_Book(),
    zip(QSharedPointer<QZipReader>::create(name)),
    bookInfo(name)
{

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
    img.loadFromData(zip->fileData(id),"JPG");
    return img;
}

QString CMV_CbzBook::pageName(int index) const
{
    return zip->fileInfoList()[index].filePath;
}

QImage CMV_CbzBook::cover() const
{
    QImage img;
    img.loadFromData(zip->fileData(pageName(0)),"JPG");
    return img;
}



