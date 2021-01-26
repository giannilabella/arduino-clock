#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include "./headers/globalDeclarations.h"
#include "./headers/functions.h"

int currentMinute = 0;
int pastMinute = 0;

void showDateTimeFunction(int forceShow) {
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

		lcd.setCursor(5,1);

		if (now.hour() < 10) lcd.print("0");
		lcd.print(now.hour(), DEC);
		lcd.print(":");
		if (now.minute() < 10) lcd.print("0");
		lcd.print(now.minute(), DEC);
	}

	pastMinute = currentMinute;

	return;
}