#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtCore>
#include <QtGui>
#include <QtQml>

#include "CMV_PageProvider.h"
#include "CMV_PageListProvider.h"
#include "CMV_PageListModel.h"
#include "CMV_BookManagerListModel.h"
#include "CMV_BookCoverProvider.h"
#include "CMV_ScreenManager.h"
#include "CMV_CurrentBook.h"
#include "CMV_BookManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("DiepDTN");
    app.setApplicationName("CBZ Manga Viewer");
    QQmlApplicationEngine engine;
    CMV_ScreenManager screenManager;
    auto bookManager = QSharedPointer<CMV_BookManager>::create();
    auto currentBook = QSharedPointer<CMV_CurrentBook>::create(bookManager);
    CMV_PageListModel pageListModel(currentBook);
    CMV_BookManagerListModel bookManagerModel(bookManager);


    engine.addImageProvider(QLatin1String("pages"), new CMV_PageProvider(currentBook));
    engine.addImageProvider(QLatin1String("pageList"), new CMV_PageListProvider(currentBook));
    engine.addImageProvider(QLatin1String("bookCover"), new CMV_BookCoverProvider(bookManager));

    engine.rootContext()->setContextProperty("ScreenManager",&screenManager);

    auto currentBookPtr = currentBook.data();
    QQmlEngine::setObjectOwnership(currentBookPtr,QQmlEngine::CppOwnership);
    engine.rootContext()->setContextProperty("CurrentBook",currentBookPtr);

//    auto bookManagerPtr = bookManager.data();
//    QQmlEngine::setObjectOwnership(bookManagerPtr,QQmlEngine::CppOwnership);
//    engine.rootContext()->setContextProperty("BookManager",bookManagerPtr);

    engine.rootContext()->setContextProperty("pageLists", &pageListModel);
    engine.rootContext()->setContextProperty("bookLists", &bookManagerModel);

    engine.load(QUrl(QStringLiteral("qrc:/System/main.qml")));

    QObject::connect(&screenManager,&CMV_ScreenManager::currentScreenChanged,[&engine](QUrl source){
        QMetaObject::invokeMethod(engine.rootObjects().at(0), "loadScreen",
                                  Q_ARG(QVariant, source));
    });
    return app.exec();
}
