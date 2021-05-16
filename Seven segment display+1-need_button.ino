byte seven_seg_digits[10][7]={
{0,0,0,0,0,0,1},
{1,0,0,1,1,1,1},
{0,0,1,0,0,1,0},
{0,0,0,0,1,1,0},
{1,0,0,1,1,0,0},
{0,1,0,0,1,0,0},
{0,1,0,0,0,0,0},
{0,0,0,1,1,1,1},
{0,0,0,0,0,0,0},
{0,0,0,1,1,0,0},
};

byte pin_number[7]={2,3,4,5,6,7,8};

const int buttonPin=12;
int buttonState=0;
int num=0;

void setup() {
  for(byte pin=0;pin<7;pin++){
    pinMode(pin_number[pin],OUTPUT);
  }
  digitalWrite(9,0);
  digitalWrite(buttonPin,HIGH);
  pinMode(buttonPin,INPUT);
  pinMode(12,INPUT_PULLUP);
}

void sevenSegWrite(byte digit){
  byte pin=2;
  for(byte seg=0;seg<7;seg++){
    digitalWrite(pin,seven_seg_digits[digit][seg]);
    pin++;
    }
}
void loop() {
 buttonState=digitalRead(buttonPin);
 if(buttonState==LOW){
num++;
if(num>9){
  num=0;
}
 }
 sevenSegWrite(num);
 delay(1000);
}

