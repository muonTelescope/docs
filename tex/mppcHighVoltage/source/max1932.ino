//Example Arduino code that loops through all voltages.
//SCLK --> Pin 13 for Uno or Duemilanove
//DIN ---> Pin 11 for Uno or Duemilanove

#include <SPI.h>
#define CS 2 //Any pin

void setup(){
    Serial.begin(9600);
    pinMode(CS, OUTPUT);
    digitalWrite(CS, HIGH);
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
}

void loop(){
    for(int i = 0 ; i < 256 ; i++){
        digitalWrite(CS, LOW);
        SPI.transfer(i);
        digitalWrite(CS, HIGH);
        Serial.println(i);
    }
}