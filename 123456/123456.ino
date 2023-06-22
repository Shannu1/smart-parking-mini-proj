

#include "LiquidCrystal.h"
const int Ir1 = 0;
 int Ir1val = A0;
 const int Ir2 = 0;
 int Ir2val = A0;
 LiquidCrystal lcd(12, 11, 9, 10, 13, 2);

 
const int LED1 = 8;
const int LED2 = 7;
const int LED3 = 3;
const int LED4 = 4;
const int LED5 = 5;
const int LED6 = 6;
  
void setup() 
{
  pinMode(Ir1val , OUTPUT);
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED6 , OUTPUT);
  pinMode(Ir2val , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  lcd.begin(16,2);


}

void loop()
{
  
{
  Ir1val = analogRead(Ir1);       // reads the value of the sharp sensor
  Serial.println(Ir1val);  
  delay(400);     // prints the value of the sensor to the serial monitor
  Ir2val = analogRead(Ir2);       // reads the value of the sharp sensor
  Serial.println(Ir2val);  
  delay(400);     // prints the value of the sensor to the serial monitor
}


if ( Ir1val <= 20 )
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED6, LOW);
    lcd.clear();
  }
   if ( Ir1val > 20 )
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED6, LOW);
  }
  if ( Ir1val <= 10) 
  { 
    digitalWrite(LED6, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);
    lcd.setCursor(2, 0);
    lcd.print(" Ir1caution ");

    delay(400);  
  }
  
 
  
  
  if ( Ir2val <= 20 )
  {
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    lcd.clear();
   
  }
   if ( Ir2val > 20 )
  {
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
  }
   if (  Ir2val <= 10) 
  { 
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, HIGH);
    lcd.setCursor(2, 1);
    lcd.print(" Ir2caution ");
    
   

   
    delay(400);
  }
  
}
