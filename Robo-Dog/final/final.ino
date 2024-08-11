#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  160
#define SERVOMAX  600

#define SERVO_0 3
#define SERVO_1 4
#define SERVO_2 5
#define SERVO_3 6
#define SERVO_4 7
#define SERVO_5 8
#define SERVO_6 0
#define SERVO_7 1
#define SERVO_8 2
#define SERVO_9 9
#define SERVO_10 10
#define SERVO_11 11

int val(int deg) {
  int value = map(deg, 0, 180, SERVOMIN, SERVOMAX);
  return value;
}

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  pwm.setPWM(SERVO_0, 0, val(135));
  pwm.setPWM(SERVO_1, 0, val(90));
  pwm.setPWM(SERVO_2, 0, val(90));
  pwm.setPWM(SERVO_3, 0, val(125));
  pwm.setPWM(SERVO_4, 0, val(90));
  pwm.setPWM(SERVO_5, 0, val(105));
  pwm.setPWM(SERVO_6, 0, val(45));
  pwm.setPWM(SERVO_7, 0, val(135));
  pwm.setPWM(SERVO_8, 0, val(25));
  pwm.setPWM(SERVO_9, 0, val(40));
  pwm.setPWM(SERVO_10, 0, val(130));
  pwm.setPWM(SERVO_11, 0, val(160));
}

void loop() {
  if (Serial.available() > 0) {
    char a = Serial.read();
    if(a=='F'){
      forward();
    }
    else if(a=='B'){
      backward();
    }
    else if(a=='L'){
      left();
    }
    else if(a=='R'){
      right();
    }
    else if(a=='1'){
      march_past();
    }
    else{
      pwm.setPWM(SERVO_0, 0, val(135));
      pwm.setPWM(SERVO_1, 0, val(90));
      pwm.setPWM(SERVO_2, 0, val(90));
      pwm.setPWM(SERVO_3, 0, val(125));
      pwm.setPWM(SERVO_4, 0, val(90));
      pwm.setPWM(SERVO_5, 0, val(105));
      pwm.setPWM(SERVO_6, 0, val(45));
      pwm.setPWM(SERVO_7, 0, val(135));
      pwm.setPWM(SERVO_8, 0, val(25));
      pwm.setPWM(SERVO_9, 0, val(40));
      pwm.setPWM(SERVO_10, 0, val(130));
      pwm.setPWM(SERVO_11, 0, val(160));
    }
  }
  else{
    pwm.setPWM(SERVO_0, 0, val(135));
    pwm.setPWM(SERVO_1, 0, val(90));
    pwm.setPWM(SERVO_2, 0, val(90));
    pwm.setPWM(SERVO_3, 0, val(125));
    pwm.setPWM(SERVO_4, 0, val(90));
    pwm.setPWM(SERVO_5, 0, val(105));
    pwm.setPWM(SERVO_6, 0, val(45));
    pwm.setPWM(SERVO_7, 0, val(135));
    pwm.setPWM(SERVO_8, 0, val(25));
    pwm.setPWM(SERVO_9, 0, val(40));
    pwm.setPWM(SERVO_10, 0, val(130));
    pwm.setPWM(SERVO_11, 0, val(160));
  }
  delay(100);
}

void forward(){
  for (int p1 = val(105), p2 = val(75), p3 = val(80), p4 = val(120); p1 >= val(90) && p2 <= val(105) && p3 <= val(90) && p4 >= val(90); p1 -= val(1), p2 += val(2), p3 += val(1), p4 -= val(2)) {
        delay(400);
        pwm.setPWM(SERVO_4, 0, p1);
        pwm.setPWM(SERVO_5, 0, p2);
        pwm.setPWM(SERVO_1, 0, p3);
        pwm.setPWM(SERVO_2, 0, p4);
      }
      for (int p1 = val(90), p2 = val(105), p3 = val(90), p4 = val(90); p1 <= val(100) && p2 >= val(75) && p3 >= val(80) && p4 <= val(120); p1 += val(1), p2 -= val(2), p3 -= val(1), p4 += val(2)) {
        delay(400);
        pwm.setPWM(SERVO_4, 0, p1);
        pwm.setPWM(SERVO_5, 0, p2);
        pwm.setPWM(SERVO_1, 0, p3);
        pwm.setPWM(SERVO_2, 0, p4);
      } 
      delay(100);
      for (int p1 = val(95), p2 = val(80), p3 = val(100), p4 = val(115); p1 >= val(85) && p2 <= val(110) && p3 >= val(90) && p4 >= val(85); p1 += val(1), p2 -= val(2), p3 -= val(1), p4 -= val(2)) {
        delay(400);
        pwm.setPWM(SERVO_7, 0, p1);
        pwm.setPWM(SERVO_8, 0, p2);
        pwm.setPWM(SERVO_10, 0, p3);
        pwm.setPWM(SERVO_11, 0, p4);
      }
      for (int p1 = val(85), p2 = val(110), p3 = val(90), p4 = val(85); p1 <= val(95) && p2 >= val(80) && p3 <= val(100) && p4 <= val(115); p1 -= val(1), p2 += val(2), p3 += val(1), p4 += val(2)) {
        delay(400);
        pwm.setPWM(SERVO_7, 0, p1);
        pwm.setPWM(SERVO_8, 0, p2);
        pwm.setPWM(SERVO_10, 0, p3);
        pwm.setPWM(SERVO_11, 0, p4);
      }
}

