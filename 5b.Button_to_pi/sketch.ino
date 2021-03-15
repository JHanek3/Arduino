const int BUTTON = 2;
const int LED = 13;

int BUTTONstate = 0;

void setup() {
  pinMode(BUTTON, INPUT);
  // pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    BUTTONstate = digitalRead(BUTTON);
    if (BUTTONstate == HIGH) {
      Serial.print("Button pressed!");
    }
    else {
      Serial.print("Button not pressed!");
    }
}
