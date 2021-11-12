#include<Servo.h>
int dpin=5;
int apin0=A0;
int apinval;

Servo myser;
void setup() {
  // put your setup code here, to run once:
pinMode(dpin,INPUT);
Serial.begin(9600);
myser.attach(9);
}


void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Do value:");
Serial.println(digitalRead(dpin));
Serial.print("A0 value:");
apinval=analogRead(apin0);
Serial.println(apinval);
delay(1000);
if(apinval>1000)
{
  
  for(int pos=0;pos<=180;pos++)
  {
    myser.write(pos);
    delay(10);
  }
  for(int pos=180;pos>=0;pos--)
  {
    myser.write(pos);
    delay(10);
  }
  
}
else
{
  myser.write(0);
}

}
