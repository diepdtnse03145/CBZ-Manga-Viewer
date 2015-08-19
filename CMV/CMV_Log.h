#ifndef CMV_LOG
#define CMV_LOG

#include <QtGlobal>
#include <QDebug>
#include <QFileInfo>
#include <QTime>
#include <QElapsedTimer>

#define CMV_DEBUG qDebug()<<QFileInfo(__FILE__).fileName() <<":"<<  \
    QStringLiteral("%1()").arg(__FUNCTION__)<<":"

#if defined(CMV_NO_DEBUG_OUTPUT)
#  undef CMV_DEBUG
#  define CMV_DEBUG while (false) qDebug()
#endif

#define CMV_ELTIMER_START(t) QElapsedTimer t; t.start()

#define CMV_ELTIMER_STOP(t) CMV_DEBUG<<#t<<":"<<t.elapsed()

#endif // CMV_LOG

