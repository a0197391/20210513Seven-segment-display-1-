byte sevenseg[10][7]={{0,0,0,0,0,0,1},
{0,1,0,1,1,1,1},
{0,0,1,0,0,1,0},
{0,0,0,0,1,1,0},
{0,1,0,1,1,0,0},
{1,0,0,0,1,0,0},
{1,0,0,0,0,0,0},
{0,0,0,1,1,1,1},
{0,0,0,0,0,0,0},
{0,0,0,1,1,0,0}};
byte num[7]={2,3,4,5,6,7,8};
const int buttonPin=12;   
int presentButtonState;
int i,vv=0,a=1;                                                                                                              
void setup() {
  // put your setup code here, to run once:
  for(i=0;i<7;i++){
pinMode(num[i],OUTPUT);
  }
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH);
}
void sevensegwrite(byte n){
for(i=0;i<7;i++){
  digitalWrite(num[i],sevenseg[n][i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  presentButtonState =digitalRead(buttonPin);
if( presentButtonState==0&&a==1){vv++;a=0;}
if( presentButtonState==1){a=1;}
  if(vv>9){vv=0;}
  sevensegwrite(vv);
delay(2);
}
