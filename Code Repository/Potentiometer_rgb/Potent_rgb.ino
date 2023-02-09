int r=4;
int g=2;
int b=3;

void digitalWriteRGB(byte red, byte blue, byte green)
{
  digitalWrite(r, red);
  digitalWrite(g, blue);
  digitalWrite(b, green);
}

void setup() {
  
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

}

void loop() {
  int potentio = analogRead(A0);
  int mode = map(potentio,0,1023,0,6);
  switch(mode)
  {
    case 1:
    digitalWriteRGB(HIGH,LOW,LOW);
    break;
    case 2:
    digitalWriteRGB(LOW,HIGH,LOW);
    break;
    case 3:
    digitalWriteRGB(LOW,LOW,HIGH);
    break;
    case 4:
    digitalWriteRGB(HIGH,HIGH,LOW);
    break;
    case 5:
    digitalWriteRGB(HIGH,LOW,HIGH);
    break;
    case 6:
    digitalWriteRGB(HIGH,LOW,LOW);
    break;

    default:
    digitalWriteRGB(LOW,LOW,LOW);
    break;
  }
  


}
