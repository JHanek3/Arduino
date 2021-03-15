// The amount of time in ms the LED stays on
int timer = 100;

void setup() {
  // use a for loop to initialize each pin as an output
  for (int thisPin = 2; thisPin < 8; thisPin++) {
    pinMode(thisPin, OUTPUT);  
  }

}

void loop() {
  // loop for the lowest pin to the highest
  for (int thisPin = 2; thisPin < 8; thisPin++) {
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin, LOW);
  }
  // loop from lowest pin to highest
  for (int thisPin = 7; thisPin > 1; thisPin--) {
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin, LOW);
  }
}
