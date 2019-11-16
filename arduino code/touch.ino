//move servo to touch button

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
