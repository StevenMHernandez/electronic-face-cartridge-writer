#include "Arduino.h"
#include "eeprom.h"

#define APPROX_LENGTH 1024

void loop()
{
  //print some of the contents out
  int addr = 1; //first address
  byte b = i2c_eeprom_read_byte(0x50, 0); // access the first address from the memory

  while (b != 0 && addr < APPROX_LENGTH)
  {
    addr++; //increase address
    b = i2c_eeprom_read_byte(0x50, addr); //access an address from the memory
    Serial.println((char)b);
  }
  while (true) {

  }
}


int eeaddress_pointer = 1;

void clear_actions() {
  Serial.println("clearing");
  while (eeaddress_pointer < APPROX_LENGTH) {
    i2c_eeprom_write_byte(0x50, eeaddress_pointer, 0xFF);
    eeaddress_pointer++;
    delay(1);
  }
  Serial.println("cleared");
  eeaddress_pointer = 1;
}

void action(char* action) {
  char action_byte = action[0];
  int i = 0;
  while (action_byte) {
    Serial.print("address: ");
    Serial.println(eeaddress_pointer);
    Serial.print("byte: ");
    Serial.println((char)action_byte);
    i2c_eeprom_write_byte(0x50, eeaddress_pointer, action_byte);
    Serial.println((char)i2c_eeprom_read_byte(0x50, eeaddress_pointer));
    delay(4);
    i++;
    action_byte = action[i];
    eeaddress_pointer++;
  }
  i2c_eeprom_write_byte(0x50, eeaddress_pointer, 0xFF);
    delay(4);
  eeaddress_pointer++;
}
