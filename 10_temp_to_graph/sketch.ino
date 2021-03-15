int lm35Pin = A0;

void setup()
{
    // set up serial at 9600 baud   
    Serial.begin(9600);
}

void loop()
{ 
    int analogValue;
    float temperature;

    // read our temperature sensor
    analogValue = analogRead(lm35Pin);

    // convert the 10bit analog value to celcius
    temperature = float(analogValue) / 1023;
    temperature = temperature * 500;

    // print the temperature over serial
    Serial.println(temperature);
    
    // wait 1hr before reading the temperature again
    delay(3600000);
}