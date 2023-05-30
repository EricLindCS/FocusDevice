#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);   // put your Arduino pin numbers here

#define BUTTON_PIN        2  // Button
#define DELAY            200  // Delay per loop in ms
#define RELAY 3
#define WARNLED 2
#define arm 4
#define ACTLED 5

bool isunp = false;
int timeis = millis();

int enfinvt = 9;

void callRand(){
  lcd.setCursor(0, 1);
  lcd.print("        ");
  lcd.setCursor(0, 1);
 int ran = round(random(0,2) + 1);
 //int ran = 1;
  //Serial.println(ran); //remove before web interface connection
  if (ran == 1){
    lcd.print("Active-A");
    Serial.println("sent to arm");
    digitalWrite(arm, HIGH);
    delay(300);
   digitalWrite(arm, LOW);
  }
  else if (ran == 2){
    lcd.print("Active-R");
    Serial.println("sent to relay");
    digitalWrite(RELAY, HIGH);
    delay(300);
    digitalWrite(RELAY, LOW);
  }
  else {
    
  }
  delay(9000);
}

void setup()
{
  lcd.begin(8, 2); 
  //lcd.print("FocDe1.0");
  
  pinMode(BUTTON_PIN, INPUT);
  pinMode(WARNLED,OUTPUT);
  pinMode(ACTLED,OUTPUT);
  pinMode(arm, OUTPUT);
  pinMode(RELAY, OUTPUT);
  digitalWrite(BUTTON_PIN, HIGH); // pull-up
  Serial.begin(9600);
}

boolean handle_button()
{
  int button_pressed = !digitalRead(BUTTON_PIN); // pin low -> pressed
  return button_pressed;
}

void loop()
{
  lcd.setCursor(0,1);

  boolean button_pressed = handle_button();

  int temp = millis()/1000;
  
  // handle button
 
  if(!button_pressed){
    digitalWrite(WARNLED,HIGH);
    if (!isunp){
      isunp = true;
      timeis = millis() / 1000;
    }
  }
  if(button_pressed && isunp){
    isunp = false;
    digitalWrite(WARNLED,LOW);
    digitalWrite(ACTLED,LOW);
  }
  else if (isunp && temp - timeis > enfinvt){
    callRand();
    timeis = millis() / 1000;
  }

  
  if(button_pressed){
    for(int o=0; o<8; o++){
      lcd.setCursor(o, 1);
      lcd.write(255);
    }
  }
  else{
    lcd.setCursor(0, 1);
    lcd.print("        ");
    long a = (100-(temp - timeis)*100/enfinvt)/8;
    for(int h=0; h<a;h++){
      lcd.setCursor(h, 1);
      lcd.write(255);
    }
  }


  delay(DELAY);
}