#include "CMV_BookManager.h"
#include <QtCore>
#include <QtGui>

CMV_BookManager::CMV_BookManager()
{
    QDirIterator ite{QStringLiteral(R"(/home/diepdtn/Music)"),QDirIterator::Subdirectories};
    while(ite.hasNext ()){
        if(ite.fileInfo().isFile() && (!QString::compare(ite.fileInfo().suffix(),"CBZ",Qt::CaseInsensitive))){
            CMV_CbzBook b(ite.filePath());
            bookList<<b;
        }
        ite.next();
    }

}

int CMV_BookManager::size(int index)
{
    return bookList.at(index).size();
}

QString CMV_BookManager::name(int index)
{
    return bookList.at(index).name();
}

QImage CMV_BookManager::cover(QString name)
{
    return bookList.at(name.toInt()).cover();
}

QString CMV_BookManager::type(int index)
{
    return QStringLiteral("CBZ");
}

