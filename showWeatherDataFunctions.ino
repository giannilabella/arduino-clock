#include <LiquidCrystal_I2C.h>
#include "./headers/globalDeclarations.h"

void showWeatherDataFunction() {
	lcd.setCursor(0,1);
	lcd.write(0);
	lcd.print("60%");

	lcd.setCursor(12,1);
	lcd.write(1);
	lcd.print("60");
	lcd.write(2);
}