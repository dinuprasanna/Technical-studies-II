int posA,posB;

Rect[][] boxes = new Rect [8][8];

int grid;
float xoff=0, yoff=1000;

void setup(){
  size(800,800);
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){    
      
      boxes[i][j]=new Rect(i*100,j*100); 
      
    }
  }
}


void draw(){
  background(0);  
  grid = width/8;
 // noStroke();
  //noFill();



  
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){      
      stroke(50);
      //noFill();
      boxes[i][j].display();
      boxes[i][j].colour();
     
    }
  }
  
  //boxes[posA][posB].colour();

   
  
  //for(int i=0;i<=width;i+=grid){
  //  for(int j=0;j<=width;j+=grid){      
  //    stroke(50);
  //    noFill();
     
  //    rect(i,j,width/8,width/8);
  //  }
  //}
 
  
  float a = noise(xoff);
  a= map(a,0,1,0,width);
  
  float b = noise(yoff);
  b= map(b,0,1,0,height);
  
  xoff=xoff+0.001;
  yoff=yoff+0.001;
    
  fill(255,30,30);
  ellipse(a,b,30,30);
  
  posA=(ceil(a)/100);
  posB=(ceil(b)/100);
  
  fill(0,255,0);
  rect(posA*100,posB*100, 100,100);

  
  println(posA,posB); //<>//
  
  
}

class Rect{
  int xpos,ypos,c;
  Rect(int x,int y){
    xpos=x;
    ypos=y;
    c=0;
  }
  
  void display(){
    rect(xpos,ypos,width/8,width/8);
  }
  
  void colour(){
    if(posA > xpos && posA < xpos+100){
      if(posB > ypos && posB < ypos+100){
        
       fill(255);
        
  }
}
  }
}
