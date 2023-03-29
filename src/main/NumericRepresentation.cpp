//
// Created by victo on 28/03/2023.
//

#include "NumericRepresentation.hpp"

NumericRepresentation::NumericRepresentation(uint8_t bit_size, uint8_t* pins) {
    this->binary = new bool[bit_size];
    this->decimal = 0;
    this->octal = 0;
    this->hexadecimal = "";

    this->bit_size = bit_size;
    this->pins = pins;

    // Set the pins direction to inputs
    for (int i = 0; i < bit_size; i++) {
        pinMode(pins[i], INPUT);
        Serial.println("D" + String(pins[i]) + " set to input");
    }

    this->binary = read_bytes_from_ic(bit_size, pins);

    this->binary_string = numeric_representation_to_string(this->binary);
    this->to_decimal();
    this->to_octal();
    this->to_hexadecimal();
}

bool NumericRepresentation::update(bool force_update) {
    bool* temp_binary = read_bytes_from_ic(bit_size, pins);
    String temp_binary_string = numeric_representation_to_string(temp_binary);

    if (force_update) {
        this->binary = temp_binary;
        return true;
    }

    if (this->binary_string != temp_binary_string) {
        this->binary = temp_binary;
        this->binary_string = temp_binary_string;
        this->to_decimal();
        this->to_octal();
        this->to_hexadecimal();
        return true;
    }

    return false;
}

String NumericRepresentation::get_value(base type) {
    switch (type) {
        case BINARY:
            return String(this->binary_string);
        case DECIMAL:
            return String(this->to_decimal());
        case OCTAL:
            return String(this->to_octal());
        case HEXADECIMAL:
            return "0x" + String(this->to_hexadecimal());
        default:
            return "Invalid Base";
    }
}

String NumericRepresentation::to_binary() {
    return this->binary_string;
}

uint8_t NumericRepresentation::to_decimal() {
    uint8_t decimal = 0;

    for (int i = sizeof(this->binary)/sizeof(this->binary[0])-1; i >= 0; i--) {
        decimal = (decimal << 1) | this->binary[i];
    }

    this->decimal = decimal;
    return decimal;
}

uint8_t NumericRepresentation::to_octal() {
    uint8_t octal = 0;
    uint8_t decimal = this->decimal;
    int i = 1;

    while (decimal != 0) {
        octal += (decimal % 8) * i;
        decimal /= 8;
        i *= 10;
    }

    this->octal = octal;
    return octal;
}

String NumericRepresentation::to_hexadecimal() {
    String hexadecimal = "";
    uint8_t decimal = this->decimal;

    while (decimal > 0) {
        int remainder = decimal % 16;
        char digit;

        if (remainder < 10) {
            digit = remainder + '0';
        } else {
            digit = remainder - 10 + 'A';
        }

        hexadecimal = digit + hexadecimal;
        decimal /= 16;
    }

    this->hexadecimal = hexadecimal;
    return hexadecimal;
}

bool* read_bytes_from_ic(uint8_t bit_size,
                        uint8_t* pins) {
    bool* binary = new bool[bit_size];
    for (int i = 0; i < bit_size; i++) {
        binary[i] = digitalRead(pins[i]);
    }
    return binary;
}

String numeric_representation_to_string(bool* binary){
    String binary_string = "";
    for (int i = 0; i < sizeof(binary); i++) {
        binary_string += binary[i];
    }
    return binary_string;
}