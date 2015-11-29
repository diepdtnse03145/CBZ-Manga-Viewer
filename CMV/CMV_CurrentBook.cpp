#include "CMV_CurrentBook.h"
#include "CMV_Log.h"
#include "CMV_CbzBook.h"
#include <QtGui>

CMV_CurrentBook::CMV_CurrentBook(QSharedPointer<CMV_BookManager> manager, QObject *parent):
    QObject(parent),
    bookManager{manager},
    index{}
{
    if(bookManager->lastRead()){
        book = bookManager->lastRead();
    }else{
        book = QSharedPointer<CMV_Book>();
    }
}

CMV_CurrentBook::~CMV_CurrentBook()
{
}

QString CMV_CurrentBook::getCurrentPage() const
{
    CMV_DEBUG<<"INDEX"<<index;
    return QStringLiteral("image://pages/%1").arg(book->pageName(index));

}

QImage CMV_CurrentBook::getPageData(const QString &id) const
{
    return book->pageAt(id);
}

void CMV_CurrentBook::next()
{
    index = index < (book->size()-1) ? index + 1 : book->size() - 1;
    emit currentPageChanged();
}

void CMV_CurrentBook::previous()
{
    index = index > 0 ? index - 1 : 0;
    emit currentPageChanged();
}

void CMV_CurrentBook::gotoPage(int page)
{
    if(index < 0){
        page = 0;
    } else if(index > book->size()){
        page = book->size() - 1;
    } else {
        index = page;
    }
    emit currentPageChanged();
}

QString CMV_CurrentBook::name()
{
    return book->name();
}

void CMV_CurrentBook::setBook(QString path)
{
    CMV_DEBUG<<"set Book"<<path;
    if(QFileInfo(path).exists()){
        book = QSharedPointer<CMV_CbzBook>::create(path);
        index = 0;
    }
    qDebug()<<size();
}
