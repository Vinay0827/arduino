#include <NewPing.h>

#define SONAR_NUM     2
#define MAX_DISTANCE 800
#define PING_INTERVAL 33

#define trigPin1      6
#define echoPin1      5
#define trigPin2      11
#define echoPin2      10
#define LM1           2
#define LM2           3
#define RM1           7
#define RM2           8

int rangeFront = 0;
int rangeWall  = 0;

NewPing sonar[SONAR_NUM] = {
  NewPing(trigPin1, echoPin1, MAX_DISTANCE),
  NewPing(trigPin2, echoPin2, MAX_DISTANCE)
};

void setup() {
  Serial.begin(9600);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  digitalWrite(trigPin1, LOW);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  digitalWrite(trigPin2, LOW);
}

int toCloseWall = 1800;
int toFarWall = 2500;
int toCloseFront = 1000;

void loop() {
  Main:
  rangeFront = readRangeFront();
  Serial.print(rangeFront);
  Serial.print(" Front");
  Serial.println();
  
  rangeWall = readRangeWall();
  Serial.print(rangeWall);
  Serial.print(" Wall");
  Serial.println();
  
  if (rangeFront <= 400) {
    rangeFront = 3000;
  }
  
  if (rangeWall <= 400) {
    rangeWall = 3000;
  }
  
  if (rangeFront < toCloseFront) {
    delay(500);
    drive_backward();
    delay(500);
    Serial.print(" Drive Back");
    // turn_right();
    Serial.print(" Right Turn");
    Serial.println();
    delay(800);
    drive_forward();
    turn_left();
    delay(1700);
    goto Main;
  }
  
  if (rangeWall > toCloseWall && rangeWall < toFarWall) {
    drive_forward();
    Serial.print(" Drive Forward");
    Serial.println();
    goto Main;
  }
  
  if (rangeWall < toCloseWall) {
    delay(100);
    // turn_left();
    turn_right();
    delay(500);
    Serial.print(" Turn Left");
    drive_forward();
    Serial.print(" Drive Forward");
    Serial.println();
    goto Main;
  }
  
  if (rangeWall > toFarWall) {
    delay(100);
    // turn_right();
    turn_left();
    Serial.print(" Turn Right");
    delay(500);
    drive_forward();
    Serial.print(" Drive Forward");
    Serial.println();
    goto Main;
  }
}

void motor_stop() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void drive_forward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void drive_backward() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

void turn_left() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void turn_right() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

int readRangeFront() {
  delay(50);
  unsigned int rangeFront = sonar[0].ping();
  sonar[0].timer_stop();
  return rangeFront;
}

int readRangeWall() {
  delay(50);
  unsigned int rangeWall = sonar[1].ping();
  sonar[1].timer_stop();
  return rangeWall;
}
