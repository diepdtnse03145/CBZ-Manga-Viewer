#ifndef CMV_SCREENMANAGER_H
#define CMV_SCREENMANAGER_H

#include <QObject>
#include <QUrl>
#include <QStateMachine>

class CMV_ScreenManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl currentScreenSource MEMBER m_currentScreenSource NOTIFY currentScreenChanged)
public:
    explicit CMV_ScreenManager(QObject *parent = 0);

signals:
    void currentScreenChanged(QUrl);
    void viewerToManager();
    void managerToViewer();

public slots:

private:
    QStateMachine machine;
    QUrl m_currentScreenSource;
};

#endif // CMV_SCREENMANAGER_H
