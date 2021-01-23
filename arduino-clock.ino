//Programa: Digital Clock with humidity and temperature sensor
//Autor: Gianni Labella

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set LCD address
LiquidCrystal_I2C lcd(0x3F,16,2);

// Set buttons
const int buttonPin_1 = 2;
const int buttonPin_2 = 3;

int buttonState_1 = 0;
int previousButtonState_1 = 0;
int buttonState_2 = 0;
int previousButtonState_2 = 0;

char * configStages[] = {"DOW", "Time", "Date"};
int stageCounter = 0;

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
	if ( buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1) == 1)
	{
		clockConfigFunction();
	}
}

int buttonClickHandler(const int *buttonPin, int *buttonState, int *previousButtonState) {
	*buttonState = digitalRead(*buttonPin);

	if (*buttonState == HIGH && *previousButtonState == LOW)
	{
		*previousButtonState = *buttonState;
		delay(500);
		return 1;
	}

	*previousButtonState = *buttonState;
	return 0;
}

void configSelectionHandler(char * selectionName, int *selectionCounter, int limit, int initialValue) {
	while (buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1) == 0)
	{
		lcd.setCursor(3,0);
		lcd.print("Select ");
		lcd.print(selectionName);
		lcd.setCursor(0,1);
		lcd.print("=> ");
		if (selectionName == "DOW")
		{
			lcd.print(DOW[DOWcounter]);
		}

		if (buttonClickHandler(&buttonPin_2, &buttonState_2, &previousButtonState_2)) {
			DOWcounter++;
			if (DOWcounter > limit) DOWcounter = 0;

			lcd.clear();
		}
	}

	lcd.setCursor(14,1);
	lcd.print("ok");
	delay(700);
	lcd.clear();
}

void clockConfigFunction() {
	char * DOW[] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};
	int DOWcounter = 0;

	int date[] = {1, 1, 2021};
	int initialDayValue = 1;
	int initialMonthValue = 1;
	int initialYearValue = 2021;

	int time[] = {0, 0, 0};
	int initialHourValue = 0;
	int initialMinutesValue = 0;
	int initialSecondsValue = 0;

	lcd.clear();

	while (buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1) == 0)
	{
		lcd.setCursor(3,0);
		lcd.print("Select DOW");
		lcd.setCursor(0,1);
		lcd.print("=> ");
		lcd.print(DOW[DOWcounter]);

		if (buttonClickHandler(&buttonPin_2, &buttonState_2, &previousButtonState_2)) {
			DOWcounter++;
			if (DOWcounter > 6) DOWcounter = 0;

			lcd.clear();
		}
	}

	lcd.setCursor(14,1);
	lcd.print("ok");
	delay(700);
	lcd.clear();

	while (buttonClickHandler(&buttonPin_1, &buttonState_1, &previousButtonState_1) == 0)
	{
		lcd.setCursor(3,0);
		lcd.print("Select Date");
		lcd.setCursor(0,1);
		lcd.print("=> ");
		lcd.print(day);
		lcd.print(" ");
		lcd.print(month);
		lcd.print(" ");
		lcd.print(year);

		if (buttonClickHandler(&buttonPin_2, &buttonState_2, &previousButtonState_2)) {
			day++;
			if (day > 31) DOWcounter = 1;

			lcd.clear();
		}
	}

	lcd.setCursor(14,1);
	lcd.print("ok");
	delay(700);
	lcd.clear();

	lcd.setCursor(0,0);
	lcd.print("processo");
	lcd.setCursor(0,1);
	lcd.print("concluido");

	Serial.print("selecionado: ");
	Serial.println(DOW[DOWcounter]);

	return;
}