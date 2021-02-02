#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <TM1637Display.h>
#include "./headers/globalDeclarations.h"

int currentMinute = 0;
int pastMinute = 0;

bool nightMode = 0;

void showDateTimeFunction(int forceShow = false) {
	DateTime now = rtc.now();
	currentMinute = now.minute();

	if (currentMinute != pastMinute || forceShow == 1)
	{
		lcd.clear();

		lcd.setCursor(0,0);

		lcd.print(monthsNamesList_short[now.month()]);
		lcd.print(" ");
		if (now.day() < 10) lcd.print("0");
		lcd.print(now.day(), DEC);
		lcd.print(", ");
		lcd.print(now.year(), DEC);

		lcd.print(" ");
		lcd.print(DOWnamesList_short[now.dayOfTheWeek()]);

		if (nightMode)
		{
			lcd.setCursor(5,1);

			if (now.hour() < 10) lcd.print("0");
			lcd.print(now.hour(), DEC);
			lcd.print("h");
			if (now.minute() < 10) lcd.print("0");
			lcd.print(now.minute(), DEC);
			lcd.print("m");
		}
		else
		{
			// show hour
			// 0b01000000: enable display colon
			display.showNumberDecEx(now.hour(), 0b01000000, true, 2, 0);

			// show minute
			display.showNumberDec(now.minute(), true, 2, 2);
		}
	}

	pastMinute = currentMinute;

	return;
}

bool toggleNightModeFunction() {
	if (nightMode == false)
	{
		nightMode = true;
		display.setBrightness(0, 0);
		display.clear();
		showDateTimeFunction(true);
	}
	else if (nightMode == true)
	{
		nightMode = false;
		display.setBrightness(0, 1);
		showDateTimeFunction(true);
	}

	return nightMode;
}