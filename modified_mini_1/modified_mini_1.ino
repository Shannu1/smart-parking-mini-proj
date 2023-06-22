










#include <LiquidCrystal.h>

#include <Servo.h>
int servoPin1 = A2;
int servoPin2 = A3;
Servo Servo1;
Servo Servo2;





 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int Ir1 = A0;
 int Ir1val = 0;
 float fltIrc1 = 0;
 const int Ir2 = A1;
 int Ir2val = 0;
 float fltIrc2 = 0;
 
const int LED1 = 8;
const int LED2 = 7;
const int LED3 = 13;
const int LED4 = 10;
const int LED5 = 9;
const int LED6 = 6;
  
void setup() 
{
  pinMode(fltIrc1 , OUTPUT);
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED6 , OUTPUT);
  pinMode(fltIrc2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
   lcd.begin(16,2);
   Serial.begin(9600);
   Servo1.attach(servoPin1);
   Servo2.attach(servoPin2);
}

void loop()
{
  
{
  lcd.setCursor(2,1);
        lcd.print(" welcome ");
  Ir1val = analogRead(Ir1);       // reads the value of the sharp sensor
  fltIrc1 = (6787.0/(Ir1val - 3.0)) -4.0;
  Serial.print(fltIrc1);
  Serial.println(" cm I1"); 
   
  delay(400);     // prints the value of the sensor to the serial monitor
  
  Ir2val = analogRead(Ir2);       // reads the value of the sharp sensor
  fltIrc2 = (6787.0/(Ir2val - 3.0)) -4.0;
  Serial.println(fltIrc2);  
  Serial.println(" cm I2");
  delay(400);     // prints the value of the sensor to the serial monitor
}


if ( fltIrc1 <= 30 )
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED6, LOW);
   lcd.print(" slot1 avail ");
    Servo1.write(90);
    delay(1000);
    
  }
   if ( fltIrc1 > 30 )
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED6, LOW);
    lcd.print(" slot1 no ");
    Servo1.write(90);
    Servo1.write(0);
    delay(1000);
    
  }
  if ( fltIrc1 <= 15) 
  { 
    digitalWrite(LED6, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);
    lcd.setCursor(1,1);
        lcd.print(" Ir1caution ");
    
  }
  
 
  
  
  if ( fltIrc2 <= 30 )
  {
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    Servo2.write(90);
    lcd.print(" slot2 avail ");
    delay(1000);
    
   
  }
   if ( fltIrc2 > 30 )
  {
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
    Servo2.write(90);
    Servo2.write(0);
    lcd.print(" slot2 no ");
    delay(1000);
    
  }
   if (  fltIrc2 <= 15) 
  { 
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, HIGH);
    lcd.print(" Ir2caution ");
    
  }
  
}
