
const int LEDPin = 9;    // LED connected to digital pin 9

const int SensorPin = A0;  // pin with the photoresistor with the red gel

int LedValue = 0; // value to write to the red LED

int SensorValue = 0; // variable to hold the value from the red sensor

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  SensorValue = analogRead(SensorPin);
  delay(5);

  LedValue = SensorValue / 4;
  Serial.println(SensorValue);
  LedValue = map(SensorValue, 430, 880, 0, 255);
  if (LedValue < 0){
    LedValue = 0;
  }
  analogWrite(LEDPin, LedValue);
  analogWrite(11, LedValue);
}
