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

    int opA_pins[4] = {13, 12, 11, 10};
    opA = new NumericRepresentation(4, opA_pins);
    Serial.println("opA initialized with values b" + opA->get_value(BINARY) + " | DEC: " + opA->get_value(DECIMAL) + " | OCT: " + opA->get_value(OCTAL) + " | HEX: " + opA->get_value(HEXADECIMAL) + "");

    int opB_pins[4] = {5,4, 3, 2};
    opB = new NumericRepresentation(4, opB_pins);
    Serial.println("opB initialized with values b" + opB->get_value(BINARY) + " | DEC: " + opB->get_value(DECIMAL) + " | OCT: " + opB->get_value(OCTAL) + " | HEX: " + opB->get_value(HEXADECIMAL) + "");

    int result_pins[8] = {14, 15, 16, 17, 18, 19, 22, 23};
    result = new NumericRepresentation(8, result_pins);
    Serial.println("result initialized with values b" + result->get_value(BINARY) + " | DEC: " + result->get_value(DECIMAL) + " | OCT: " + result->get_value(OCTAL) + " | HEX: " + result->get_value(HEXADECIMAL) + "");
    display->show_operation(*opA, *opB, *result);
}

void loop() {
    if(opA->update() || opB->update() || result->update()){
        display->show_operation(*opA, *opB, *result);
        Serial.println("opA initialized with values b" + opA->get_value(BINARY) + " | DEC: " + opA->get_value(DECIMAL) + " | OCT: " + opA->get_value(OCTAL) + " | HEX: " + opA->get_value(HEXADECIMAL) + "");
        Serial.println("opB initialized with values b" + opB->get_value(BINARY) + " | DEC: " + opB->get_value(DECIMAL) + " | OCT: " + opB->get_value(OCTAL) + " | HEX: " + opB->get_value(HEXADECIMAL) + "");
        Serial.println("result initialized with values b" + result->get_value(BINARY) + " | DEC: " + result->get_value(DECIMAL) + " | OCT: " + result->get_value(OCTAL) + " | HEX: " + result->get_value(HEXADECIMAL) + "");
        Serial.println("--------------------------------------------------");
    }
}