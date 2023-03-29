//
// Created by victo on 28/03/2023.
//

#include "NumericRepresentation.h"

NumericRepresentation::NumericRepresentation(uint8_t bit_size, uint8_t* pins) {
    this->binary = new bool[bit_size];
    this->decimal = nullptr;
    this->octal = nullptr;
    this->hexadecimal = nullptr;

    for (int i = 0; i < bit_size; i++) {
        this->binary[i] = digitalRead(pins[i]);
    }

    this->binary_string = numeric_representation_to_string(this->binary);
}

String numeric_representation_to_string(uint8_t* binary){
    String binary_string = "";
    for (int i = 0; i < sizeof(binary); i++) {
        binary_string += binary[i];
    }
    return binary_string;
}

void NumericRepresentation::read_bytes_from_ic() {
    for (int i = 0; i < this->bit_size; i++) {
        this->binary[i] = digitalRead(this->pins[i]);
    }
}

void NumericRepresentation::update(bool force_update) {
    if (force_update) {
        this->read_bytes_from_ic();
    }

}