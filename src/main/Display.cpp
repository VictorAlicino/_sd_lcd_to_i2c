//
// Created by victo on 28/03/2023.
//

#include "Display.hpp"


Display::Display(){
    this->display = new LiquidCrystal_I2C(0x27, 16, 2);
    this->display->init();
    this->display->backlight();
    this->display->setCursor(0, 0);
    this->display->print("Display Initialized");
}

void Display::show_operation(NumericRepresentation opA,
                             NumericRepresentation opB,
                             NumericRepresentation result) {
    this->display->setCursor(0, 0);
    this->display->print(opA.get_value(DECIMAL));
    this->display->setCursor(0, 2);
    this->display->print("*");
    this->display->setCursor(0, 3);
    this->display->print(opB.get_value(DECIMAL));
    this->display->setCursor(0, 5);
    this->display->print("=");
    this->display->setCursor(0, 6);
    this->display->print(result.get_value(DECIMAL));

    this->display->setCursor(1, 0);
    this->display->print("B: " + result.get_value(BINARY));
    this->display->setCursor(1, 10);
    this->display->print(" H:" + result.get_value(HEXADECIMAL));
}
