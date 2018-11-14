/*********************************************************
This is a library for the MPR121 12-channel Capacitive touch sensor

Designed specifically to work with the MPR121 Breakout in the Adafruit shop 
  ----> https://www.adafruit.com/products/

These sensors use I2C communicate, at least 2 pins are required 
to interface

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.  
BSD license, all text above must be included in any redistribution
**********************************************************/

#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();

uint16_t lasttouched = 0;
uint16_t currtouched = 0;

int red = 3;
int grn = 5;
int blu = 6;

void setup() {
  Serial.begin(9600);

  pinMode(red, OUTPUT);
  pinMode(grn, OUTPUT);
  pinMode(blu, OUTPUT);
}

void loop() {
  currtouched = cap.touched();
  
  for (uint8_t i=0; i<12; i++) {

    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      if (i == 1){
        analogWrite(red, 100);
      }
      else if (i == 5){
        analogWrite(grn, 100);
      }
      else if (i == 8){
        analogWrite(blu, 100);
      }
    }

    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      if (i == 1){
        analogWrite(red, 0);
      }
      else if (i == 5){
        analogWrite(grn, 0);
      }
      else if (i == 8){
        analogWrite(blu, 0);
      }
    }
  }
  lasttouched = currtouched;
}
