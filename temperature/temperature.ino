int TM_PIN = A0;
int last_reading_time = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //analogReference(INTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:

  int now = millis();
  if(now - last_reading_time > 1000) // only measure with 1s delay
  {
    int reading = analogRead(TM_PIN);
    //int temp = reading / 9.31; 
    int temp = (5.0 * reading * 100.0) / 1024;
    Serial.println(reading);
    last_reading_time = now;
  }
}
