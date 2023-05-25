const int ledPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //if (Serial.available() > 0) {
    //int value = Serial.parseInt();
    //if (value > 100) {
      digitalWrite(ledPin, LOW);
   // } else {
   //   digitalWrite(ledPin, LOW);
   // }
   // Serial.println(value); // Echo the received value back to the computer
  //}
}
