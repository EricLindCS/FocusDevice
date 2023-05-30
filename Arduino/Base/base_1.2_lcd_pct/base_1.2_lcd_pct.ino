#include <LiquidCrystal.h>

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


#define BUTTON_PIN        6  // Button
#define DELAY            200  // Delay per loop in ms
#define RELAY 7
#define WARNLED 8
#define arm 9
#define ACTLED 10

bool isunp = false;
int timeis = millis();

int enfinvt = 13;

void callRand(){
 int ran = round(random(0,2) + 1);
 //int ran = 1;
  //Serial.println(ran); //remove before web interface connection
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("Status:ACT:");
  if (ran == 1){
    lcd.print("EN-A");
    digitalWrite(arm, HIGH);
    delay(300);
   digitalWrite(arm, LOW);
  }
  else if (ran == 2){
    lcd.print("EN-R");
    digitalWrite(RELAY, HIGH);
    delay(300);
    digitalWrite(RELAY, LOW);
  }
  else {
    
  }
  delay(9000);
  lcd.setCursor(0,1);
  lcd.print("                     ");

}

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 2);
  // Print a message to the LCD.
  lcd.print("Focus Device 1.0");
  
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
   lcd.print("                     ");
  lcd.setCursor(0,1);
  lcd.print("Status:");
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
    lcd.print("Safe");
  }
  else{
    lcd.print("Armed");
    long a = (temp - timeis)*100/enfinvt;
    if(a<1){
      lcd.setCursor(15, 1);
    }
    else if (a<100){
      lcd.setCursor(14, 1);
    }
    else{
      lcd.setCursor(13, 1);
    }
    lcd.print(a);
    lcd.print("%");
  }


  delay(DELAY);
}