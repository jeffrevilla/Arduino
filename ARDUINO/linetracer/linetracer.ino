int leftSensorPin= 7;
int rightSensorPin=2;

int in1=3;
int in2=4;
int in3=5;
int in4=6;

void setup(){
  Serial.begin(9600);
  pinMode(leftSensorPin,INPUT);
  pinMode(rightSensorPin,INPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void loop(){

  int leftSensorValue=digitalRead(leftSensorPin);
  int rightSensorValue=digitalRead(rightSensorPin);

  if(leftSensorValue==LOW && rightSensorValue==LOW){
   Serial.println("00");
   fwd();
  }
  else if(leftSensorValue==HIGH && rightSensorValue==LOW){
   Serial.println("10");
   rgt();
  }
  
   else if(leftSensorValue==LOW && rightSensorValue==HIGH) {
    Serial.println("01");
    lft();
   }
   else {
    stp();
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
