#include "CMV_ScreenManager.h"
#include "gui/Screen/CMV_ScreenDefine.h"
#include "CMV_Log.h"
#include <QtCore>

CMV_ScreenManager::CMV_ScreenManager(QObject *parent) : QObject(parent)
{
    QState *viewerState = new QState();
    QState *managerState = new QState();

    viewerState->addTransition(this,SIGNAL(viewerToManager()),managerState);
    managerState->addTransition(this,SIGNAL(managerToViewer()),viewerState);

    viewerState->assignProperty(this,"currentScreenSource",QUrl(ViewerScreen));
    managerState->assignProperty(this,"currentScreenSource",QUrl(ManagerScreen));

    machine.addState(viewerState);
    machine.addState(managerState);
    QSettings setting;

//    if(setting.value("lastRead",QVariant()).toString())
    machine.setInitialState(managerState);
    machine.start();
}


