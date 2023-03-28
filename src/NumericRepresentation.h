//
// Created by victo on 28/03/2023.
//

#ifndef _SD_LCD_TO_I2C_NUMERICREPRESENTATION_H
#define _SD_LCD_TO_I2C_NUMERICREPRESENTATION_H

#include <string>

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
    std::string binary_string;
    uint8_t decimal;
    uint8_t octal;
    uint8_t hexadecimal;

    uint8_t bit_size;
    uint8_t* pins;

    std::string to_binary(uint8_t value);
    std::string to_decimal(uint8_t value);
    std::string to_octal(uint8_t value);
    std::string to_hexadecimal(uint8_t value);
public:
    NumericRepresentation(uint8_t bit_size, uint8_t* pins);
    void update(bool force_update);
    std::string get_value(base type);

    void read_bytes_from_ic();

};

bool* read_bytes_from_ic
std::string numeric_representation_to_string(uint8_t* binary);


#endif //_SD_LCD_TO_I2C_NUMERICREPRESENTATION_H
