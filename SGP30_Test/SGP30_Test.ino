/*
  Library for the Sensirion SGP30 Indoor Air Quality Sensor
  By: Ciara Jekel
  SparkFun Electronics
  Date: June 28th, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  SGP30 Datasheet: https://cdn.sparkfun.com/assets/c/0/a/2/e/Sensirion_Gas_Sensors_SGP30_Datasheet.pdf

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14813

  This example reads the sensors calculated CO2 and TVOC values
*/

#include "SparkFun_SGP30_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_SGP30
#include <Wire.h>

SGP30 mySensor; //create an object of the SGP30 class

int n = 0;

const int LED = 13;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  //Initializes sensor for air quality readings
  //measureAirQuality should be called in one second increments after a call to initAirQuality
  pinMode(LED, OUTPUT);
}

void loop() {
  //Initialize sensor
  if (mySensor.begin() == true) {

    if (mySensor.measureRawSignals() != 0) {
      Serial.println("Nothing detected");
      digitalWrite(LED, LOW);
    }
    else {

      Serial.print("Raw H2: ");
      Serial.print(mySensor.H2);
      Serial.print(" \tRaw Ethanol: ");
      Serial.println(mySensor.ethanol);

      if (mySensor.H2 > 10000 && mySensor.H2 < 13000 && mySensor.ethanol > 14000 && mySensor.ethanol < 17000) {
        digitalWrite(LED, HIGH);
      }
    }

  } 
  delay(100);



}
