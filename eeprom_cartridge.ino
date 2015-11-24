#include <Wire.h> //I2C library
#include "helpers.h"
#include "definitions.h"
//#include "eeprom.h"

void setup() 
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Wire.begin();
  Serial.begin(9600);
  clear_actions();
  upload_actions();
  Serial.print("There were ");
  Serial.print(eeaddress_pointer);
  Serial.println(" bytes written!");
  digitalWrite(13, HIGH);
}

void upload_actions() {
  action(DRAW_EYES CIRCLE);
  //this seem to get skipped
  
  action(DRAW_EYES CIRCLE);
  action(PAUSE "999");
  action(TRANSITION BLINK);
  
  action(CLEAR_LINES);
  action(WRITE REPLACE_SECOND_LINE "  Example ");
  action(WRITE SCROLL  "  Scroll");
  action(PAUSE WAITPAD);

  
  action(END);
}

