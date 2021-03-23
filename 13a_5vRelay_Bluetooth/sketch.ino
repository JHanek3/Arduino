int pinOut = 10;

char state;

void setup() {
  Serial.begin(9600);
  pinMode(pinOut, OUTPUT);
  digitalWrite(pinOut, LOW);
}

void loop() {
  if(Serial.available() > 0) {
    state = Serial.read();
  }
  Serial.println(state);
  switch(state) {
    case 'D':
      digitalWrite(pinOut, HIGH);
      break;
    case 'd':
      digitalWrite(pinOut, LOW);
      break;
    default:
      break;
  }
  delay(50);
}