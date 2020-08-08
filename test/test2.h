#include <SD.h>
#include "RTClib.h"
#include <Wire.h>
#include <string.h>
RTC_DS1307 RTC;
char FileName[] = "P00-0000.txt";
char FolderName[] = "0000-00";
File PicFile;

void setup()
{
    Serial.begin(115200);
    Wire.begin(); //Important for RTClib.h
    RTC.begin();
    if (!RTC.isrunning())
    {
        Serial.println("RTC is NOT running!");
        // following line sets the RTC to the date & time this sketch was compiled
        // RTC.adjust(DateTime(__DATE__, __TIME__));
        return;
    }
    Serial.print("Initializing SD card...");
    // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
    // Note that even if it's not used as the CS pin, the hardware SS pin
    // (10 on most Arduino boards, 53 on the Mega) must be left as an output
    // or the SD library functions will not work.
    pinMode(53, OUTPUT);
    if (!SD.begin(53))
    {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");
}

void loop()
{
    GetFolder();
    CreateFolderName();
    delay(3000);
    GetFileName();
    CreateFile();
    delay(3000);
}

void GetFolderName()
{
    DateTime now = RTC.now();
    FolderName[0] = (now.year() / 1000) % 10 + '0'; //To get 1st digit from year()
    FolderName[1] = (now.year() / 100) % 10 + '0';  //To get 2nd digit from year()
    FolderName[2] = (now.year() / 10) % 10 + '0';   //To get 3rd digit from year()
    FolderName[3] = now.year() % 10 + '0';          //To get 4th digit from year()
    FolderName[5] = now.month() / 10 + '0';         //To get 1st digit from month()
    FolderName[6] = now.month() % 10 + '0';         //To get 2nd digit from month()
    Serial.println(FolderName);
}

void CreateFolder()
{
    if (SD.exists(FolderName))
    {
        Serial.println("exists.");
    }
    else
    {
        Serial.println("doesn't exist.");
        Serial.println("Creating new file");
        Serial.println(FolderName);
        SD.mkdir(FolderName);
    }
}

void GetFileName()
{
    DateTime now = RTC.now();
    FileName[1] = now.day() / 10 + '0';    //To get 1st digit from day()
    FileName[2] = now.day() % 10 + '0';    //To get 2nd digit from day()
    FileName[4] = now.hour() / 10 + '0';   //To get 1st digit from day()
    FileName[5] = now.hour() % 10 + '0';   //To get 2nd digit from day()
    FileName[6] = now.minute() / 10 + '0'; //To get 1st digit from day()
    FileName[7] = now.minute() % 10 + '0'; //To get 2nd digit from day()
    Serial.println(FileName);
}

void CreateFile()
{
    if (SD.exists(/ FolderName / FileName))
    { //<<-Not sure about the syntax needed here
        Serial.println("Exists.");
    }
    else
    {
        Serial.println("doesn't exist.");
        Serial.println("Creating new file");
        Serial.println(FileName);
        PicFile = SD.open(/ FolderName / FileName, FILE_WRITE); //<<-Not sure about the syntax needed here
        PicFile.close();
    }
}