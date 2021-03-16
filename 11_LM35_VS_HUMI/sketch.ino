#include <dht.h>

dht DHT;

int DHT11_PIN = 5;
int lm35Pin = A0;

void setup(){
  Serial.begin(115200);
}

void loop(){
  int analogValue;
  float temperature;

  // read our temperature sensors
  analogValue = analogRead(lm35Pin);
  float chk = DHT.read11(DHT11_PIN);

  // convert the 10bit analog value to celcius for the LM35
  temperature = float(analogValue) / 1023;
  temperature = temperature * 500;

  // print the temperature over serial, i just want the data so im gonna shave this
////  Serial.println("lm35: " + String(temperature) + "\n" + "humi: " + String(DHT.temperature));
//  Serial.println("lm35: " + String(temperature));
//  Serial.println("humi: " + String(DHT.temperature));
//  Serial.println("Humidity: " + String(DHT.humidity));
  Serial.println(String(temperature) + " " + String(DHT.temperature) + " " + String(DHT.humidity));
  // wait an hour 3600000, or wait 5seconds
  delay(5000);
}