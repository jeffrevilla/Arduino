#include<Servo.h>
Servo myServo;

const int in1=3;
const int in2=4;
const int in3=5;
const int in4=6;
const int servoPin = 9;
//#define servoPin9

const int trigPin= 7;
const int echoPin= 8;

float duration,distance,value,leftD,rightD;

void setup(){

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
myServo.attach(servoPin);
}

void loop(){
value= ping();
Serial.println(value);
delay(10);

  if (value<20){
    stp(); delay(200);
    bwd(); delay(500);
    stp(); delay(200);
    myServo.write(170); delay(700);
   leftD = ping();
    myServo.write(90); delay(700);
    myServo.write(10); delay(700);
   rightD = ping();
    myServo.write(90); delay(700);
    //left
    if(leftD >= rightD){
      lft(); delay(500);
    stp(); delay(200); 
    }
    //Right
    if(rightD > leftD){
      rgt(); delay(500);
    stp(); delay(200); 
    } else{
      fwd();
    }
    } else{
  fwd();
  }
}
// for motor
void fwd(){
  digitalWrite(in1,LOW);//A
  digitalWrite(in2,HIGH);//B
  digitalWrite(in3,HIGH);//C
  digitalWrite(in4,LOW);//D
 
}

void bwd(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void lft(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void rgt(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void stp(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

//for ultrasonic
int ping() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  return distance;
}

