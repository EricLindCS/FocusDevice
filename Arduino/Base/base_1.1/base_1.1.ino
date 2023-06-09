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
 int ran = round(random(0,2) + 1);
 //int ran = 1;
  //Serial.println(ran); //remove before web interface connection
  if (ran == 1){
    Serial.println("sent to arm");
    digitalWrite(arm, HIGH);
    delay(300);
   digitalWrite(arm, LOW);
  }
  else if (ran == 2){
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
  lcd.print("FocDe1.0");
  
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
    lcd.setCursor(0,1);
    lcd.print("        ");
  }

  if(button_pressed){
    lcd.print("Safe");
  }
  else{
    lcd.print("!!!");
   
    long a = (temp - timeis)*100/enfinvt;
    if(a < 100){
      lcd.setCursor(5,1);
    }
    else {
      lcd.setCursor(4,1);
    }
     lcd.print(a);


    lcd.setCursor(7,1);
     lcd.print("% ");
     //lcd.write(255);
  }


  delay(DELAY);
}