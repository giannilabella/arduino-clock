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

	return;
}

void configSelectionHandler(char * selectionName, int *selectionValue, int *limitValue, int *initialValue) {
	for (int selectionStage = 0; selectionStage < 3; selectionStage++)
	{
		while (! buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1, 0))
		{
			lcd.setCursor(1,0);
			lcd.print("Select ");
			lcd.print(selectionName);
			lcd.setCursor(13,0);
			lcd.print("(");
			lcd.print(selectionStage + 1);
			lcd.print(")");
			lcd.setCursor(0,1);
			lcd.print("=> ");
			for (int i = 0; i < 3; i++)
			{
				if (selectionValue[i] < 10) lcd.print("0");
				lcd.print(selectionValue[i]);
				lcd.print(" ");
			}		

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

	return;
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
		if (buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1, 0)) 
		{
			lcd.clear();
			return;
		}
	}

	// DOW
	int DOWcounter = 1;
	int limitDOWValue = 7;
	int initialDOWValue = 1;

	// Date: day, month, year
	int dateValue[] = {1, 1, 2021};
	int limitDateValue[] = {31, 12, -1};
	int initialDateValue[] = {1, 1, 2021};

	// Time: hours, minutes, seconds
	int timeValue[] = {0, 0, 0};
	int limitTimeValue[] = {23, 59, 59};
	int initialTimeValue[] = {0, 0, 0};

	lcd.clear();

	// configDowSelectionHandler("DOW", DOWarray, &DOWcounter, limitDOWValue, initialDOWValue);
	// Serial.println(DOWarray[DOWcounter]);

	configSelectionHandler("Date", dateValue, limitDateValue, initialDateValue);
	Serial.println(dateValue[0]);
	Serial.println(dateValue[1]);
	Serial.println(dateValue[2]);

	configSelectionHandler("Time", timeValue, limitTimeValue, initialTimeValue);
	Serial.println(timeValue[0]);
	Serial.println(timeValue[1]);
	Serial.println(timeValue[2]);

	rtc.adjust
	(
		DateTime
		(	
			//	year, month, day
			dateValue[2], dateValue[1], dateValue[0],
			// seconds, minutes, hours
			timeValue[2], timeValue[1], timeValue[0]
		)
	);

	lcd.setCursor(1,0);
	lcd.print("Set Date/Time");
	lcd.setCursor(4,1);
	lcd.print("Success");
	delay(700);
	lcd.clear();

	return;
}