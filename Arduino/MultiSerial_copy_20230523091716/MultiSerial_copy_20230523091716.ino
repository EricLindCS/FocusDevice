int ledPin1 = 2;  // Pin connected to LED 1
int ledPin2 = 3;  // Pin connected to LED 2
int ledPin3 = 4;  // Pin connected to LED 3
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() >= 3) {
    int value1 = Serial.parseInt();
    int value2 = Serial.parseInt();
    int value3 = Serial.parseInt();

    if (value1 > 100) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
/*
    analogWrite(ledPin, value1);
    analogWrite(ledPin2, value2);
    analogWrite(ledPin3, value3);
*/
    Serial.print("Received values: ");
    Serial.print("Slider 1: ");
    Serial.print(value1);
    Serial.print(", Slider 2: ");
    Serial.print(value2);
    Serial.print(", Slider 3: ");
    Serial.println(value3);
  }
}
