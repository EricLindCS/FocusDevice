int arm = 0;
bool isunp = false;
int timeis = millis();

#define BUTTON_PIN 2;
#define RELAY 7;
#define WARN_LED 8;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT)
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(BUTTON_PIN, HIGH); // pull-up
  Serial.begin(9600);
}




// the loop routine runs over and over again forever:


void writeCol(int col, int lev) {

  for (int i = 0; i < 8; i++){
    digitalWrite(Row[i], LOW);
  }
  for (int j = 0; j < 5; j++){
    digitalWrite(Col[j], HIGH);
  }

  int x = col;
  int y = lev;

  for (int k=0; k < x; k++){
    digitalWrite(Row[x-1], HIGH);
  }

  digitalWrite(Col[y-1], LOW);

}

void callRand(){
 int ran = round(random(0,2) + 1);
 //int ran = 1;
  //Serial.println(ran); //remove before web interface connection
  if (ran == 1){
    Serial.println("sent to arm");
    //digitalWrite(arm, HIGH);
    delay(3);
   // digitalWrite(arm, LOW);
  }
  else if (ran == 2){
    Serial.println("sent to relay");
    digitalWrite(RELAY, HIGH);
    delay(30);
    digitalWrite(RELAY, LOW);
  }
  else {
    
  }
  */
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  //int sensorValue =  6; //map(analogRead(potent), 0, 671, 0, 9);
  Serial.println(analogRead(potent));

  senval[sel] = sensorValue;

  avgen=0;
  
/*
  if(!isblank(senval[sizeof(senval)-1])){
    for (int g=0; g < sizeof(senval); g++){
      avgen += senval[g];
    }
    //avgen/=sizeof(senval);
    //Serial.println(avgen + " " + sensorValue);
  }
*/

    avgen = senval[0] + senval[1] + senval[2];
    avgen/=3.0;

    //avgen/=sizeof(senval);
    //Serial.println(avgen + " " + sensorValue);

  if (sel != 3){
    sel++;
  }
  else{
    sel = 0;
   // Serial.println(senval[sel]);
  }
  Serial.println(avgen);

  if (avgen < 5){
    Serial.println("rand called");
    callRand();
   delay(8000);
  }

  delay(300);  // delay in between reads for stability

}
