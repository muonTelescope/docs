#include "nau7802/NAU7802.h"
#include "nau7802/NAU7802.cpp"
#include <Wire.h>

// Create the NAU7802 ADC object
NAU7802 adc = NAU7802();

void setup(void) {
    Serial.begin(9600);
    Wire.begin();       // Join i2c bus
    adc.begin();        // Initalize ADC
    adc.avcc2V4();      // Set voltage range to 0-2.4V
}

void loop(void) {
    // Read Channel 1
    adc.selectCh1();  // Channel 1 has 50x Divided High voltage
    Serial.print("Chanel 1: ");
    Serial.println(adc.readmV());

    // Read Channel 2
    adc.selectCh2();  // Channel 2 has thermistor
    Serial.print("Chanel 2: ");
    Serial.println(adc.readmV());
}