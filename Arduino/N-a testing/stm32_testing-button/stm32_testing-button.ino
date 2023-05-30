/*
  Blink onboard LED at 0.1 second interval
*/

#define BUTTON_PIN PB3
void setup()
{
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(PC13, OUTPUT);
}
void loop()
{
  if(digitalRead(BUTTON_PIN)){
    digitalWrite(PC13, HIGH);
  }
  else{
    digitalWrite(PC13, LOW);
  }

  delay(100);
}
