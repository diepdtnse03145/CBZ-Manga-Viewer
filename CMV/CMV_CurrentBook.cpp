#include "CMV_CurrentBook.h"
#include "CMV_Log.h"
#include <QtGui>

CMV_CurrentBook::CMV_CurrentBook():
    book{QStringLiteral(R"(/home/diep/Documents/Amagi Brilliant Park.cbz)")},
    index{}
{

}

CMV_CurrentBook::~CMV_CurrentBook()
{

}

QString CMV_CurrentBook::getCurrentPage()
{
    CMV_Debug<<"INDEX"<<index;
    return QStringLiteral("image://pages/%1").arg(book.pageName(index));

}

QImage CMV_CurrentBook::getPageData(const QString &id)
{
    return book.pageAt(id);
}

void CMV_CurrentBook::next()
{
    ++index;
}

