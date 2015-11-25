#include "cbzmangaviewer.h"

CbzMangaViewer::CbzMangaViewer(QObject *parent) :
    QObject(parent),
    bookManager{QSharedPointer<CMV_BookManager>::create()},
    currentBook{QSharedPointer<CMV_CurrentBook>::create(bookManager)},
    pageListModel{currentBook},
    bookManagerModel{bookManager}
{

    engine.addImageProvider(QLatin1String("pages"), new CMV_PageProvider(currentBook));
    engine.addImageProvider(QLatin1String("pageList"), new CMV_PageListProvider(currentBook));
    engine.addImageProvider(QLatin1String("bookCover"), new CMV_BookCoverProvider(bookManager));

    engine.rootContext()->setContextProperty("ScreenManager",&screenManager);

    auto currentBookPtr = currentBook.data();
    QQmlEngine::setObjectOwnership(currentBookPtr,QQmlEngine::CppOwnership);
    engine.rootContext()->setContextProperty("CurrentBook",currentBookPtr);

    engine.rootContext()->setContextProperty("pageLists", &pageListModel);
    engine.rootContext()->setContextProperty("bookLists", &bookManagerModel);


}

void CbzMangaViewer::start()
{
    engine.load(QUrl(QStringLiteral("qrc:/System/main.qml")));

    connect(&screenManager,&CMV_ScreenManager::currentScreenChanged,[this](QUrl source){
        QMetaObject::invokeMethod(engine.rootObjects().at(0), "loadScreen",
                                  Q_ARG(QVariant, source));
    });
}

