#include "Arduino.h"

int potentiometer_pin = A0; //Define the analog input pin

unsigned long startMillis; //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 6000; //the value is a number of milliseconds
const byte ledPin = 13;            //using the built in LED

void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600); //Default baud rate of the Nextion TFT is 9600
  pinMode(potentiometer_pin, INPUT);

} //Define pin as input

void WriteToNextion(int value[])
{
  for (int i = 0; i < 355; i++)
  {
    Serial.print("i = ");
    Serial.println(i);

    int Value = value[i];   //Read the pot value ann map it to 0.255 (max value of waveform=255)
    String Tosend = "add "; //We send the string "add "
    Tosend += 2;            //send the id of the block you want to add the value to
    Tosend += ",";
    Tosend += 0; //Channel of taht id, in this case channel 0 of the waveform
    Tosend += ",";
    Tosend += Value; //Send the value and 3 full bytes
    Serial1.print(Tosend);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
    if (i = 50)
    {

      int Value = 20;         //Read the pot value ann map it to 0.255 (max value of waveform=255)
      String Tosend = "add "; //We send the string "add "
      Tosend += 2;            //send the id of the block you want to add the value to
      Tosend += ",";
      Tosend += 0; //Channel of taht id, in this case channel 0 of the waveform
      Tosend += ",";
      Tosend += Value; //Send the value and 3 full bytes
      Serial1.print(Tosend);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
    }
  }
}
int counter = 0;
int dataarray[355] = {0}; //356 one cycle of data This is the width of the graph on nextion
int scalingFactor = 100;
int data =
    void loop()
{

  currentMillis = millis();                  //get the current "time" (actually the number of milliseconds since the program started)
  if (currentMillis - startMillis >= period) //test whether the period has elapsed
  {
    int Value = map(analogRead(potentiometer_pin), 0, 1024, 0, 255); //Read the pot value ann map it to 0.255 (max value of waveform=255)
    startMillis = currentMillis;                                     //IMPORTANT to save the start time of the current LED state.
    counter = counter + 1;
    float valueF = value / scalingFactor;
    dataarray[counter] = valueF;
    Serial.print("counter = ");
    Serial.println(counter);

    if (counter == 300)
    {
      Serial.print("counter Stopped at = ");
      Serial.println(counter);
      WriteToNextion(dataarray);
      while (1)
      {
      }
    }
  }
}