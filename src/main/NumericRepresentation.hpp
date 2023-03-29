//
// Created by victo on 28/03/2023.
//

#ifndef _SD_LCD_TO_I2C_NUMERICREPRESENTATION_H
#define _SD_LCD_TO_I2C_NUMERICREPRESENTATION_H

#include <Arduino.h>


typedef enum number_base {
    BINARY,
    DECIMAL,
    OCTAL,
    HEXADECIMAL
} base;

class NumericRepresentation {
private:
    //
    bool* binary;
    String binary_string;
    uint8_t decimal;
    uint8_t octal;
    String hexadecimal;

    uint8_t bit_size;
    uint8_t* pins;

    String to_binary();
    uint8_t to_decimal();
    uint8_t to_octal();
    String to_hexadecimal();
public:
    NumericRepresentation(uint8_t bit_size,
                          uint8_t* pins);
    bool update(bool force_update);
    String get_value(base type);

};

bool* read_bytes_from_ic(uint8_t bit_size,
                        uint8_t* pins);

String numeric_representation_to_string(bool* binary);


#endif //_SD_LCD_TO_I2C_NUMERICREPRESENTATION_H
