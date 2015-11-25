#ifndef CBZMANGAVIEWER_H
#define CBZMANGAVIEWER_H

#include <QObject>
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

class CbzMangaViewer : public QObject
{
    Q_OBJECT
public:
    explicit CbzMangaViewer(QObject *parent = 0);

    void start();
signals:

public slots:

private:
    QQmlApplicationEngine engine;

    CMV_ScreenManager screenManager;
    QSharedPointer<CMV_BookManager> bookManager;

    QSharedPointer<CMV_CurrentBook> currentBook;
    CMV_PageListModel pageListModel;
    CMV_BookManagerListModel bookManagerModel;

};

#endif // CBZMANGAVIEWER_H
