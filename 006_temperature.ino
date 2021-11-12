int outputpin=0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  int rawvolt=analogRead(outputpin);
  float millivolt=(rawvolt/1024.0)*5000;
  float celsius=millivolt/10;
  Serial.print(celsius);
  Serial.println(" C");
  Serial.print((celsius*9)/5+32);
  Serial.println(" F");
  delay(1000);
  

}
