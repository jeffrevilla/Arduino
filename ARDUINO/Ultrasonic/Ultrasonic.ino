const int in1=3;
const int in2=4;
const int in3=5;
const int in4=6;

const int trigPin= 7;
const int echoPin= 8;


float duration,distance,value;

void setup(){

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
}

void loop(){
 value=ping();
  Serial.println(value);
  delay(10);
  if (value<20){
  stp();
  delay(250);
  bwd();
  delay(500);
  rgt();
   delay(500);
  } else {
    fwd();
  }
}

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

int ping(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  return distance;
}