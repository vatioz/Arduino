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
  int red = 255-(255/170.0)*reading;
  //Serial.println(red);
  return red;
}

int GetBlueFromReading(int reading)
{
  return (255/170.0)*(reading-85);
}

int GetGreenFromReading(int reading)
{
  if(reading <= 127)
    return (255/67.0)*(reading-60);
  else
    return 255-( (255/72.0)*(reading-128));
}

int Normalize(int output)
{
    if(output > 255)
      return 255;
    if(output < 0)
      return 0;

    return output;
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  reading = analogRead(POT_PIN);

  int converted = reading/4;

  int r = Normalize(GetRedFromReading(converted));
  int g = Normalize(GetGreenFromReading(converted));
  int b = Normalize(GetBlueFromReading(converted));
  
    SetAnalog(r,g,b);
  
    
  if(reading < lastReading-15 || reading > lastReading+15)
  {
    Serial.print(reading);
    Serial.print("/");
    Serial.print(converted);
    Serial.print(" -> ");
    Serial.print("( ");
    Serial.print(r);
    Serial.print(", ");
    Serial.print(g);
    Serial.print(", ");
    Serial.print(b);
    Serial.println(" )");
    lastReading = reading;
  }
  
  
  
}
