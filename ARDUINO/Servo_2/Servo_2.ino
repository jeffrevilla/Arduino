#include <Servo.h>
Servo myServo;

const int in1 = 3;
const int in2 = 4;
const int in3 = 5;
const int in4 = 6;
const int servoPin = 9;

const int trigPin = 7;
const int echoPin = 8;

float duration, distance, value;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  value = ping();
  Serial.println(value);
  delay(10);



  if (value < 20) {
    stp(); // Add missing semicolon
    delay(200);
    bwd();
    delay(500);
    stp();
    delay(200);
    myServo.write(170);
    delay(500);
    myServo.write(90);
    delay(500);
    myServo.write(10);
    delay(500);
    myServo.write(90); // Change "left()" to "lft()" to match the function name
    delay(500);
    lft(); // Change "left()" to "lft()" to match the function name
    delay(500);
    stp();
    delay(200);
  }  else{
    fwd();
  }
}

// for motor
void fwd() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void bwd() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void lft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void rgt() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stp() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// for ultrasonic
int ping() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
