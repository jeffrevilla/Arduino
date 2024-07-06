int in1 =2;
int in2 =3;
int in3 =4;
int in4 =5;

void setup (){
 pinMode (in1, OUTPUT);
 pinMode (in2, OUTPUT);
 pinMode (in3, OUTPUT);
 pinMode (in3, OUTPUT);
 
}

void loop () {
  
fwd ();
delay(2000);
rgt ();
delay(725);
fwd();
delay(2000);
lft ();
delay(725);
fwd();
delay(2000);
lft ();
delay(725);
fwd();
delay(2000);
rgt ();
delay(725);
fwd();
delay(2000);
stp ();
delay(5000);
}

void fwd (){
  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH);
  digitalWrite (in3, LOW);
  digitalWrite (in4, HIGH);
}
void lft (){
  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH);
  digitalWrite (in3, LOW);
  digitalWrite (in4, LOW);
}

void rgt (){
  digitalWrite (in1, LOW);
  digitalWrite (in2, LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4, HIGH);
}

void stp (){
  digitalWrite (in1, LOW);
  digitalWrite (in2, LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4, LOW);
}
