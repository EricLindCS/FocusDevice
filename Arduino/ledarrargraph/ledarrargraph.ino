int R6=13;
int R8 = 12;
int R5=11;
int R7 = 10;
int C2 = 9;
int C3 = 8;
int C5 = 7;
int R3=1;
int R1 = 2;
int C4 = 6;
int R4 = 5;
int C1 = 4;
int R2 = 3;

int Col[5] = {4,9,8,6,7};
int Row[8] = {2,3,14,5,11,13,10,12};

/*int ledarr[8][5];
for (int i = 0; i< 8; i++){
  for (int j = 0; j<5; j++){
    ledarr[]
  }
}
*/



void setup() {
  for (int i = 1; i < 15; i++){
    pinMode(i, OUTPUT);
  }
   Serial.begin(9600);

}


// the loop routine runs over and over again forever:
void loop() {


  for (int i = 0; i < 8; i++){
    digitalWrite(Row[i], LOW);
  }
  for (int j = 0; j < 5; j++){
    digitalWrite(Col[j], HIGH);
  }

  if (Serial.available() > 0) {
    int value = Serial.parseInt();
    


    Serial.println(value); // Echo the received value back to the computer
  }

  // read the input on analog pin 0:
 // int x = map(analogRead(A0), 0, 1023, 0, 7);
 // int y = map(analogRead(A1), 0, 1023, 0, 5);
  // print out the value you read:
  /*
  Serial.print(y);
  Serial.print(" ");
  Serial.println(x);
  */
// read the input on analog pin 0:
  int x = 1;
  int y = 1;

  digitalWrite(Row[x-1], HIGH);
  digitalWrite(Col[y-1], LOW);
 // Serial.println(digitalRead(R3));
  delay(1);  // delay in between reads for stability
  

}
