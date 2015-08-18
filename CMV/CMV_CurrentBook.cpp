#include "CMV_CurrentBook.h"
#include "CMV_Log.h"
#include <QtGui>

CMV_CurrentBook::CMV_CurrentBook():
    book{QStringLiteral(R"(/home/diepdtn/Documents/Amagi Brilliant Park.cbz)")},
    index{}
{

}

CMV_CurrentBook::~CMV_CurrentBook()
{

}

QString CMV_CurrentBook::getCurrentPage() const
{
    CMV_DEBUG<<"INDEX"<<index;
    return QStringLiteral("image://pages/%1").arg(book.pageName(index));

}

QImage CMV_CurrentBook::getPageData(const QString &id) const
{
    return book.pageAt(id);
}

void CMV_CurrentBook::next()
{
    index = index < (book.size()-1) ? index + 1 : book.size() - 1;
}

void CMV_CurrentBook::previous()
{
    index = index > 0 ? index - 1 : 0;
}

void CMV_CurrentBook::gotoPage(int page)
{
    if(index < 0){
        page = 0;
    } else if(index > book.size()){
        page = book.size() - 1;
    } else {
        index = page;
    }
}
