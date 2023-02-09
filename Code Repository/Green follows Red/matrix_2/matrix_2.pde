import processing.serial.*;
Serial port;

int grid;
float xoff=0, yoff=1000;

void setup(){
  size(800,800);
  //port = new Serial(this, "COM7", 9600);
  //frameRate(24);
  
}


void draw(){
  background(0);  
  grid = width/8;
 // noStroke();
  //noFill();
  
  for(int i=0;i<=width;i+=grid){
    for(int j=0;j<=width;j+=grid){      
      stroke(50);
      noFill();
     
      rect(i,j,width/8,width/8);
    }
  }
 
  
  float a = noise(xoff);
  a= map(a,0,1,0,width);
  
  float b = noise(yoff);
  b= map(b,0,1,0,height);
  
  xoff=xoff+0.01;
  yoff=yoff+0.01;
  
  //int a = mouseX;
  //int b = mouseY;
    

    
   int posA=(ceil(a)/100);
   int posB=(ceil(b)/100);
  
  
   fill(0,255,0);
   rect(posA*100,posB*100, 100,100);
    
    
   //byte out[] = new byte[2];
   //out[0]= byte(posA);
   //out[1]= byte(posB);
   //port.write(out);
   //println(out);
    
   println(posA,posB);
    
 
  
  
  
  fill(255,30,30);
  ellipse(a,b,30,30);
  
  
  
}
