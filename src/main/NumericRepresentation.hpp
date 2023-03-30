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
    bool* binary_temp;
    String binary_string;
    uint8_t decimal;
    uint16_t decimal16_t;
    uint8_t octal;
    String hexadecimal;

    int bit_size;
    uint8_t* pins;

    String to_binary();
    uint8_t to_decimal8_t();
    uint16_t to_decimal16_t();
    uint8_t to_octal();
    String to_hexadecimal();

    bool is_equal(bool* a, bool* b);
public:
    NumericRepresentation(int bit_size,
                          uint8_t* pins);
    bool update();
    String get_value(base type);
    void read_bytes_from_ic();

};

String numeric_representation_to_string(bool* binary, uint8_t bit_size);


#endif //_SD_LCD_TO_I2C_NUMERICREPRESENTATION_H
