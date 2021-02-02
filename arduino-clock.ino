//Programa: Digital Clock with humidity and temperature sensor
//Autor: Gianni Labella

#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <TM1637Display.h>
#include "./headers/globalDeclarations.h"
#include "./headers/functions.h"
#include "./headers/dateTimeConfigFunctions.h"
#include "./headers/showDateTimeFunctions.h"
#include "./headers/showWeatherDataFunctions.h"
#include "./headers/customChars.h"

// Set LCD address
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Set RTC
RTC_DS1307 rtc;

// Set 4-digit display
#define CLK 4
#define DIO 5
TM1637Display display(CLK, DIO);

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

	// LCD custom chars creation
	lcd.createChar(0, customHumidityChar);
	lcd.createChar(1, customTemperatureChar);
	lcd.createChar(2, customCelsiusChar);

	// RTC setup
	rtc.begin();

	if (!rtc.isrunning())
	{
		Serial.println("RTC lost power, lets set the time!");

		// sets the date & time at which the sketch was compiled
		rtc.adjust(DateTime(__DATE__, __TIME__));
	}

	// 4-digit display setup
	display.setBrightness(0, 1);

	// Buttons setup
	pinMode(buttonPin_1, INPUT);
	pinMode(buttonPin_2, INPUT);

	// Show Date/Time
	showDateTimeFunction(true);
}

void loop() {
	showDateTimeFunction();
	showWeatherDataFunction();

	if (buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1, 0))
	{
		clockConfigFunction();
		showDateTimeFunction(true);
	}

	if (buttonClickHandler(&buttonPin_2, &buttonState_2, &previousButtonState_2, 0))
	{
		toggleNightModeFunction();
	}
}