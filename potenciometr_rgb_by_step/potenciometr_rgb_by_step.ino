int RLED_PIN = 3;
int GLED_PIN = 5;
int BLED_PIN = 6;
int reading;
int lastReading;
int POT_PIN = A0;

int INTENSITY = 140;

void SetAnalog(int r, int g, int b)
{
  analogWrite(RLED_PIN, r);
  analogWrite(GLED_PIN, g);
  analogWrite(BLED_PIN, b);
}

int GetRedFromReading(int reading)
{
  return 255-(255/170)*reading;
}

int GetBlueFromReading(int reading)
{
  return 255/170*(reading-85);
}

int GetGreenFromReading(int reading)
{
  if(reading <= 127)
    return 255/67*(reading-60);
  else
    return 255-(255/72*(reading-128));
}

int Normalize(int output)
{
    if(output > 255)
      return 255;
    if(output < 0)
      return 0;
}
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  reading = analogRead(POT_PIN);

  int converted = reading/4;

  if(converted < 80)
    SetAnalog(INTENSITY, 0, 0);
  else if(converted < 160)
    SetAnalog(0, INTENSITY, 0);
  else
    SetAnalog(0, 0, INTENSITY);
    
  if(reading < lastReading-15 || reading > lastReading+15)
  {
    Serial.print(reading);
    Serial.print(" -> ");
    Serial.println(converted);
    lastReading = reading;
  }
  
  
  
}
