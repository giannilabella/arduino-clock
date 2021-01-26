//Programa: Digital Clock with humidity and temperature sensor
//Autor: Gianni Labella

// #include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include "./headers/globalDeclarations.h"
#include "./headers/functions.h"
#include "./headers/dateTimeConfigFunctions.h"
#include "./headers/showDateTimeFunctions.h"

// Set LCD address
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Set RTC
RTC_DS1307 rtc;

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
	lcd.setBacklight(HIGH);

	// RTC setup
	rtc.begin();

	if (!rtc.isrunning())
	{
		Serial.println("RTC lost power, lets set the time!");

		// sets the date & time at which the sketch was compiled
		rtc.adjust(DateTime(__DATE__, __TIME__));
	}

	// Buttons setup
	pinMode(buttonPin_1, INPUT);
	pinMode(buttonPin_2, INPUT);

	// Show Date/Time
	showDateTimeFunction(1);
}

void loop() {
	if (buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1, 0))
	{
		clockConfigFunction();
		lcd.clear();
	}

	showDateTimeFunction(0);
}