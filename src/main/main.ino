#include "Display.hpp" // For this to work properly, use this library: https://github.com/johnrickman/LiquidCrystal_I2C
#include "NumericRepresentation.hpp"

const bool DEBUG = true;

// Global variables
Display* display;
NumericRepresentation* opA;
NumericRepresentation* opB;
NumericRepresentation* result;

void setup() {
    if(DEBUG) Serial.begin(9600);

    // Initialize the display
    display = new Display();

    // Initializing the operands
    uint8_t opA_pins[4] = {2, 3, 4, 5};
    opA = new NumericRepresentation(8, opA_pins);
    Serial.println("opA initialized with value: " + opA->get_value(BINARY) + "");

    uint8_t opB_pins[4] = {10, 11, 12, 13};
    opB = new NumericRepresentation(8, opB_pins);
    Serial.println("opB initialized with value: " + opB->get_value(BINARY) + "");

    uint8_t result_pins[8] = {18, 19, 20, 21, 22, 23, 24, 25};
    result = new NumericRepresentation(8, result_pins);
    Serial.println("result initialized with value: " + result->get_value(BINARY) + "");
}

void loop() {
    if(opA->update(false) || opB->update(false) || result->update(false)){
        display->show_operation(*opA, *opB, *result);
    }
}