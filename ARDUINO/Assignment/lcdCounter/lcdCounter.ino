
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Replace with your LCD's I2C address if different

const int countUpButtonPin = 2;
const int countDownButtonPin = 3;
int count = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  
  pinMode(countUpButtonPin, INPUT_PULLUP);
  pinMode(countDownButtonPin, INPUT_PULLUP);
  
  lcd.setCursor(0, 0);
  lcd.print("Count: ");
}

void loop() {
  if (digitalRead(countUpButtonPin) == LOW) {
    count++;
    updateLCD();
    delay(200); // Debounce delay
    while (digitalRead(countUpButtonPin)== LOW);
  }

  if (digitalRead(countDownButtonPin) == LOW && count > 0) {
    count--;
    updateLCD();
    delay(200); // Debounce delay
    while (digitalRead(countDownButtonPin)== LOW);
  }
}

void updateLCD() {
  lcd.setCursor(7, 0);
  lcd.print("    "); // Clear previous count
  lcd.setCursor(7, 0);
  lcd.print(count);
}