void backward(){
  for (int p1 = val(85), p2 = val(110), p3 = val(90), p4 = val(85); p1 <= val(95) && p2 >= val(80) && p3 <= val(100) && p4 <= val(115); p1 -= val(1), p2 += val(2), p3 += val(1), p4 += val(2)) {
        delay(400);
        pwm.setPWM(SERVO_7, 0, p1);
        pwm.setPWM(SERVO_8, 0, p2);
        pwm.setPWM(SERVO_10, 0, p3);
        pwm.setPWM(SERVO_11, 0, p4);
      for (int p1 = val(95), p2 = val(80), p3 = val(100), p4 = val(115); p1 >= val(85) && p2 <= val(110) && p3 >= val(90) && p4 >= val(85); p1 += val(1), p2 -= val(2), p3 -= val(1), p4 -= val(2)) {
        delay(400);
        pwm.setPWM(SERVO_7, 0, p1);
        pwm.setPWM(SERVO_8, 0, p2);
        pwm.setPWM(SERVO_10, 0, p3);
        pwm.setPWM(SERVO_11, 0, p4);
      }
      delay(1000);
      for (int p1 = val(90), p2 = val(105), p3 = val(90), p4 = val(90); p1 <= val(100) && p2 >= val(75) && p3 >= val(80) && p4 <= val(120); p1 += val(1), p2 -= val(2), p3 -= val(1), p4 += val(2)) {
        delay(400);
        pwm.setPWM(SERVO_4, 0, p1);
        pwm.setPWM(SERVO_5, 0, p2);
        pwm.setPWM(SERVO_1, 0, p3);
        pwm.setPWM(SERVO_2, 0, p4);
      } 
      for (int p1 = val(105), p2 = val(75), p3 = val(80), p4 = val(120); p1 >= val(90) && p2 <= val(105) && p3 <= val(90) && p4 >= val(90); p1 -= val(1), p2 += val(2), p3 += val(1), p4 -= val(2)) {
        delay(400);
        pwm.setPWM(SERVO_4, 0, p1);
        pwm.setPWM(SERVO_5, 0, p2);
        pwm.setPWM(SERVO_1, 0, p3);
        pwm.setPWM(SERVO_2, 0, p4);
      }
      delay(100);
  }
}

void left(){
  for (int p1 = val(105), p2 = val(75), p3 = val(80), p4 = val(120); p1 >= val(90) && p2 <= val(105) && p3 <= val(90) && p4 >= val(90); p1 -= val(1), p2 += val(2), p3 += val(1), p4 -= val(2)) {
    delay(400);
    pwm.setPWM(SERVO_4, 0, p1);
    pwm.setPWM(SERVO_5, 0, p2);
    // pwm.setPWM(SERVO_1, 0, p3);
    // pwm.setPWM(SERVO_2, 0, p4);
  }
  for (int p1 = val(90), p2 = val(105), p3 = val(90), p4 = val(90); p1 <= val(100) && p2 >= val(75) && p3 >= val(80) && p4 <= val(120); p1 += val(1), p2 -= val(2), p3 -= val(1), p4 += val(2)) {
    delay(400);
    pwm.setPWM(SERVO_4, 0, p1);
    pwm.setPWM(SERVO_5, 0, p2);
    // pwm.setPWM(SERVO_1, 0, p3);
    // pwm.setPWM(SERVO_2, 0, p4);
  } 
  delay(100);
  for (int p1 = val(95), p2 = val(80), p3 = val(100), p4 = val(115); p1 >= val(85) && p2 <= val(110) && p3 >= val(90) && p4 >= val(85); p1 += val(1), p2 -= val(2), p3 -= val(1), p4 -= val(2)) {
    delay(400);
    pwm.setPWM(SERVO_7, 0, p1);
    pwm.setPWM(SERVO_8, 0, p2);
    pwm.setPWM(SERVO_10, 0, p3);
    pwm.setPWM(SERVO_11, 0, p4);
  }
  for (int p1 = val(85), p2 = val(110), p3 = val(90), p4 = val(85); p1 <= val(95) && p2 >= val(80) && p3 <= val(100) && p4 <= val(115); p1 -= val(1), p2 += val(2), p3 += val(1), p4 += val(2)) {
    delay(400);
    pwm.setPWM(SERVO_7, 0, p1);
    pwm.setPWM(SERVO_8, 0, p2);
    pwm.setPWM(SERVO_10, 0, p3);
    pwm.setPWM(SERVO_11, 0, p4);
  }
}

