#include <LiquidCrystal_I2C.h>
char val; // Data received from the serial port
int ledPin = 13; // Set the pin to digital I/O 13
int currentValue = 0;
int values[] ={0,0};

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2);

void setup() {
   pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
   Serial.begin(9600); // Start serial communication at 9600 bps
   lcd.init();
   lcd.backlight();
}


void loop() {
  
     
  // digitalWrite(ledPin,HIGH);
  if(Serial.available()){
    int incomingValue = Serial.read();
    
    values[currentValue] = incomingValue;

    currentValue++;
    if(currentValue > 1){
      currentValue = 0;
    }

    int posA = values[0];
    int posB = values[1];

   

    printToFirstRow(posA,posB);
    

    if((values[1])==15){

      digitalWrite(ledPin,HIGH);
      delay(300);
    
    }
    
    if((values[0])==122){

      digitalWrite(ledPin,LOW);
      delay(300);
    
    }
   
  } 
} 

void printToFirstRow(int a, int b){
    lcd.setCursor(0,0);
    lcd.print(a);
    lcd.print(" ");
    lcd.print(b);
}










// void loop() {
//    if (Serial.available()) 
//    { // If data is available to read,
//      val = Serial.read();// read it and store it in val
//    }
//    if (val % 2==0) 
//    { // If 1 was received
//      digitalWrite(ledPin, HIGH); // turn the LED on
//    } else {
//      digitalWrite(ledPin, LOW); // otherwise turn it off
//    }
//    delay(10); // Wait 10 milliseconds for next reading
// }











// int currentValue = 0;
// int values[] = {0,0};

// void setup()  {
//   Serial.begin(9600);
// } 


// void loop() {   

//   if(Serial.available()){
//     int incomingValue = Serial.read();
    
//     values[currentValue] = incomingValue;

//     currentValue++;
//     Serial.println(incomingValue);
//     if(currentValue > 1){
//       currentValue = 0;
//     }
 
//   } 
// } 