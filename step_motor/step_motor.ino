/*
   BYJ48 Stepper motor code
   Connect :
   IN1 >> D8
   IN2 >> D9
   IN3 >> D10
   IN4 >> D11
   VCC ... 5V Prefer to use external 5V Source
   Gnd
   written By :Mohannad Rawashdeh
  http://www.instructables.com/member/Mohannad+Rawashdeh/
     28/9/2013
  */

int L_BTN = 13;
int R_BTN = 12;

int currentlyOpen = false;
#define closeCurtains false
#define openCurtains true
#define revolutionsToCloseCurtains 2
#define revolutionsToOpenCurtains 2

int PHOTO1_PIN = A0;
int PHOTO2_PIN = A1;

#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11
int Steps = 0;
boolean Direction = true;// gre
unsigned long last_time;
unsigned long currentMillis ;
int steps_left=4095;
long time;

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);
}
void loop()
{
  
  int outside = analogRead(PHOTO1_PIN);
  int inside = analogRead(PHOTO2_PIN);

  // inside when lights on ~ 600
  // outside when lights on ~ 400


  if(currentlyOpen && inside > outside + 100 )
  {
    Serial.print("Inside: ");
    Serial.print(inside);
    Serial.print(" / Outside: ");
    Serial.print(outside);
    Serial.println(" -> Closing curtains...");
    Direction = closeCurtains;
    doRevolutions(revolutionsToCloseCurtains);
    currentlyOpen = false;    
  }
  else if(!currentlyOpen && outside > inside + 100)
  {
    Serial.print("Inside: ");
    Serial.print(inside);
    Serial.print(" / Outside: ");
    Serial.print(outside);
    Serial.println(" -> Opening curtains...");
    Direction = openCurtains;
    doRevolutions(revolutionsToOpenCurtains);
    currentlyOpen = true;
  } 
}

void doRevolutions(int numberOfRevolutions)
{
  steps_left = numberOfRevolutions * 4095;
  
  while(steps_left >= 0)
  {  
    currentMillis = micros();
    if(currentMillis-last_time>=1000) //min 800 = quickest (cca rev per 4s), 2000 = rev per 8s
    {
      stepper(1); 
      time=time+micros()-last_time;
      last_time=micros();
      steps_left--;    
    }
  }  
}


void stepper(int xw)
{
  for (int x=0;x<xw;x++)
  {
    switch(Steps)
    {
       case 0:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
       break; 
       case 1:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, HIGH);
       break; 
       case 2:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
       break; 
       case 3:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
       break; 
       case 4:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
       case 5:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
         case 6:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
       case 7:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
       break; 
       default:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
    }
    SetDirection();
  }
} 
void SetDirection()
{
  if(Direction==1){ Steps++;}
  if(Direction==0){ Steps--; }
  if(Steps>7){Steps=0;}
  if(Steps<0){Steps=7; }
}
