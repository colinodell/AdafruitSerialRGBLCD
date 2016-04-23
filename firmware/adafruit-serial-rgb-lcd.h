#ifndef _ADAFRUIT_SERIAL_RGB_LCD_h
#define _ADAFRUIT_SERIAL_RGB_LCD_h

#include <stdint.h>

#if defined (STM32F2XX)
  #include "application.h"
#else
  #error "This platform is not yet supported."
#endif

class SerialRGBLCD : public Print
{
  public:
    void begin();
    void begin(uint16_t baud);
    void displayOn();
    void displayOff();
    void setBrightness(uint8_t brightness);
    void setContrast(uint8_t contrast);
    void setAutoscroll(bool autoscroll);
    void clear();
    void changeStartupSplash(char *text);
    void setCursor(uint8_t column, uint8_t row);
    void home();
    void cursorBack();
    void cursorForward();
    void setUnderlineCursor(bool underline);
    void setBlockCursor(bool block);
    void setBacklightColor(uint8_t red, uint8_t green, uint8_t blue);
    void setCustomCharacter(uint8_t bank, uint8_t character, uint8_t data[8]);
    void loadCharacterBank(uint8_t bank);
    virtual size_t write(uint8_t);
    void write(String);
};

#endif

