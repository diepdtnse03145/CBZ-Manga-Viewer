#ifndef CMV_CURRENTBOOK_H
#define CMV_CURRENTBOOK_H

#include <QObject>
#include <QSharedPointer>
#include "CMV_BookManager.h"

class CMV_Book;

class CMV_CurrentBook : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentPage READ getCurrentPage NOTIFY currentPageChanged)

signals:
    void currentPageChanged();

public:
    CMV_CurrentBook(QSharedPointer<CMV_BookManager> manager, QObject* parent = nullptr);
    ~CMV_CurrentBook();

    QString getCurrentPage() const;
    QImage getPageData(const QString& id) const;

    Q_INVOKABLE void next();
    Q_INVOKABLE void previous();
    Q_INVOKABLE void gotoPage(int page);
    inline QString pageName(int index) const;
    inline int size() const;

    Q_INVOKABLE void setBook(QString path);

private:
    QSharedPointer<CMV_Book> book;
    QSharedPointer<CMV_BookManager> bookManager;
    int index;
};

QString CMV_CurrentBook::pageName(int index) const
{
    return book->pageName(index);
}

int CMV_CurrentBook::size() const
{
    return book->size();
}


#endif // CMV_CURRENTBOOK_H
