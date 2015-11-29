#include "CMV_BookManager.h"
#include "CMV_CbzBook.h"
#include <QtCore>
#include <QtGui>
#include <QtSql>
#include "CMV_Log.h"

CMV_BookManager::CMV_BookManager()
{
    CMV_ELTIMER_START(dbt);
//    updateBookDatabase();
    updateBookList();
    CMV_ELTIMER_STOP(dbt);
}

int CMV_BookManager::size(int index)
{
    return bookList.at(index)->size();
}

QString CMV_BookManager::name(int index)
{
    return bookList.at(index)->name();
}

QImage CMV_BookManager::cover(QString name)
{
    return bookList.at(name.toInt())->cover();
}

QString CMV_BookManager::type(int index)
{
    return QStringLiteral("CBZ");
}

QString CMV_BookManager::path(int index)
{
    return bookList.at(index)->path();
}

QSharedPointer<CMV_Book> CMV_BookManager::lastRead()
{
    return QSharedPointer<CMV_Book>();
}

void CMV_BookManager::updateBookList()
{
    QString path = "book.db";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "db");
    db.setDatabaseName(path);
    if (!db.open()){
        qDebug()<<"An error occurred while opening the connection: "<< db.lastError().text();
        return;
    }
    QSqlQuery query("SELECT * FROM Books", db);
    QSqlRecord rec = query.record();

    int pathCol = rec.indexOf("path");

    while (query.next()) {
        auto b = QSharedPointer<CMV_CbzBook>::create(query.value(pathCol).toString());
        bookList<<b;
    }
}

void CMV_BookManager::updateBookDatabase()
{
    QString path = "book.db";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "db");
    db.setDatabaseName(path);
    if (!db.open()){
        qDebug()<<"An error occurred while opening the connection: "<< db.lastError().text();
        return;
    }
    QSqlQuery q("", db);
    q.exec("create table Books (id integer primary key, path TEXT)");

    int i = 0;
    QDirIterator ite("/", QDirIterator::Subdirectories);

    while (ite.hasNext()){
        auto inf = ite.fileInfo();
        if(inf.isFile() && (!QString::compare(QStringLiteral("CBZ"), inf.suffix(),
                                              Qt::CaseInsensitive))){
            q.exec(QStringLiteral("insert into Books values (%1, '%2')").arg(QString::number(i++),inf.absoluteFilePath()));


        }
        ite.next();
    }
}

