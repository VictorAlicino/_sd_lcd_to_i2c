//
// Created by victo on 28/03/2023.
//

#include "Display.hpp"


Display::Display(){
    this->display = new LiquidCrystal_I2C(0x27, 16, 2);
    this->display->init();
    this->display->backlight();
    this->display->setCursor(0, 0);
    this->display->print("Loading...");
}

void Display::show_operation(NumericRepresentation opA,
                             NumericRepresentation opB,
                             NumericRepresentation result) {

    this->display->clear();

    this->display->setCursor(0, 0);
    this->display->print(opA.get_value(DECIMAL));
    this->display->print("*");
    this->display->print(opB.get_value(DECIMAL));
    this->display->print("=");
    this->display->print(result.get_value(DECIMAL));

    this->display->setCursor(0, 1);
    this->display->print(result.get_value(BINARY) + "b");
    this->display->print(" " + result.get_value(HEXADECIMAL));
}
