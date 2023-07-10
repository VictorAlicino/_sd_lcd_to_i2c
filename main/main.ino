#include "Display.hpp" // For this to work properly, use this library: https://github.com/johnrickman/LiquidCrystal_I2C
#include "NumericRepresentation.hpp"

const bool DEBUG = true;

// Global variables
Display* display;
NumericRepresentation* opA;
NumericRepresentation* opB;
NumericRepresentation* result;

NumericRepresentation* counter;

void setup() {
    if(DEBUG) Serial.begin(9600);

    // Initialize the display
    display = new Display();

    // Initializing the operands
    int counter_pins[4] = {11, 10, 9, 8};
    counter = new NumericRepresentation(4, counter_pins);
    Serial.println("counter initialized with values b" + counter->get_value(BINARY) + " | DEC: " + counter->get_value(DECIMAL) + " | OCT: " + counter->get_value(OCTAL) + " | HEX: " + counter->get_value(HEXADECIMAL) + "");

    int opA_pins[3] = {7, 6, 5};
    opA = new NumericRepresentation(3, opA_pins);
    Serial.println("opA initialized with values b" + opA->get_value(BINARY) + " | DEC: " + opA->get_value(DECIMAL) + " | OCT: " + opA->get_value(OCTAL) + " | HEX: " + opA->get_value(HEXADECIMAL) + "");

    int opB_pins[7] = {22, 24, 26, 28, 30, 32, 34};
    opB = new NumericRepresentation(7, opB_pins);
    Serial.println("opB initialized with values b" + opB->get_value(BINARY) + " | DEC: " + opB->get_value(DECIMAL) + " | OCT: " + opB->get_value(OCTAL) + " | HEX: " + opB->get_value(HEXADECIMAL) + "");

    int result_pins[7] = {35, 33, 31, 29, 27, 25, 23};
    result = new NumericRepresentation(7, result_pins);
    Serial.println("result initialized with values b" + result->get_value(BINARY) + " | DEC: " + result->get_value(DECIMAL) + " | OCT: " + result->get_value(OCTAL) + " | HEX: " + result->get_value(HEXADECIMAL) + "");
    display->show_operation(*opA, *opB, *result, *counter);
}

void loop() {
    if(opA->update() || opB->update() || result->update() || counter->update()){
        display->show_operation(*opA, *opB, *result, *counter);
        Serial.println("counter @ b" + counter->get_value(BINARY) + " | DEC: " + counter->get_value(DECIMAL) + " | OCT: " + counter->get_value(OCTAL) + " | HEX: " + counter->get_value(HEXADECIMAL) + "");
        Serial.println("opA @ b" + opA->get_value(BINARY) + " | DEC: " + opA->get_value(DECIMAL) + " | OCT: " + opA->get_value(OCTAL) + " | HEX: " + opA->get_value(HEXADECIMAL) + "");
        Serial.println("opB @ b" + opB->get_value(BINARY) + " | DEC: " + opB->get_value(DECIMAL) + " | OCT: " + opB->get_value(OCTAL) + " | HEX: " + opB->get_value(HEXADECIMAL) + "");
        Serial.println("result @ b" + result->get_value(BINARY) + " | DEC: " + result->get_value(DECIMAL) + " | OCT: " + result->get_value(OCTAL) + " | HEX: " + result->get_value(HEXADECIMAL) + "");
        Serial.println("--------------------------------------------------");
    }
}