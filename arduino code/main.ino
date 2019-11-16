#include <Servo.h>

#define LEFT 0
#define RIGHT 1

Servo leftServo; //회전하기
Servo rightServo; //오르기

//TCS3200(color senser) set
#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 2
int frequency = 0;

int rgb[3]; //result of color senser. [0]=red, [1]=green [2]=blue

//game stat variable
int lastPos = LEFT; 
int thisPos = LEFT;

void setup() {
  //TCS3200 pin set
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  //servo set
  leftServo.attach(10);
  rightServo.attach(8);
  
  Serial.begin(9600);

  leftServo.write(80);
  delay(500);
  rightServo.write(80);
  delay(500);
}
void loop() {
  
  readColor();

  Serial.print(rgb[0]);Serial.print(" "); //result of senser
  Serial.print(rgb[1]);Serial.print(" ");
  Serial.print(rgb[2]);Serial.println();

  if(45 <= rgb[0] && rgb[0] <= 55 && 64 <= rgb[1] && rgb[1] <= 74  && 61 <= rgb[2] && rgb[2] <= 72){ // is the next pos is right?
    thisPos = RIGHT;
    Serial.println("MATCH");
  } else {
    Serial.println("NOOO");
    thisPos = LEFT;
  }
  if(thisPos == lastPos){
    touch(RIGHT); //오르기
  } else {
    touch(LEFT);
    lastPos = thisPos; // 회전하기
  }

  delay(100);
}
