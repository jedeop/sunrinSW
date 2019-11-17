//서보모터를 움직여 버튼을 터치하도록하는 함수

void touch(int btn){
  if (btn == LEFT){ //회전하기
    leftServo.write(80);
    delay(200);
    leftServo.write(50);
    delay(100);
  } else { // 오르기
    rightServo.write(80);
    delay(200);
    rightServo.write(110);
    delay(100);
  }
}
