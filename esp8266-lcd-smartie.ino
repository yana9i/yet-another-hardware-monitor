#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_LINES 2

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Now Booting...");
  delay(2000);
  lcd.clear();
  delay(1000);
}

byte serial_read_byte() {
  int rxbyte;
  while (Serial.available() == 0) {
  }
  rxbyte = Serial.read();
  return (byte)(rxbyte & 0xff);
}

void loop() {

  byte rxbyte;
  byte temp;

  rxbyte = serial_read_byte();

  if (rxbyte == 0xfe) {
    switch (serial_read_byte()) {
    case 'B':
      lcd.backlight();
      break;
    case 'F':
      lcd.noBacklight();
      break;
    case 'G':
      temp = serial_read_byte() - 1;
      lcd.setCursor(temp, (serial_read_byte() - 1));
      break;
    case 'H':
      lcd.home();
      break;
    case 'J':
      lcd.noBlink();
      break;
    case 'K':
      lcd.blink();
      break;
    case 'T':
      lcd.noCursor();
      break;
    case 'N':
      byte charIndex;
      charIndex = serial_read_byte();
      byte newChar[8];
      for (temp = 0; temp < 8; temp++) {
        newChar[temp] = serial_read_byte();
      }
      lcd.createChar(charIndex, newChar);
      break;
    case 'S':
      lcd.cursor();
      break;
    case 'X':
      lcd.clear();
      lcd.home();
      break;
    case 'Q':
      lcd.autoscroll();
      break;
    case 'R':
      lcd.noAutoscroll();
      break;
    case 'V': // GPO OFF
    case 'W': // GPO ON
    case 'P': // set contrast
    case 'b': // set brightness
    case ')': // set auto transmit keys
    case '`': // set repeat off
    case 192: // set fan
      break;
    default:
      temp = serial_read_byte(); // dump the command code
      break;
    }
    return;
  }
  lcd.write(rxbyte);
  return;
}