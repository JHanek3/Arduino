// Pin the potentiometer is attached to
int potPin = A0;

// Array of numbers the LEDs are attached to
int ledPins[] = {2,3,4,5,6,7};

//The number of leds in the bar graph
int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }

}

void loop() {
  // read the potentiometer
  int potReading = analogRead(potPin);
  // map the result to a range from 0 to the number of LEDs
  int ledLevel = map(potReading, 0, 1023, 0, ledCount);

  // loop over the led array
  for (int thisLed= 0; thisLed < ledCount; thisLed++){
    // if the array element's index is less than ledLevel, turn the pin for this
    // element on
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    } else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  } 
}
