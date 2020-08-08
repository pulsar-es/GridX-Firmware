#include "Arduino.h"
#include "Nextion.h"
#include "Display.h"
#include "Database.h"

void Display ::plotData(int value)
{

    int Value = value / 100; //Read the pot value ann map it to 0.255 (max value of waveform=255)
    String Tosend = "add ";  //We send the string "add "
    Tosend += 2;             //send the id of the block you want to add the value to
    Tosend += ",";
    Tosend += 0; //Channel of taht id, in this case channel 0 of the waveform
    Tosend += ",";
    Tosend += Value; //Send the value and 3 full bytes
    Serial2.print(Tosend);
    nextionwrite();
}
void Display::clearDiplay()
{
    String Tosend = "cle ";
    Tosend += 2;
    Tosend += ",";
    Tosend += 0;
    Serial2.print(Tosend);
    nextionwrite();
}
void Display::nextionwrite(void)
{
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
}
void Display::setRTCDate(int hour, int min, int sec, int day)
{

    Serial2.print("rtc0="); // This is sent the year.
    Serial2.print(day);
    nextionwrite();

    Serial2.print("rtc1="); // This is sent the month.
    Serial2.print(day);
    nextionwrite();

    Serial2.print("rtc2="); // This is sent the day.
    Serial2.print(day);     // This is sent the hour.
    nextionwrite();

    Serial2.print("rtc3="); // This is sent the hour.
    Serial2.print(hour);    // This is sent the hour.
    nextionwrite();

    Serial2.print("rtc4=4"); // This is sent the minute.
    Serial2.print(min);      // This is sent the hour.
    nextionwrite();

    Serial2.print("rtc5="); // This is sent the second.
    Serial2.print(sec);     // This is sent the hour.
    nextionwrite();
}

void Display::setRTCHour(int time)
{
    Serial2.print("rtc3="); // This is sent the hour.
    Serial2.print(time);    // This is sent the hour.
    nextionwrite();
}
void Display::setRTCMinute(int time)
{

    Serial2.print("rtc4=4"); // This is sent the minute.
    Serial2.print(time);     // This is sent the hour.
    nextionwrite();
}
void Display::setRTCDay(int time)
{
    Serial2.print("rtc2="); // This is sent the day.
    Serial2.print(time);    // This is sent the hour.
    nextionwrite();
}
void Display::setRTCMonth(int time)
{
    Serial2.print("rtc1="); // This is sent the month.
    Serial2.print(time);
    nextionwrite();
}
void Display::setRTCYear(int time)
{
    Serial2.print("rtc0="); // This is sent the year.
    Serial2.print(time);
    nextionwrite();
}

void Display::dayPlot(String dbData, int count)
{

    String seconds; //main captured String
    String minutes; //data String
    String hours;

    String years;  //main captured String
    String months; //data String
    String days;

    String power;

    int ind1 = dbData.indexOf(',');      //finds location of first ,
    seconds = dbData.substring(0, ind1); //captures first data String
    int ind2 = dbData.indexOf(',', ind1 + 1);
    minutes = dbData.substring(ind1 + 1, ind2 + 1);
    int ind3 = dbData.indexOf(',', ind2 + 1);
    hours = dbData.substring(ind2 + 1, ind3 + 1);

    int ind4 = dbData.indexOf(',', ind3 + 1);     //finds location of first ,
    years = dbData.substring(ind3 + 1, ind4 + 1); //captures first data String
    int ind5 = dbData.indexOf(',', ind4 + 1);
    months = dbData.substring(ind4 + 1, ind5 + 1);
    int ind6 = dbData.indexOf(',', ind5 + 1);
    days = dbData.substring(ind5 + 1, ind6 + 1);

    int ind7 = dbData.indexOf(',', ind6 + 1);
    power = dbData.substring(ind6 + 1);
    Serial.print(" the Power is power");
    Serial.println(months);

    plotData(months.toInt());

    if (count == 354)
        clearDiplay();
}
