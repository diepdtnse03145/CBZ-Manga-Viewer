#include "CMV_UiHandler.h"
#include "CMV_Log.h"
#include <QtCore>
#include "wpagepool.h"
#include "CMV_CurrentBook.h"

CMV_UiHandler::CMV_UiHandler(QObject *parent) : QObject(parent)
{
//    WPagePool::getInstance()->setSource(QStringLiteral(R"(/home/bienhust/Documents/Amagi Brilliant Park.cbz)"));

}

CMV_UiHandler::~CMV_UiHandler()
{

}

void CMV_UiHandler::nextPage()
{
    CMV_Debug<< "asf";
    CMV_CurrentBook::instance().next();
    emit currentPageChanged();
}

void CMV_UiHandler::previousPage()
{

}

void CMV_UiHandler::gotoPage(int page)
{

}

QString CMV_UiHandler::getCurrentPage()
{
    return CMV_CurrentBook::instance().getCurrentPage();
}

