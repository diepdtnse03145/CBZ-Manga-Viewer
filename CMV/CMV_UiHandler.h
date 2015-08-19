#ifndef CMV_UIHANDLER_H
#define CMV_UIHANDLER_H

#include <QObject>

class CMV_UiHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentPage READ getCurrentPage NOTIFY currentPageChanged)

public:
    explicit CMV_UiHandler(QObject *parent = 0);
    ~CMV_UiHandler();

signals:
    void currentPageChanged();
    void screenSourceChanged(QString);

public slots:
    void nextPage();
    void previousPage();
    void gotoPage(int page);
    QString getCurrentPage();
    void setCurrentBook(int index);

};

#endif // CMV_UIHANDLER_H
