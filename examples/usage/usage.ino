#include <AdafruitSerialRGBLCD.h>

SerialRGBLCD lcd;

void setup() {
  lcd.begin(9600);
  delay(250);
  lcd.setContrast(220, true);
  lcd.setBrightness(220, true);
  lcd.setAutoscroll(true);
}

void loop() {
  lcd.clear();

  lcd.setBacklightColor(0, 255, 0);  
  lcd.println("Hello World!");
  
  delay(2000);

  lcd.setBacklightColor(64, 64, 200);
  lcd.println("This is a demo");

  delay(2000);
}

