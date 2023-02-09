#include <LiquidCrystal_I2C.h>
#include "LedControl.h"

LedControl lc=LedControl(12,11,10,1);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2);


char val; // Data received from the serial port
int ledPin = 13; // Set the pin to digital I/O 13
int currentValue = 0;
int values[] ={0,0};

int posA, posB;

void setup() {

  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  Serial.begin(9600); // Start serial communication at 9600 bps
  lcd.init();
  lcd.backlight();

  lc.shutdown(0,false); /* Set the brightness to a medium values */
  lc.setIntensity(0,3); /* and clear the display */
  lc.clearDisplay(0);

}


void loop() {
  
  
  light(posA,posB);

  if(Serial.available()){
    int incomingValue = Serial.read();
    
    values[currentValue] = incomingValue;

    currentValue++;
      if(currentValue > 1){
        currentValue = 0;
      }

    posA = values[0];
    posB = values[1];


    light(posA,posB);


    printToFirstRow(posA,posB);
    
    
  }
  

} 

// light(posA,posB);

void printToFirstRow(int a, int b){
    lcd.setCursor(0,0);
    lcd.print(int(a));
    lcd.print(" ");
    lcd.print(int(b));
}

void light(int a, int b){

  lc.setLed(0,a,b,true);
  delay(300);
  // lc.setLed(0,a,b,false);

}