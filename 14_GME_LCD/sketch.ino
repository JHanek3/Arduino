// include the library code:
#include <LiquidCrystal.h>
String gmeCurrent = "";
String gmeVariable = "";

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("GME TO THE MOON");
  

}

void loop() {
  
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    int commaIndex = data.indexOf(",");
    String gmeCurrent = data.substring(0, commaIndex);
    String gmeVariable = data.substring(commaIndex + 1, data.length());
    lcd.clear();
    lcd.setCursor(0,0);
    if (gmeVariable == "pre") {
      lcd.print("PreMarket");
      lcd.setCursor(0,1);
      lcd.print("GME: $" + gmeCurrent);
    } else if (gmeVariable == "pos") {
      lcd.print("PostMarket");
      lcd.setCursor(0,1);
      lcd.print("GME: $" + gmeCurrent);
    } else if (gmeVariable == "close") {
      lcd.print("Market Closed");
      lcd.setCursor(0,1);
      lcd.print("GME: $" + gmeCurrent);
    } else {
      lcd.print("GME: $" + gmeCurrent);
      lcd.setCursor(0,1);
      lcd.print("% Change: " + gmeVariable);
    }
  }
}
