#ifndef CMV_DEVICEINFO_H
#define CMV_DEVICEINFO_H

#include <QSize>

class CMV_DeviceInfo
{
public:
    static inline CMV_DeviceInfo& instance()
    {
         static CMV_DeviceInfo i;
         return i;
    }

    int screenWidth();
    int screenHeight();

    QSize screenSize();

private:
    CMV_DeviceInfo();
};

#endif // CMV_DEVICEINFO_H
