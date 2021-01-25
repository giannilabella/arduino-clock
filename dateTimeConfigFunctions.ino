#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "./headers/globalDeclarations.h"
#include "./headers/functions.h"

void configDowSelectionHandler(char * selectionName, char ** selectionValues, int *selectionCounter, int limitValue, int initialValue) {
	while (! buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1, 0))
	{
		lcd.setCursor(3,0);
		lcd.print("Select ");
		lcd.print(selectionName);
		lcd.setCursor(0,1);
		lcd.print("=> ");
		lcd.print(selectionValues[*selectionCounter]);

		if (buttonClickHandler(&buttonPin_2, &buttonState_2, &previousButtonState_2, 1)) {
			(*selectionCounter) ++;

			if (*selectionCounter > limitValue) *selectionCounter = initialValue;

			lcd.clear();
		}
	}

	lcd.setCursor(14,1);
	lcd.print("ok");
	delay(700);
	lcd.clear();
}

void configSelectionHandler(char * selectionName, int *selectionValue, int *limitValue, int *initialValue) {
	for (int selectionStage = 0; selectionStage < 3; selectionStage++)
	{
		while (! buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1, 0))
		{
			lcd.setCursor(3,0);
			lcd.print("Select ");
			lcd.print(selectionName);
			lcd.setCursor(0,1);
			lcd.print("=> ");
			lcd.print(selectionValue[0]);
			lcd.print(" ");
			lcd.print(selectionValue[1]);
			lcd.print(" ");
			lcd.print(selectionValue[2]);		

			if (buttonClickHandler(&buttonPin_2, &buttonState_2, &previousButtonState_2, 1)) {
				selectionValue[selectionStage] ++;
				
				if (limitValue[selectionStage] != -1)
					if (selectionValue[selectionStage] > limitValue[selectionStage])
						selectionValue[selectionStage] = initialValue[selectionStage];

				lcd.clear();
			}
		}

		lcd.setCursor(14,1);
		lcd.print("ok");
		delay(700);
		lcd.clear();
	}
}

void clockConfigFunction() {
	lcd.clear();
	lcd.setCursor(1,0);
	lcd.print("Set Date/Time");
	lcd.setCursor(0,1);
	lcd.print("<-Exit");
	lcd.setCursor(10,1);
	lcd.print("Next->");

	while (! buttonClickHandler(&buttonPin_2, &buttonState_2, &previousButtonState_2, 0))
	{
		if (buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1, 0)) return;
	}
	

	// DOW
	char * DOWarray[] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};
	int DOWcounter = 0;
	int limitDOWValue = 6;
	int initialDOWValue = 0;

	// Date: day, month, year
	int dateValue[] = {1, 1, 2021};
	int limitDateValue[] = {31, 12, -1};
	int initialDateValue[] = {1, 1, 2021};

	// Time: hour, minutes, seconds
	int timeValue[] = {0, 0, 0};
	int limitTimeValue[] = {23, 59, 59};
	int initialTimeValue[] = {0, 0, 0};

	lcd.clear();

	configDowSelectionHandler("DOW", DOWarray, &DOWcounter, limitDOWValue, initialDOWValue);
	Serial.println(DOWarray[DOWcounter]);

	configSelectionHandler("Date", dateValue, limitDateValue, initialDateValue);
	Serial.println(dateValue[0]);
	Serial.println(dateValue[1]);
	Serial.println(dateValue[2]);

	configSelectionHandler("Time", timeValue, limitTimeValue, initialTimeValue);
	Serial.println(timeValue[0]);
	Serial.println(timeValue[1]);
	Serial.println(timeValue[2]);

	lcd.setCursor(0,0);
	lcd.print("processo");
	lcd.setCursor(0,1);
	lcd.print("concluido");

	return;
}