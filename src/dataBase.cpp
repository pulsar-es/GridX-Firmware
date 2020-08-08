#include "Arduino.h"
#include "Database.h"
#include "Display.h"

bool Database::dbInit(int pinCS)
{
    bool SDCardstatus = false;
    Serial.print("Initializing SD card...");
    if (SD.begin(pinCS))
    {
        Serial.println("SD card is ready to use.");
        SDCardstatus = true;
    }
    else
    {
        Serial.println("SD card initialization failed please check SD card connection");

        SDCardstatus = false;
    }
    return SDCardstatus;
}
char* Database::CreateFile(int day, int month, int year)
{
    char folderName[8] = "POWER";
    char address[50];
    SD.mkdir(folderName);
    sprintf(address, "/%s/%02d-%02d-%02d.txt", folderName, day, month, year);
    File file = SD.open(address, FILE_WRITE);
   // Serial.println(address);

    // if the file opened okay, write to it:
    if (file)
    {
       /// Serial.println("Power (Transaction.txt) file created on SD Card ");
        
    }
    // if the file didn't open, print an error:
    else
    {
        Serial.println("error creating  Power file");
    }
    char * sendCha = address;
    return sendCha;
}

bool Database::saveTimePower(char *data, char *filename)
{
    File powerFile = SD.open(filename, FILE_WRITE);
    if (powerFile)
    {
        //Serial.println("Writing to file...");
        Serial.println(data);
        powerFile.println(data);
        powerFile.close(); // close the file
                           // Serial.println("Done power information.");
        return true;
    }
    // if the file didn't open, print an error:
    else
    {
        Serial.println("error writting  power data to SD Card");
        return false;
    }
}

bool Database::WritePower(char address[50], int hour, int minute, int second, int power)
{
    File file = SD.open(address, FILE_WRITE);
    char data[50];
    /*/sprintf(data, "%02d,%02d,%02d,%02d.txt", hour, minute, second, power);
    if (file)
    {
       // file.print(data);
        //file.close(); // close the file
                    // Serial.println("Done power information.");
        return true;
    }
    // if the file didn't open, print an error:
    else
    {
        Serial.println("error writting  power data to SD Card");
        return false;
    }*/
}
String Database::getData(char address[50], int count)
{
    Display display;

    File powerFile = SD.open(address, FILE_READ);
    String powerData = "";
    if (powerFile)
    {
        display.clearDiplay();
        while (powerFile.available())
        {
            
            // Write one line to buffer
            //Serial.println("Returning data");
            powerData = powerFile.readStringUntil('\n');
            //Serial.println("count");
            //Serial.println(powerData);
            display.dayPlot(powerData, count);
        }
        powerFile.close();
    }
    else
    {
        Serial.println("error opening Power.txt");
    }

    return powerData;
}