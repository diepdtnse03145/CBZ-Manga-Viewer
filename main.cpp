#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtCore>
#include <QtGui>
#include <QtQml>

#include "CMV_PageProvider.h"
#include "CMV_UiHandler.h"
#include "CMV_PageListProvider.h"
#include "CMV_PageListModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    CMV_UiHandler handler;
    CMV_PageListModel pageListModel;

    engine.addImageProvider(QLatin1String("pages"), new CMV_PageProvider());
    engine.addImageProvider(QLatin1String("pageList"), new CMV_PageListProvider());

    engine.rootContext()->setContextProperty("Book",&handler);
    engine.rootContext()->setContextProperty("pageLists", &pageListModel);

    engine.load(QUrl(QStringLiteral("qrc:/qml/gui/main.qml")));

    return app.exec();
}
