import processing.video.*;

import processing.serial.*;

Serial port;

Capture video;
color trackColor; 

int posA, posB;
int grid;


void setup() {
  
  size(800, 800);
  //port = new Serial(this, "COM7", 9600);
  
  String[] cameras = Capture.list();
  printArray(cameras);
  video = new Capture(this, 800, 800, "pipeline: ksvideosrc device-index=0 ! video/x-raw,width=640,height=480");
  video.start();
  trackColor = color(255, 0, 0);
  
  //frameRate(2);
}

void captureEvent(Capture video) {

  video.read();
}

void draw() {
  
  video.loadPixels();
  image(video, 0, 0, 800,800);
  
  //grid = width/8;
  //for(int i=0;i<=width;i+=grid){
  //  for(int j=0;j<=width;j+=grid){  
  //    strokeWeight(2);
  //    stroke(50);
  //    noFill();
     
  //    rect(i,j,width/8,width/8);
  //  }
  //}

  float record = 100;

  int  closestX = 0;
  float closestY = 0;


  // Begin loop to walk through every pixel
  for (int x = 0; x < video.width; x++ ) {
    for (int y = 0; y < video.height; y++ ) {
      
      int loc = x + y * video.width;
      // What is current color
      color currentColor = video.pixels[loc];
      float r1 = red(currentColor);
      float g1 = green(currentColor);
      float b1 = blue(currentColor);
      float r2 = red(trackColor);
      float g2 = green(trackColor);
      float b2 = blue(trackColor);

      float d = distSq(r1, g1, b1, r2, g2, b2); 

      if (d < record) {
        record = d;
        closestX = x;
        closestY= y;
      }
    }
  }

  // We only consider the color found if its color distance is less than 10. 
  // This threshold of 10 is arbitrary and you can adjust this number depending on how accurate you require the tracking to be.
  if (record < 2) { 
    fill(255);
    strokeWeight(4.0);
    stroke(0);
    ellipse(closestX, closestY, 40, 40);
    //print(closestX,closestY);
    
    
    posA=(ceil(closestX)/100+1);
    posB=(ceil(closestY)/100+1);
   //println(posA, " ", posB);
  }
  
  println(posA," ", posB);
  
  //byte out[] = new byte[2];
  //out[0]= byte(posA);
  //out[1]= byte(posB);
  //port.write(out);
  //println(out);
  

}

float distSq(float x1,float y1, float z1, float x2,float y2,float z2){
  float d= (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) +(z2-z1)*(z2-z1);
  return d;
  
}


void mousePressed() {
  // Save color where the mouse is clicked in trackColor variable
  int loc = mouseX + mouseY*video.width;
  trackColor = video.pixels[loc];
}
