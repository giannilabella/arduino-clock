#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <math.h>
#include "./headers/globalDeclarations.h"

float humidity = dht.readHumidity();
float temperature = dht.readTemperature();

int roundedHumidity = 0;
int roundedTemperature = 0;

int previousRoundedHumidity = 0;
int previousRoundedTemperature = 0;

void showWeatherDataFunction(int forceShow = false) {
	humidity = dht.readHumidity();
	temperature = dht.readTemperature();

	roundedHumidity = round(humidity);
	roundedTemperature = round(temperature);

	if (previousRoundedHumidity != roundedHumidity || previousRoundedTemperature != roundedTemperature || forceShow == 1)
	{
		lcd.setCursor(0,1);
		lcd.write(0);
		if (isnan(humidity))
		{
			lcd.print("--");
		}
		else
		{
			lcd.print(roundedHumidity);
		}
		lcd.print("%");

		lcd.setCursor(12,1);
		lcd.write(1);
		if (isnan(temperature))
		{
			lcd.print("--");
		}
		else
		{
			lcd.print(roundedTemperature);
		}
		lcd.write(2);
	}
	
	previousRoundedHumidity = roundedHumidity;
	previousRoundedTemperature = roundedTemperature;

	return;
}