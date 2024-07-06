//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
const int buttonPin=2;
const int ledPin=9;

int buttonState=0;
int count_value=0;
int preState=0;
int peopleNum=0;

void setup()
{
pinMode(ledPin,OUTPUT);
pinMode(buttonPin,INPUT);
Serial.begin(9600);;
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("COUNT");
  lcd.setCursor(2,1);
  lcd.print("PERSON");
   lcd.setCursor(0,2);
  lcd.print("TOTAL");
 
}


void loop()
{
    lcd.setCursor(2,3);
  lcd.print(count_value);
buttonState=digitalRead(buttonPin);
if (buttonState == HIGH && preState == 0)
{
count_value++;
Serial.println(count_value);
digitalWrite(ledPin,HIGH);
delay(100);
digitalWrite(ledPin,LOW);

preState=1;
}else if(buttonState == LOW){
preState=0;
}

}
