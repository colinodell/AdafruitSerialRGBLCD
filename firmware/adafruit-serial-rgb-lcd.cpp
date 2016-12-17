#include "adafruit-serial-rgb-lcd.h"

void SerialRGBLCD::begin()
{
  begin(9600);
}

void SerialRGBLCD::begin(uint16_t baud)
{
  #if defined (STM32F2XX)
    Serial1.begin(baud);
  #else
    Serial.begin(baud);
  #endif
}

void SerialRGBLCD::displayOn()
{
  write(0xFE);
  write(0x42);

  delay(0.3);
}

void SerialRGBLCD::displayOff()
{
  write(0xFE);
  write(0x46);

  delay(0.3);
}

void SerialRGBLCD::setBrightness(uint8_t brightness, bool saveToEEPROM = false)
{
  write(0xFE);
  if (saveToEEPROM) {
    write(0x98);
  } else {
    write(0x99);
  }
  write(brightness);
}

void SerialRGBLCD::setContrast(uint8_t contrast, bool saveToEEPROM = false)
{
  write(0xFE);
  if (saveToEEPROM) {
    write(0x91);
  } else {
    write(0x50);
  }
  write(contrast);
}

void SerialRGBLCD::setAutoscroll(bool autoscroll)
{
  write(0xFE);
  if (autoscroll) {
    write(0x51);
  } else {
    write(0x52);
  }
}

void SerialRGBLCD::clear()
{
  write(0xFE);
  write(0x58);
}

void SerialRGBLCD::changeStartupSplash(char *text)
{
  write(0xFE);
  write(0x40);

  for (char *c = text; *c; ++c) {
    write(*c);
  }
}

void SerialRGBLCD::setCursor(uint8_t column, uint8_t row)
{
  write(0xFE);
  write(0x47);
  write(column);
  write(row);
}

void SerialRGBLCD::home()
{
  write(0xFE);
  write(0x48);
}

void SerialRGBLCD::cursorBack()
{
  write(0xFE);
  write(0x4C);
}

void SerialRGBLCD::cursorForward()
{
  write(0xFE);
  write(0x4D);
}

void SerialRGBLCD::setUnderlineCursor(bool underline)
{
  write(0xFE);
  if (underline) {
    write(0x4A);
  } else {
    write(0x4B);
  }
}

void SerialRGBLCD::setBlockCursor(bool block)
{
  write(0xFE);
  if (block) {
    write(0x53);
  } else {
    write(0x54);
  }
}

void SerialRGBLCD::setBacklightColor(uint8_t red, uint8_t green, uint8_t blue)
{
  write(0xFE);
  write(0xD0);
  write(red);
  write(green);
  write(blue);
}

void SerialRGBLCD::setCustomCharacter(uint8_t bank, uint8_t character, uint8_t data[8])
{
  write(0xFE);
  write(0xC1);
  write(bank);
  write(character);
    
  for (int i = 0; i < 8; i++) {
    write(data[i]);
  }
}

void SerialRGBLCD::loadCharacterBank(uint8_t bank)
{
  write(0xFE);
  write(0xC0);
  write(bank);
}

size_t SerialRGBLCD::write(uint8_t character)
{
  #if defined (STM32F2XX)
    Serial1.write(character);
  #else
    Serial.write(character);
  #endif
}

void SerialRGBLCD::write(String text)
{
  for (int i = 0; i < text.length(); i++) {
    write(text.charAt(i));
  }
}

