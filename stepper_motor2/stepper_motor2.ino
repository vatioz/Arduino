int L_BTN = 13;
int R_BTN = 12;

#include <Stepper.h>

const int stepsPerRevolution = 4096;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


int stepCount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(1);
  pinMode(L_BTN, INPUT);
  pinMode(R_BTN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int direction = 1;
  int left = digitalRead(L_BTN);
  //Serial.println(left);
  int right = digitalRead(R_BTN);
  //Serial.println(right);
  if(left==1)
    direction = -1000; // change of direction doesn't work on my BYJ48 motor
  else if (right == 1)
    direction = 1000;
  else
    return;

  
  myStepper.step(direction);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount += direction;

  
  
}
