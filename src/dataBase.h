#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "Arduino.h"
#include <SD.h>
#include <SPI.h>
#include "Display.h"

class Database
{

private:
public:
    Database(int pinCS)
    {

        pinMode(pinCS, OUTPUT);
        // SD Card Initialization
    }
    bool dbInit(int pinCS);
    char * CreateFile(int day, int month, int year);

    bool saveTimePower(char *data, char *filename);
    bool WritePower(char address[50], int hour, int minute, int second, int power);
    String getData(char address[50], int count);
};

#endif
