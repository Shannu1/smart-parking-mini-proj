
#include <LiquidCrystal.h>
LiquidCrystal lcd (12,13,5,4,3,2);
int IR_1 = A1; //exit
int IR_2 = A2; //enter
int counter=0;
int currentState=0;
int previousState_1=0;
int previousState_2=0;
int IR_1_op;
int IR_2_op;
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode(IR_1,INPUT);
pinMode(IR_2,INPUT);
lcd.begin (16,2);
}

void loop() {
  // put your main code here, to run repeatedly:

lcd.setCursor (0,0);
lcd.print ("NO.OF CARS:");
lcd.setCursor (0,1);
lcd.print ("CAR");
IR_1_op = digitalRead(IR_1);
IR_2_op = digitalRead(IR_2);
Serial.println(digitalRead(IR_2));
if (IR_1_op == HIGH && IR_2_op == LOW)
{
 currentState=1;  
}
else 
{
  currentState=0;
}
if(currentState!=previousState_1)
{
  if(currentState==1)
  {
    counter=counter+1;
    lcd.setCursor(13,0);
    lcd.print(counter);
     lcd.setCursor(4,1);
    lcd.print("ENTER");
  }
}
  previousState_1=currentState;
  delay (250);  
 Serial.println(counter);
if (IR_1_op == LOW && IR_2_op == HIGH)
{
 currentState=1;  
}
else 
{
  currentState=0;
}
if(currentState!=previousState_2)
{
  if(currentState==1)
  {
    counter=counter-1;
    lcd.setCursor(13,0);
    lcd.print(counter);
     lcd.setCursor(4,1);
    lcd.print("LEAVE");
  }
}
  previousState_2=currentState;
  delay (250);  
 Serial.println(counter); 
}  
