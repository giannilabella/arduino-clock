//Programa: Digital Clock with humidity and temperature sensor
//Autor: Gianni Labella

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include "./headers/globalDeclarations.h"
#include "./headers/functions.h"
#include "./headers/dateTimeConfigFunctions.h"

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
}

void loop() {
	if (buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1, 0))
	{
		clockConfigFunction();
		lcd.clear();
	}

	lcd.setCursor(0,0);
	lcd.print("Horario");

	DateTime now = rtc.now();

	if (now.second() == 0)
	{
		Serial.println("Current Date & Time: ");
		Serial.print(now.year(), DEC);
		Serial.print('/');
		Serial.print(now.month(), DEC);
		Serial.print('/');
		Serial.print(now.day(), DEC);
		Serial.print(" (");
		Serial.print(now.dayOfTheWeek(), DEC);
		Serial.print(") ");
		Serial.print(now.hour(), DEC);
		Serial.print(':');
		Serial.print(now.minute(), DEC);
		Serial.print(':');
		Serial.print(now.second(), DEC);
		Serial.println();
	}

}