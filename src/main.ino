#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C display(0x27, 16, 2);

void setup() {
    display.init();
    display.backlight();
    display.setCursor(0, 0);
}

void loop() {
    
}