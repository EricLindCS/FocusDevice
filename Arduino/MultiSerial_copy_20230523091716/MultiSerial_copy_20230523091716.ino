int ledPin1 = 2;  // Pin connected to LED 1
int ledPin2 = 3;  // Pin connected to LED 2
int ledPin3 = 4;  // Pin connected to LED 3

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() >= 3) {
    int value1 = Serial.parseInt();
    int value2 = Serial.parseInt();
    int value3 = Serial.parseInt();

    analogWrite(ledPin1, value1);
    analogWrite(ledPin2, value2);
    analogWrite(ledPin3, value3);
  }
}
