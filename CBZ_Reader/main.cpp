#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtCore>
#include <QtGui>
#include <QtQml>

#include "wpageprovider.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    WPagePool::getInstance()->setSource(QStringLiteral(R"(/home/diep/Documents/Amagi Brilliant Park.cbz)"));
    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("pages"), new WPageProvider());
    engine.rootContext()->setContextProperty("Book",WPagePool::getInstance());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
