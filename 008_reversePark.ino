const int trig=8;
const int echo=7;
int duration=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(trig,OUTPUT);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  pinMode(echo,INPUT);
  duration=pulseIn(echo,HIGH);
  int inches=microsecondsToInches(duration);
  int cm=microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.println(" in");
  Serial.print(cm);
  Serial.println(" cm");
  delay(100);
  if(cm<10)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
}
long microsecondsToInches(long ms)
{
  return ms/74/2;
}
long microsecondsToCentimeters(long ms)
{
  return ms/29/2;
}



