#define BUTTON_PIN        2  // Button
#define DELAY            200  // Delay per loop in ms
#define RELAY 3
#define WARN_LED 8
#define arm 5

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
  pinMode(BUTTON_PIN, INPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
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
  int temp = millis()/1000;
  // handle button
  boolean button_pressed = handle_button();
  if(!button_pressed){
    digitalWrite(8,HIGH);
    if (!isunp){
      isunp = true;
      timeis = millis() / 1000;
    }
  }
  if(button_pressed && isunp){
    isunp = false;
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
  }
  else if (isunp && temp - timeis > enfinvt){
    callRand();
    timeis = millis() / 1000;
  }

  // do other things
 /*
  if(isunp){
  Serial.println(temp-timeis);
  } 
  */  
/*
  // add newline sometimes
  static int counter = 0;
  if ((++counter & 0x3f) == 0)
    Serial.println();
*/
  delay(DELAY);
}