#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int buzzer = 6;   
int bottone=8;
int numero; 
int numeroled; 
int led = 9;
double tempobuzzer;
double tempobuzzerinizio;
double tempoled;
double tempoledinizio;
bool aled = false;
double valorebuzzer;
double valoreled;
int stato;
void setup(){
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  lcd.begin(16,2);
  numero = random(1500,5000);
  numeroled = random(1500,5000);
  lcd.setCursor(0,0);
  lcd.print("Click the");
  lcd.setCursor(0,1);
  lcd.print("buttun!");
  stato=0;
}
void loop(){
  stato= digitalRead(bottone);
  if(stato == HIGH){
      avvioled(); 
      } 
      if(aled==true){
        avviobuzzer();
        }
  }
  void avvioled(){
     lcd.clear();
     stato= LOW;
    delay(numeroled);
    tempoledinizio = millis();
     digitalWrite(led, HIGH);
    while (stato==LOW){
      stato= digitalRead(bottone);
    if (stato==HIGH){
      aled=true;
  digitalWrite(led, LOW);
 }
   }
 tempoled = millis();
 valoreled = tempoled-tempoledinizio;
 lcd.setCursor(0,0);
 lcd.print((valoreled/1000));
 lcd.setCursor(4,0);
 lcd.print("s");
 if (valoreled<=250){
  lcd.setCursor(7,0);
  lcd.print("Good ");
 }
 else {
  lcd.setCursor(7,0);
  lcd.print("Bad ");
 }
}
void avviobuzzer(){
    stato= LOW;
  delay(numero);
  tone(buzzer,1000);
  tempobuzzerinizio= millis();
 while (stato==LOW){
   stato= digitalRead(bottone);
    if (stato==HIGH){
    noTone(buzzer);
    tempobuzzer= millis();
   } 
} 
valorebuzzer=tempobuzzer-tempobuzzerinizio;
lcd.setCursor(0,1);
lcd.print(valorebuzzer/1000);
lcd.setCursor(4,1);
lcd.print("s"); 
if (valorebuzzer<=250){
  lcd.setCursor(7,1);
  lcd.print("Good ");
 }
 else {
  
  lcd.setCursor(7,1);
  lcd.print("Bad ");
 }
delay(5000);
aled=false;
setup();
 }

   


  
  
