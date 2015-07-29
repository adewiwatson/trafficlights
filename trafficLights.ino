//LED Pin Variables
//Right street(pedestrian) pins Green, Amber, Red;234 crossing light pin 5 input button pin 6
//bottom street(right turning) pins Green,Amber, Red; 789 right turn light pin 10
//top street(straight) pins green,amber,red 11,12,13
//|    .  R10  |
//|    .  A9  |___G(3)_____
//|       G8
//| R6         ---|  |-----
//| A5 .G7.  ___G0A1R2________
//| G4 .   .  |
//|           |
int ledPins[] = {2,3,4,5,7,8,9,10,11,12,13};
int inputPin =0;
int ldrPin = 0;
int GREENTIME = 10000;
int ORANGETIME = 2000;
//int redTimeNorm = 5000;
//int redTimePress = 15000;
int inputVal = 0;
int buttonPressed = 0;
int lightLevel = 0;
//int NOFLASHES = 5;
//int FLASHPERIOD = 500;
int lastPos = 0;
void setup() {
  // put your setup code here, to run once:
  //initiate each pin
  for(int i = 0; i < 11; i++){
      pinMode(ledPins[i],OUTPUT);
  }
  pinMode(inputPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //normalCycle();
  loopFunction();
}

void loopFunction(){
  if(lightLevel > 300){
    position2();
    lastPos = 2;
  }
  position3(lastPos);
  lastPos = 3;
  
  if(buttonPressed == 1){
    buttonPressed = 0;
    position4();
    lastPos = 4;
  }
  position1(lastPos);
  lastPos = 1;

//    if(buttonPressed == 1){
//    normalCycle(redTimePress);
//    buttonPressed = 0;
//  } else {
//    normalCycle(redTimeNorm);
//  }
}

//void normalCycle(int redTimeTemp){
//  digitalWrite(ledPins[2],HIGH);
//  if (redTimeTemp == redTimePress){
//    digitalWrite(ledPins[3],HIGH);
//    myDelay(redTimeTemp);
//    digitalWrite(ledPins[3],LOW);
//    digitalWrite(ledPins[2],LOW);
//    for(int i = 1;i<=NOFLASHES;i++){
//    digitalWrite(ledPins[3],HIGH);
//    digitalWrite(ledPins[1],HIGH);
//    myDelay(FLASHPERIOD);
//    digitalWrite(ledPins[3],LOW);
//    digitalWrite(ledPins[1],LOW);
//    myDelay(FLASHPERIOD);
//    }
//  }else{
//  myDelay(redTimeTemp);
//  digitalWrite(ledPins[1],HIGH);
//  myDelay(ORANGETIME);
//  digitalWrite(ledPins[2],LOW);
//  digitalWrite(ledPins[1],LOW);
//  }
//  digitalWrite(ledPins[0], HIGH);
//  myDelay(GREENTIME);
//  digitalWrite(ledPins[0],LOW);
//  digitalWrite(ledPins[1],HIGH);
//  myDelay(ORANGETIME);
//  digitalWrite(ledPins[1],LOW);
//}

//|    .  R10  |
//|    .  A9  |___G(3)_____
//|       G8
//| R6         ---|  |-----
//| A5 .G7.  ___G0A1R2________
//| G4 .   .  |
//|           |


//|    .      |
//|    .   G  |____ R _____
//|
//|            ---|  |-----
//| G  . R  .  _R_____________
//|    .   .  |
//|           |
void position1(int prevPos){
  if (prevPos == 3){
    
    digitalWrite(ledPins[10], HIGH);
    digitalWrite(ledPins[9], HIGH);
    digitalWrite(ledPins[6], HIGH);
    digitalWrite(ledPins[5], HIGH);
    digitalWrite(ledPins[1], HIGH);
    myDelay(ORANGETIME);
    digitalWrite(ledPins[10],LOW);
    digitalWrite(ledPins[9],LOW);
    digitalWrite(ledPins[6],LOW);
    digitalWrite(ledPins[5],LOW);
    digitalWrite(ledPins[1],LOW);
  } else{
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[4], HIGH);

    digitalWrite(ledPins[10], HIGH);
    digitalWrite(ledPins[9], HIGH);
    myDelay(ORANGETIME);
    digitalWrite(ledPins[10],LOW);
    digitalWrite(ledPins[9],LOW);
  }
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[8], HIGH);
  digitalWrite(ledPins[2], HIGH);
  myDelay(GREENTIME);
  digitalWrite(ledPins[4],LOW);
  digitalWrite(ledPins[8],LOW);
  digitalWrite(ledPins[2],LOW);
  }
//|    .      |
//|    .   R  |____ R _____
//|
//|            ---|  |-----
//| G  . G  .  _R_____________
//|    .   .  |
//|           |
void position2(){
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[4], HIGH);

  digitalWrite(ledPins[9], HIGH);
  myDelay(ORANGETIME);
  digitalWrite(ledPins[9], LOW);

  digitalWrite(ledPins[10], HIGH);
  digitalWrite(ledPins[7], HIGH);
  myDelay(GREENTIME);
  digitalWrite(ledPins[4], LOW);
  digitalWrite(ledPins[7], LOW);
  digitalWrite(ledPins[10], LOW);
  digitalWrite(ledPins[2], LOW);
  }
//|    .      |
//|    .   R  |____ R _____
//|
//|            ---|  |-----
//| R  . R  .  _G_____________
//|    .   .  |
//|           |
void position3(int prevPos){
  if (prevPos == 2){
  digitalWrite(ledPins[10], HIGH);

  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[5], HIGH);
  myDelay(ORANGETIME);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[5], LOW);
  } else{
  digitalWrite(ledPins[10], HIGH);

  digitalWrite(ledPins[9], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[5], HIGH);
  myDelay(ORANGETIME);
  digitalWrite(ledPins[9], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[5], LOW);
  }
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[6], HIGH);
  myDelay(GREENTIME);
  digitalWrite(ledPins[6],LOW);
  digitalWrite(ledPins[10],LOW);
  digitalWrite(ledPins[0],LOW);
  }
//|    .      |
//|    .   R  |____ G _____
//|
//|            ---|  |-----
//| G  . R  .  _R_____________
//|    .   .  |
//|           |
void position4(){
  digitalWrite(ledPins[10], HIGH);

  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[6], HIGH);
  digitalWrite(ledPins[5], HIGH);
  myDelay(ORANGETIME);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[6], LOW);
  digitalWrite(ledPins[5], LOW);

  digitalWrite(ledPins[3], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[4], HIGH);
  myDelay(GREENTIME);
  digitalWrite(ledPins[3],LOW);
  digitalWrite(ledPins[10],LOW);
  digitalWrite(ledPins[2],LOW);
  digitalWrite(ledPins[4],LOW);
  }


void checkButton(){
  lightLevel = analogRead(ldrPin);
  inputVal = digitalRead(inputPin);
  if (inputVal == LOW){
      buttonPressed = 1;
    }
  }
void myDelay(int timePeriod){
  for(int i = 1;i<=timePeriod;i++){
    checkButton();
    delay(1);
  }
}
