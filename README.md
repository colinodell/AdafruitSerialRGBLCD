# adafruit-serial-rgb-lcd
Firmware library for Adafruit's USB + Serial Backpack Kit with 16x2 RGB LCD

This library only supports the TTL serial connection.

## Supported Boards

Currently this library only supports the Particle Photon.  It should be possible to support other boards (including Arduinos) by modifying the constructor and `write()` methods to use `Serial` instead of `Serial1`, though this is currently untested.

### Particle Photon

Wire the board as follows:

 - Red wire to +5V (VIN)
 - Black wire to ground (GND)
 - White wire to TX

Even though the Photon operates at 3.3v logic, powering it via USB does provide just under 5V output on the VIN pin, which is sufficient for powering the LCD backpack.  Furthermore, because data is only being transmitted from the Photon, we don't have to worry about level shifting.

### Arduino

As mentioned above, this library should work on Arduinos with minimal changes.  Please submit a PR if you get it working!

## Documentation

This documentation is adapted from https://learn.adafruit.com/usb-plus-serial-backpack/command-reference.

### Initialization

```
SerialRGBLCD lcd;

void setup()
{
  lcd.begin(9600);
}
```

#### `void begin(uint16_t baud)`

Initializes the serial connection at the specified bitrate.  `baud` can be any of the following: `2400`, `4800`, `9600` (default), `19200`, `28800`, or `57600`.

### Commands

#### `void displayOn()`

Turns the display on.

#### `void displayOff()`

Turns the display off.

#### `void setBrightness(uint8_t brightness)`

Sets the brightness between `0` (dimmest) and `255` (brightest).  The value will be persisted to EEPROM.

#### `void setContrast(uint8_t contrast)`

Sets the contrast between `0` and `255`.  The value will be persisted to EEPROM.

Values between `180` and `220` tend to work best.

#### `setAutoscroll(bool autoscroll)`

When enabled (`true`), if text is received and there's no more room to display it, the screen will automatically "scroll down" - the second line will "move up" to become the first line and the additional text will display below it.

When disabled (`false`), any additional text will wrap around to the start of the display.

#### `void clear()`

Clears the screen.

#### `void changeStartupSplash(char *text)`

Changes the default splash text which appears when the LCD is first powered on.

#### `void setCursor(uint8_t column, uint8_t row)`

Sets the cursor to the given position.  Note that column and row numbering start at `1`, not `0`.

#### `void home()`

Sets the cursor location to `1, 1` (top-left corner).

#### `void cursorBack()`

Moves the cursor backwards by one position, wrapping around to the last position if needed.

#### `void cursorForward()`

Moves the cursor forward by one position, wrapping around to the first position if needed.

#### `void setUnderlineCursor(bool underline)`

Turns the underline cursor off (`false`) or on (`true`).

#### `void setBlockCursor(bool block)`

Turns the block cursor off (`false`) or on (`true`).

### RGB Colors

#### `void setBacklightColor(uint8_t red, uint8_t green, uint8_t blue)`

Sets the color of the backlight.  Each color component (red, green, and blue) are represented by a single byte between `0` and `255`.  This value will be persisted to EEPROM.

### Custom Characters

There are four banks available for storing custom characters, and each supports up to 8 different characters.

#### `void setCustomCharacter(uint8_t bank, uint8_t slot, uint8_t data[8])`

Saves the custom character pixels given by `data` into the given bank's slot.

#### `void loadCharacterBank(uint8_t bank)`

Loads the given `bank` of custom characters into memory.

### Displaying Text

This class extends from [Arduino's `Print` class](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/cores/arduino/Print.h), allowing you to display different types of variables by using the `print()` method.

If you'd like to write a raw byte, you may directly use the underlying `write(uint8_t)` method instead.
