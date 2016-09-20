int PHOTO_PIN = A0;
int PHOTO_PIN = A1;


int current;

void setup() {
  // put your setup code here, to run once:
  //pinMode(BUZ_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(PHOTO_PIN);
  if(reading>800)
  {
    if(current == 0)
      current = 60;
    

    //delay(20);
    analogWrite(BUZ_PIN, current);
  }


  else if (current != 0)
  {
    current = 0;
    analogWrite(BUZ_PIN, current);
  }

  
  
  Serial.println(reading);
}
