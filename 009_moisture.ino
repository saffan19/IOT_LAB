int dpin=5;
int apin0=1;
int apinval;
void setup() {
  // put your setup code here, to run once:
pinMode(dpin,INPUT);
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Do value:");
Serial.println(digitalRead(dpin));
Serial.print("A0 value:");
apinval=analogRead(apin0);
Serial.println(apinval);
delay(5000);

}
