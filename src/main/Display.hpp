//
// Created by victo on 28/03/2023.
//

#ifndef _SD_LCD_TO_I2C_DISPLAY_H
#define _SD_LCD_TO_I2C_DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "NumericRepresentation.hpp"

class Display {
private:
    LiquidCrystal_I2C* display;

public:
    Display();
    void show_operation(NumericRepresentation opA, NumericRepresentation opB, NumericRepresentation result);

};


#endif //_SD_LCD_TO_I2C_DISPLAY_H
