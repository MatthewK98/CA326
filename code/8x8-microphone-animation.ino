#include "LedControl.h"

#define speakerPin 5
# define potPin A4

LedControl lc=LedControl(6,10,12,4);
unsigned long delaytime=1000;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);

  pinMode(potPin,INPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}



void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

void loop() { 

  uint16_t potValue;

  potValue = analogRead(potPin);
  
  byte big[8] = {0x3C,0x42,0x81,0x81,0x81,0x41,0x66,0x18};
  byte small[8] = {0x00,0x3C,0x42,0x41,0x41,0x22,0x1C,0x00};
//  delay(1000);
//  printByte(big);
//  delay(2000);
//  printByte(small);
  if (potValue < 100){
    printByte(big);
  }
  if (potValue > 342){
    printByte(small);
  }
}
