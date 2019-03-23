    #include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int buzzer = 6;   
int bottone=8;
int numero; 
int numeroled; 
int led = 9;
int ledrosso=13;
int ledverde= 7;
double tempobuzzer;
double tempobuzzerinizio;
double tempoled;
double tempoledinizio;
bool aled = false;
double valorebuzzer;
double valoreled;
bool ledd=true;
bool buzzerr= true;
int stato;
void setup(){
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(ledverde,OUTPUT);
  pinMode(ledrosso,OUTPUT);
  lcd.begin(16,2);
  numero = random(1500,5000);
  numeroled = random(1500,5000);
  delay(100);
  lcd.setCursor(0,0);
  lcd.print("Click the");
  lcd.setCursor(0,1);
  lcd.print("button!");
  stato=0;
  ledd=true;
buzzerr= true;
}
void loop(){
  stato= digitalRead(bottone);
  if(stato == HIGH){
      avvioled(); 
      } 
      if(aled==true){
        avviobuzzer();
        }
 digitalWrite(ledverde, LOW);
digitalWrite(ledrosso, LOW);

      
  }
  void accendiledfinale(){
    if (ledd== true && buzzerr== true){
     digitalWrite(ledverde, HIGH);
    }
    else {
       digitalWrite(ledrosso, HIGH);
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
  lcd.print(":)");
   ledd=true;
 }
 else {
  lcd.setCursor(7,0);
  lcd.print(":( ");
  ledd=false;
 }

}
void avviobuzzer(){
   aled=false;
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
  buzzerr= true;
  lcd.setCursor(6,1);
  lcd.print(":)");
 }
 else {
  buzzerr= false;
  lcd.setCursor(6,1);
  lcd.print(":(");
 } if (ledd==true && buzzerr==true){
     digitalWrite(ledverde, HIGH);
    }
    else {
       digitalWrite(ledrosso, HIGH);
      }
 
delay(3000);
        esamefinito();
 }

 void esamefinito(){
  lcd.setCursor(10,0);
  lcd.print("NEW");
    lcd.setCursor(9,1);
  lcd.print("TEST");
 while (stato==LOW){
   stato= digitalRead(bottone);
  if (stato== HIGH){
    delay(3000);
   setup();
    }
  }
  }
 

 
   


  
  
