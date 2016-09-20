int IR_PIN = 13;

#include <IRremote.h>
IRrecv irrecv(IR_PIN);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR_PIN, INPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {

  // put your main code here, to run repeatedly:
if (irrecv.decode(&results)) // have we received an IR signal?
 
  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}/* --(end main loop )-- */
 
/*-----( Function )-----*/
void translateIR() // takes action based on IR code received
 
// describing Remote IR codes 
 
{
 
  switch(results.value)
 
  {
 
  case 0xFF629D: Serial.println(" CH"); break;
  case 0xFF22DD: Serial.println(" PREV");    break;
  case 0xFF02FD: Serial.println(" NEXT");    break;
  case 0xFFC23D: Serial.println(" PLAY");   break;
  case 0xFFA857: Serial.println(" VOL-"); break;
  case 0xFF6897: Serial.println(" 0");    break;
  case 0xFF9867: Serial.println(" 100+");    break;
  case 0xFFB04F: Serial.println(" 200+");    break;
  case 0xFF30CF: Serial.println(" 1");    break;
  case 0xFF18E7: Serial.println(" 2");    break;
  case 0xFF7A85: Serial.println(" 3");    break;
  case 0xFF10EF: Serial.println(" 4");    break;
  case 0xFF38C7: Serial.println(" 5");    break;
  case 0xFF5AA5: Serial.println(" 6");    break;
  case 0xFF42BD: Serial.println(" 7");    break;
  case 0xFF4AB5: Serial.println(" 8");    break;
  case 0xFF52AD: Serial.println(" 9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  
 case 0xFFA25D: Serial.println(" CH-");break;  
 case 0xFFE21D: Serial.println(" CH+");break;
 case 0x0000FF: Serial.println(" PLAY");break;  
 case 0xFFE01F: Serial.println(" VOL+");break;  
 case 0xFF906F: Serial.println(" EQ");break;  
  default: 
    Serial.print(" other button: ");
    Serial.println(results.value);
 
  }// End Case
 
  delay(500); // Do not get immediate repeat
 
 
} //END translateIR
