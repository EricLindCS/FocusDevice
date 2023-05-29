/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/

int R6 = 13;
int R8 = 12;
int R5 = 11;
int R7 = 10;
int C2 = 9;
int C3 = 8;
int C5 = 7;
int R3 = 1;
int R1 = 2;
int C4 = 6;
int R4 = 5;
int C1 = 4;
int R2 = 3;

int avgen=0;

int arm = 14;
int potent = 18; 
int phone = 17;
int taser = 16;

int Col[5] = {4,9,8,6,7};
int Row[8] = {2,3,14,5,11,13,10,12};

int senval[3] = {0,0,0};
int sel = 0;

void setup() {
  randomSeed(analogRead(3));
  for (int i = 1; i < 17; i++){
    pinMode(i, OUTPUT);
  }
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
    digitalWrite(arm, HIGH);
    delay(3);
    digitalWrite(arm, LOW);
  }
  else if (ran == 2){
    Serial.println("sent to relay");
    digitalWrite(taser, HIGH);
    delay(3);
    digitalWrite(taser, LOW);
  }
  else {
    
  }
  */
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue =  6; //map(analogRead(potent), 0, 671, 0, 9);
  //Serial.println(analogRead(potent));

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
