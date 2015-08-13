#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtCore>
#include <QtGui>
#include <QtQml>

#include "CMV_PageProvider.h"
#include "CMV_UiHandler.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    CMV_UiHandler handler;

    engine.addImageProvider(QLatin1String("pages"), new CMV_PageProvider());
    engine.rootContext()->setContextProperty("Book",&handler);
    engine.load(QUrl(QStringLiteral("qrc:/qml/gui/main.qml")));

    return app.exec();
}
