int sensorValue=0;
int outputValue=0;
int analogOutPin=9;
int analogPin=A0;

void setup() {
Serial.begin(9600);
}

void loop() {
  sensorValue=analogRead(analogPin);
  outputValue=map(sensorValue,0,1023,0,255);
  analogWrite(analogOutPin,outputValue);
  Serial.println(sensorValue);
  Serial.println(outputValue);
  delay(1000);
}
