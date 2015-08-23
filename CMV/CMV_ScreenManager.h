#ifndef CMV_SCREENMANAGER_H
#define CMV_SCREENMANAGER_H

#include <QObject>
#include <QUrl>

class CMV_ScreenManager : public QObject
{
    Q_OBJECT
public:
    explicit CMV_ScreenManager(QObject *parent = 0);

signals:
    void screenSourceChanged(QUrl);

public slots:
    void toViewer();
    void toManager();
    void toSetting();
};

#endif // CMV_SCREENMANAGER_H
