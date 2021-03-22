
const int sensorMin = 0;
const int sensorMax = 800;

int photoCellPin = A0;

int pinOut = 10;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);

}

void loop() {
  int analogValue;
  int range;

  analogValue = analogRead(photoCellPin);
  range = map(analogValue, sensorMin, sensorMax, 0, 3);

  switch (range)
  {
   case 0:
    Serial.println("dark");
    digitalWrite(pinOut, HIGH);
    break;
   case 1:
    Serial.println("dim");
    digitalWrite(pinOut, HIGH);
    break;
   case 2:
    Serial.println("medium");
    digitalWrite(pinOut, LOW);
    break;
   case 3:
    Serial.println("bright");
    digitalWrite(pinOut, LOW);
    break;
  }
  // Delay 10 seconds is kind of pointless, sensor reads dark then lights the lamp for 10s, lamp turns off, sensor sees dark turns lamp on
  // This would be better as a bluetooth switch or time based like 8pm to 11pm turn on lamp else keep off
  delay(10000);
}