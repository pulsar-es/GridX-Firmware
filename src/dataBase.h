#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <SD.h>
#include <SPI.h>

class dataBase
{
private:
    boolean setDatabaseFile(void);
    int setPIN(int pin);

public:
    dataBase()
    {
    }
    void dataBaseWritePower(float power, char *dateTime);
};

extern dataBase data;

#endif
