// Const to describe when its dark enough to light the LED
const int sensorDark = 500;

//the voltage cell divider pin
int photoCellPin = A0;
int LEDPin = 2;


void setup() {
  pinMode(LEDPin, OUTPUT);
  
}

void loop() {
  int analogValue;

  //Read photocell
  analogValue = analogRead(photoCellPin);
  
  // higher the analog the darker it is
  if (analogValue < sensorDark) {
    digitalWrite(LEDPin, HIGH);  
  }
  else {
    digitalWrite(LEDPin, LOW);
  }

  // wait one ms for better quality sensor readings
  delay(1);
}
