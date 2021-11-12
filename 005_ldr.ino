int ldrvalue=0;
int light_sensitivity=40;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
ldrvalue=analogRead(A0);
delay(10);
Serial.println(ldrvalue);
if(ldrvalue<light_sensitivity)
{
  digitalWrite(9,HIGH);
  
}
else
{
  digitalWrite(9,LOW);
}
}