void right(){
  for (int p1 = val(105), p2 = val(75), p3 = val(80), p4 = val(120); p1 >= val(90) && p2 <= val(105) && p3 <= val(90) && p4 >= val(90); p1 -= val(1), p2 += val(2), p3 += val(1), p4 -= val(2)) {
    delay(400);
    // pwm.setPWM(SERVO_4, 0, p1);
    // pwm.setPWM(SERVO_5, 0, p2);
    pwm.setPWM(SERVO_1, 0, p3);
    pwm.setPWM(SERVO_2, 0, p4);
  }
  for (int p1 = val(90), p2 = val(105), p3 = val(90), p4 = val(90); p1 <= val(100) && p2 >= val(75) && p3 >= val(80) && p4 <= val(120); p1 += val(1), p2 -= val(2), p3 -= val(1), p4 += val(2)) {
    delay(400);
    // pwm.setPWM(SERVO_4, 0, p1);
    // pwm.setPWM(SERVO_5, 0, p2);
    pwm.setPWM(SERVO_1, 0, p3);
    pwm.setPWM(SERVO_2, 0, p4);
  } 
  delay(100);
  for (int p1 = val(95), p2 = val(80), p3 = val(100), p4 = val(115); p1 >= val(85) && p2 <= val(110) && p3 >= val(90) && p4 >= val(85); p1 += val(1), p2 -= val(2), p3 -= val(1), p4 -= val(2)) {
    delay(400);
    pwm.setPWM(SERVO_7, 0, p1);
    pwm.setPWM(SERVO_8, 0, p2);
    pwm.setPWM(SERVO_10, 0, p3);
    pwm.setPWM(SERVO_11, 0, p4);
  }
  for (int p1 = val(85), p2 = val(110), p3 = val(90), p4 = val(85); p1 <= val(95) && p2 >= val(80) && p3 <= val(100) && p4 <= val(115); p1 -= val(1), p2 += val(2), p3 += val(1), p4 += val(2)) {
    delay(400);
    pwm.setPWM(SERVO_7, 0, p1);
    pwm.setPWM(SERVO_8, 0, p2);
    pwm.setPWM(SERVO_10, 0, p3);
    pwm.setPWM(SERVO_11, 0, p4);
  }
}

void march_past(){
  for (int p1 = val(105), p2 = val(75), p3 = val(95), p4 = val(80); p1 >= val(90) && p2 <= val(105) && p3 >= val(85) && p4 <= val(110); p1 -= val(1), p2 += val(2), p3 -= val(1), p4 += val(2)) {
    delay(400);
    pwm.setPWM(SERVO_4, 0, p1);
    pwm.setPWM(SERVO_5, 0, p2);
    pwm.setPWM(SERVO_7, 0, p3);
    pwm.setPWM(SERVO_8, 0, p4);
  }
  for (int p1 = val(90), p2 = val(105), p3 = val(85), p4 = val(110); p1 <= val(100) && p2 >= val(75) && p3 <= val(95) && p4 >= val(80); p1 += val(1), p2 -= val(2), p3 += val(1), p4 -= val(2)) {
    delay(400);
    pwm.setPWM(SERVO_4, 0, p1);
    pwm.setPWM(SERVO_5, 0, p2);
    pwm.setPWM(SERVO_7, 0, p3);
    pwm.setPWM(SERVO_8, 0, p4);
  } 
  delay(100);
  for (int p1 = val(80), p2 = val(120), p3 = val(100), p4 = val(115); p1 <= val(90) && p2 >= val(90) && p3 >= val(90) && p4 >= val(85); p1 += val(1), p2 -= val(2), p3 -= val(1), p4 -= val(2)) {
    delay(400);
    pwm.setPWM(SERVO_1, 0, p1);
    pwm.setPWM(SERVO_2, 0, p2);
    pwm.setPWM(SERVO_10, 0, p3);
    pwm.setPWM(SERVO_11, 0, p4);
  }
  for (int p1 = val(90), p2 = val(90), p3 = val(90), p4 = val(85); p1 >= val(80) && p2 <= val(120) && p3 <= val(100) && p4 <= val(115); p1 -= val(1), p2 += val(2), p3 += val(1), p4 += val(2)) {
    delay(400);
    pwm.setPWM(SERVO_1, 0, p1);
    pwm.setPWM(SERVO_2, 0, p2);
    pwm.setPWM(SERVO_10, 0, p3);
    pwm.setPWM(SERVO_11, 0, p4);
  }
}