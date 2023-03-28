//
// Created by victo on 28/03/2023.
//

#ifndef _SD_LCD_TO_I2C_DISPLAY_H
#define _SD_LCD_TO_I2C_DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Display {
private:
    LiquidCrystal_I2C display;

public:
    Display();
    void display_value(uint8_t value, base type);

};


#endif //_SD_LCD_TO_I2C_DISPLAY_H
