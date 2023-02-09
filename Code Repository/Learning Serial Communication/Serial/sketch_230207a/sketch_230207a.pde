//import processing.serial.*;

//Serial myPort;  // Create object from Serial class

//void setup() 
//{
//  size(200,200); //make our canvas 200 x 200 pixels big
//  //change the 0 to a 1 or 2 etc. to match your port
//  myPort = new Serial(this, "COM7", 9600);
//}

//void draw() {
//  if (mousePressed == true) 
//  {                           //if we clicked in the window
//   myPort.write('1');         //send a 1
//   println("1");   
//  } else 
//  {                           //otherwise
//  myPort.write('0');          //send a 0
//  }   
//}


import processing.serial.*;

Serial port;

void setup() {

  port = new Serial(this, "COM7", 9600);
}

void draw() {     
  
  int value1 = (int) random(122,124);
  int value2 = (int) random(15,18);
  
  
  byte out[] = new byte[2];
  out[0] = byte(value1);
  out[1] = byte(value2);
  port.write(out);
  println(out);
  
}
  
