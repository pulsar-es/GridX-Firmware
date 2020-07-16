#include "dataBase.h"

File myFile;

void dataBase::dataBaseWritePower(float power, char *dateTime)
{
}

boolean dataBase::setDatabaseFile()
{

    bool SDCardstatus = false;
    int pinCS = 53; // Pin 10 on Arduino Uno
    pinMode(pinCS, OUTPUT);
    // SD Card Initialization
    if (SD.begin())
    {
        Serial.println("SD card is ready to use.");
        SDCardstatus = true;
    }
    else
    {
        Serial.println("SD card initialization failed");
        SDCardstatus = false;
    }
    return SDCardstatus
}