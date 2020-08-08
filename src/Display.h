#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "Arduino.h"
#include <Nextion.h>

class Display
{

    /*
     * start download.
     *
     * @return none.
     */

public:
    void dayPlot(String dbData, int count);
    void plotData(int value);
    void clearDiplay();
    void setRTCDate(int hour, int min, int sec,int day);
    void nextionwrite(void);
    void setRTCHour(int time);
    void setRTCMinute(int time);
    void setRTCDay(int time);
    void setRTCMonth(int time);
    void setRTCYear(int time);

protected:
};

#endif