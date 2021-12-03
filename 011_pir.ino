int Cali=15;
long unsigned int lowIn;
long unsigned int pause=1000;
boolean lockLow=true;
boolean takeLowTime;
int pirPin=3;
int ledPin=13;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin,INPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(pirPin,LOW);

  Serial.print("Calibrating sensor");
  for(int i=0;i<Cali;i++)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.print("done");
  Serial.print("Sensor Active");
  delay(50);
  

}

void loop() {
  if(digitalRead(pirPin)==HIGH)
  {
    digitalWrite(ledPin,HIGH);
    if(lockLow)
    {
      lockLow=false;
      Serial.println("---");
      Serial.print("Motion detected at");
      Serial.print(millis()/1000);
      Serial.println("sec");
      delay(50);
    }
    takeLowTime=true;
  }
 
  
  if(digitalRead(pirPin)==LOW)
  {
    digitalWrite(ledPin,LOW);
    if(takeLowTime)
    {
      lowIn=millis();
      takeLowTime=false;
    }
    if(!lockLow&&millis()-lowIn>pause)
    {
      lockLow=true;
      Serial.print("motion ended at :");
      Serial.print((millis()-pause)/1000);
      Serial.println("sec");
      delay(50);
    }
    
  }

}
