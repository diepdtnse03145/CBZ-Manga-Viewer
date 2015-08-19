#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtCore>
#include <QtGui>
#include <QtQml>

#include "CMV_PageProvider.h"
#include "CMV_UiHandler.h"
#include "CMV_PageListProvider.h"
#include "CMV_PageListModel.h"
#include "CMV_BookManagerListModel.h"
#include "CMV_BookCoverProvider.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    CMV_UiHandler handler;
    CMV_PageListModel pageListModel;
    CMV_BookManagerListModel bookManagerModel;

    engine.addImageProvider(QLatin1String("pages"), new CMV_PageProvider());
    engine.addImageProvider(QLatin1String("pageList"), new CMV_PageListProvider());
    engine.addImageProvider(QLatin1String("bookCover"), new CMV_BookCoverProvider());

    engine.rootContext()->setContextProperty("Book",&handler);
    engine.rootContext()->setContextProperty("pageLists", &pageListModel);
    engine.rootContext()->setContextProperty("bookLists", &bookManagerModel);

    engine.load(QUrl(QStringLiteral("qrc:/qml/gui/main.qml")));

    QObject::connect(&handler,&CMV_UiHandler::screenSourceChanged,[&engine](QString source){
        QMetaObject::invokeMethod(engine.rootObjects().at(0), "loadSource",
                Q_ARG(QVariant, source));
    });
    return app.exec();
}
