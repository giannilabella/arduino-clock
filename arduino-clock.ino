//Programa: Digital Clock with humidity and temperature sensor
//Autor: Gianni Labella

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "./headers/globalDeclarations.h"
#include "./headers/functions.h"
#include "./headers/dateTimeConfigFunctions.h"

// Set LCD address
LiquidCrystal_I2C lcd(0x3F,16,2);

// Set buttons
const int buttonPin_1 = 2;
const int buttonPin_2 = 3;

int buttonState_1 = 0;
int previousButtonState_1 = 0;
int buttonState_2 = 0;
int previousButtonState_2 = 0;

void setup() {
	// Serial setup
	Serial.begin(9600);

	// LCD setup
	lcd.init();

	// Buttons setup
	pinMode(buttonPin_1, INPUT);
	pinMode(buttonPin_2, INPUT);

	lcd.setBacklight(HIGH);
	lcd.setCursor(0,0);
	lcd.print("LCD e modulo I2C");
}

void loop() {
	if ( buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1, 0) == 1)
	{
		clockConfigFunction();
	}
}