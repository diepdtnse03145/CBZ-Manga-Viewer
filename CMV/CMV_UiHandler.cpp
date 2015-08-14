#include "CMV_UiHandler.h"
#include "CMV_Log.h"
#include "CMV_CurrentBook.h"

#include <QtCore>

CMV_UiHandler::CMV_UiHandler(QObject *parent) : QObject(parent)
{

}

CMV_UiHandler::~CMV_UiHandler()
{

}

void CMV_UiHandler::nextPage()
{
    CMV_CurrentBook::instance().next();
    emit currentPageChanged();
}

void CMV_UiHandler::previousPage()
{
    CMV_CurrentBook::instance().previous();
    emit currentPageChanged();

}

void CMV_UiHandler::gotoPage(int page)
{
    CMV_DEBUG <<"To page"<<page;
    CMV_CurrentBook::instance().gotoPage(page);
    emit currentPageChanged();

}

QString CMV_UiHandler::getCurrentPage()
{
    return CMV_CurrentBook::instance().getCurrentPage();
}

