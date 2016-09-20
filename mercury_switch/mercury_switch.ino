int MS_PIN = 2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MS_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


  int reading = digitalRead(MS_PIN);
  Serial.println(reading);

  delay(100);
}
