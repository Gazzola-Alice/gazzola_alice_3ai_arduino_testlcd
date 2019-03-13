#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Potamocero");
  lcd.setCursor(0,1);
  lcd.print("Cucciolo");
  //tone(buzzer, 1000, )
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
