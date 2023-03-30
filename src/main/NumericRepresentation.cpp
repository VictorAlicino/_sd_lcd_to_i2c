//
// Created by victo on 28/03/2023.
//

#include "NumericRepresentation.hpp"

NumericRepresentation::NumericRepresentation(int bit_size, uint8_t* pins) {
    this->binary = new bool[bit_size];
    this->binary_temp = new bool[bit_size];
    this->decimal = 0;
    this->decimal16_t = 0;
    this->octal = 0;
    this->hexadecimal = "";

    this->bit_size = bit_size;
    this->pins = pins;

    // Set the pins direction to inputs
    for (int i = 0; i < bit_size; i++) {
        pinMode(pins[i], INPUT);
        Serial.println("D" + String(pins[i]) + " set to input");
    }

    read_bytes_from_ic();

    for(int i=0; i<bit_size; i++){
        this->binary[i] = this->binary_temp[i];
    }

    this->binary_string = numeric_representation_to_string(this->binary, bit_size);
    this->bit_size <= 4 ? this->decimal = to_decimal8_t() : this->decimal16_t = to_decimal16_t();
    this->to_octal();
    this->to_hexadecimal();

    // Print the binary boolean list
    for(int i = 0; i < bit_size; i++) {
        Serial.print(this->binary[i]);
    }Serial.println();
}

bool NumericRepresentation::is_equal(bool *a, bool *b) {
    for(int i = 0; i < this->bit_size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool NumericRepresentation::update() {
    read_bytes_from_ic(); // Update the binary_temp
    if (!is_equal(this->binary, this->binary_temp)){
        this->binary_string = numeric_representation_to_string(this->binary_temp, this->bit_size);
        this->bit_size <= 4 ? this->decimal = to_decimal8_t() : this->decimal16_t = to_decimal16_t();
        this->to_octal();
        this->to_hexadecimal();
        // Update the binary
        for(int i=0; i<bit_size; i++){
            this->binary[i] = this->binary_temp[i];
        }
        return true;
    }
    return false;
}

String NumericRepresentation::get_value(base type) {
    switch (type) {
        case BINARY:
            return this->binary_string;
        case DECIMAL:
            if(this->bit_size <= 4) return String(this->to_decimal8_t());
            else return String(this->to_decimal16_t());
        case OCTAL:
            return String(this->to_octal());
        case HEXADECIMAL:
            return "0x" + String(this->to_hexadecimal());
        default:
            return String("Invalid Base");
    }
}

String NumericRepresentation::to_binary() {
    return this->binary_string;
}

uint8_t NumericRepresentation::to_decimal8_t() {
    uint8_t decimal = 0;

    for (int8_t i = 0; i < bit_size; i++) {
        decimal = (decimal << 1) | this->binary_temp[i];
    }

    this->decimal = decimal;
    return decimal;
}

uint16_t NumericRepresentation::to_decimal16_t() {
    uint16_t decimal = 0;

    for (int16_t i = 0; i < bit_size; i++) {
        decimal = (decimal << 1) | this->binary_temp[i];
    }

    this->decimal16_t = decimal;
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
    if (this->bit_size <= 4){
        decimal = this->decimal;
    } else {
        decimal = this->decimal16_t;
    }

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

void NumericRepresentation::read_bytes_from_ic() {
    Serial.print("Reading bytes: ");
    for (int i = 0; i < bit_size; i++) {
        this->binary_temp[i] = digitalRead(pins[i]);
        Serial.print(digitalRead(pins[i]));
    }Serial.println();
}

String numeric_representation_to_string(bool* binary, uint8_t bit_size){
    String binary_string = "";
    for (int i = 0; i < bit_size; i++) {
        binary_string += binary[i];
    }
    return binary_string;
}