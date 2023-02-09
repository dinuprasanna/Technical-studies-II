#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,3);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */


/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */


/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
// void single() {
//   for(int row=0;row<8;row++) {
//     for(int col=0;col<8;col++) {
//       delay(delaytime);
//       lc.setLed(0,row,col,true);
//       delay(delaytime);
//       for(int i=0;i<col;i++) {
//         lc.setLed(0,row,col,false);
//         delay(delaytime);
//         lc.setLed(0,row,col,true);
//         delay(delaytime);
//       }
//     }
//   }
// }

int sense = 8;
bool ya = true;

void loop() { 

  lc.shutdown(0,false);
  
  sense = random(8); 
  Serial.println(sense);

  for(int i= 0 ; i< sense; i++){

    for(int j=0; j< sense; j++){

      
     


      lc.setLed(0,i,j,true);
      delay(10);
      //lc.setLed(0,i,j,false);

   
      

      // lc.setLed(0,i,j,false);




    }
  }
  // lc.shutdown(0,true);
  lc.clearDisplay(0);
  
  
}