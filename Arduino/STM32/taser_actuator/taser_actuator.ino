/*
  Blink onboard LED at 0.1 second interval
*/

bool isArmed = false;

#define BUTTON_PIN PB3
#define INPIN PB9





#define WARNLED PB4
#define ACTLED PB8
#define RELAY PB7
#define ONLED  PB6

void setup()
{ 
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(ONLED, OUTPUT);
  pinMode(WARNLED, OUTPUT);
  pinMode(ACTLED, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(INPIN, INPUT);
 // delay(100);
  digitalWrite(RELAY, HIGH);
}
void loop()
{
  
  digitalWrite(ONLED, HIGH);

  if(digitalRead(BUTTON_PIN)){
    digitalWrite(WARNLED, HIGH);
    isArmed = true;
  }
  else{
    digitalWrite(WARNLED, LOW);
    isArmed = false;
  }

  if(digitalRead(INPIN) == HIGH){
    digitalWrite(ACTLED, HIGH);
    if(isArmed){
      digitalWrite(RELAY, LOW);
    }
    delay(100);
    digitalWrite(ACTLED, LOW);
    digitalWrite(RELAY, HIGH); 
  }
  
  /*
  if(digitalRead(INPIN) == HIGH){
    digitalWrite(WARNLED, HIGH);

  }
  else {
    digitalWrite(WARNLED, LOW);
  }if(digitalRead(INPIN)){
    digitalWrite(ONLED, HIGH);

  }
  else {
    digitalWrite(ONLED, LOW);
  }
  */
  delay(100);
}
