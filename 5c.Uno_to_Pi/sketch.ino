#include <ezButton.h>

//ezButton object that attaches to pin 2
ezButton button(2);

//LED setup
const int ledR = 11;
const int ledG = 12;

void powerOffAll() {
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  }

void flicker() {
    digitalWrite(ledR, HIGH);
    delay(100);
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    delay(100);
    digitalWrite(ledG,LOW);
  }

void setup() {
  
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  
  Serial.begin(9600);

  powerOffAll();
  
}

void loop() {
  // Must call the loop function first
  button.loop();
  if(button.isReleased()) {

    Serial.write(42);
    int randomInt = (0, 3);
    while (randomInt < 10) {
      flicker();
      randomInt++;  
    }
    
  }
  
  if (Serial.available() > 0) {
      int ledNumber = Serial.read() - '0';
      Serial.println(ledNumber);


      //I've put delay in these switch statements and its not delaying
      //anything, I think its because the code runs the delay too "quickly"
      switch (ledNumber) {
        case 0:
          digitalWrite(ledR, HIGH);
          break;
        case 1:
          digitalWrite(ledG, HIGH);
          break;
        default:
          break; 
        }
        delay(1500);
        powerOffAll();
    }
    
}