#ifndef WPAGEPOOL_H
#define WPAGEPOOL_H

#include <QObject>
#include <private/qzipreader_p.h>
#include <QStringList>

class QPixmap;
class WPagePool : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentPage READ getCurrentPage NOTIFY currentPageChanged)
public:
    void setSource(const QString& source);
    bool contains(const QString& id);

    QByteArray getPageData(const QString& id);

    static WPagePool* getInstance();

signals:
    void currentPageChanged();

public slots:
    void next();
    void previous();
    void gotoPage(int index);
    QString getCurrentPage();

private:
    explicit WPagePool(QObject *parent = 0);
    ~WPagePool();

    QStringList m_imgList;
    QZipReader *m_zip;
    int m_index;

    static WPagePool* m_pInstance;
};

#endif // WPAGEPOOL_H
