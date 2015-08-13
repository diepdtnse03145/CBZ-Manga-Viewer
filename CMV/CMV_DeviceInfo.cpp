#include "CMV_DeviceInfo.h"

CMV_DeviceInfo::CMV_DeviceInfo()
{

}

int CMV_DeviceInfo::screenWidth()
{
    return 640;
}

int CMV_DeviceInfo::screenHeight()
{
    return 960;
}

QSize CMV_DeviceInfo::screenSize()
{
    return {640,960};
}

