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

int rgb[3]; //센서가 인식한 값. [0]=red, [1]=green [2]=blue

//게임 상태 변수
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

  leftServo.write(80); //서보모터 초기화
  delay(500);
  rightServo.write(80);
  delay(500);
}
void loop() {
  
  readColor(); //색 인식

  Serial.print(rgb[0]);Serial.print(" "); //센서 결과값을 Serial에 출력
  Serial.print(rgb[1]);Serial.print(" ");
  Serial.print(rgb[2]);Serial.println();

  if(45 <= rgb[0] && rgb[0] <= 55 && 64 <= rgb[1] && rgb[1] <= 74  && 61 <= rgb[2] && rgb[2] <= 72){ // 다음 위치게 오른쪽인가?
    thisPos = RIGHT;
    Serial.println("MATCH");
  } else {
    Serial.println("NOOO");
    thisPos = LEFT;
  }
  if(thisPos == lastPos){
    touch(RIGHT); //오르기
  } else {
    touch(LEFT); // 회전하기
    lastPos = thisPos; //이전 발판 위치 업데이트
  }

  delay(100);
}
