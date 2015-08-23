#include "CMV_ScreenManager.h"
#include "gui/CMV_ScreenDefine.h"
#include "CMV_Log.h"


CMV_ScreenManager::CMV_ScreenManager(QObject *parent) : QObject(parent)
{

}

void CMV_ScreenManager::toViewer()
{
    CMV_DEBUG;
    emit screenSourceChanged(QUrl(ViewerScreen));
}

void CMV_ScreenManager::toManager()
{
    emit screenSourceChanged(QUrl(ManagerScreen));
}

void CMV_ScreenManager::toSetting()
{

}

