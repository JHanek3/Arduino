int LEDRedPin = 5;
int LEDGreenPin = 4;
int LEDWhitePin = 3;
int LEDYellowPin = 2;

void setup() {
  // Listening over serial
  Serial.begin(9600);
  // LED pins are output
  pinMode(LEDRedPin, OUTPUT);
  pinMode(LEDGreenPin, OUTPUT);
  pinMode(LEDWhitePin, OUTPUT);
  pinMode(LEDYellowPin, OUTPUT);
  
}

void toggleLED(int LEDPin) {
  // toggle the led 
  digitalWrite(LEDPin, !digitalRead(LEDPin));  
}

void loop() {
  if (Serial.available() > 0) {

    //read single char over serial
    int inByte = Serial.parseInt();

    // do something regarding intByte
    switch (inByte) {

      case 1:
        toggleLED(LEDRedPin);
        break;
      
      case 2:
        toggleLED(LEDGreenPin);
        break;
      
      case 3:
        toggleLED(LEDWhitePin);
        break;

      case 4:
        toggleLED(LEDYellowPin);
        break;

      default:
      // turn everything off
      
        digitalWrite(LEDRedPin, LOW);
        digitalWrite(LEDGreenPin, LOW);
        digitalWrite(LEDYellowPin, LOW);
        digitalWrite(LEDWhitePin, LOW);
        break;
    }
  }
}
