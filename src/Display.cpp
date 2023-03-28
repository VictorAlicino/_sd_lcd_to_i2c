//
// Created by victo on 28/03/2023.
//

#include "Display.h"

Display::Display(){
    this->display = LiquidCrystal_I2C(0x27, 16, 2);
    this->display.init();
    this->display.backlight();
    this->display.setCursor(0, 0);
    this->display.print("Display Initialized");
}

void Display::display_value(uint8_t value) {
    this->display.setCursor(0, 0);
    //TODO: Binary Value
    this->display.setCursor(1, 0);
    this->display.print(value);
}
