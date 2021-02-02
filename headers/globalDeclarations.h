#ifndef globalDeclarations_H_INCLUDED
#define globalDeclarations_H_INCLUDED

// LCD
#include <LiquidCrystal_I2C.h>
extern LiquidCrystal_I2C lcd;

// RTC
#include "RTClib.h"
extern RTC_DS1307 rtc;

// 4-digit display
#include <TM1637Display.h>
extern TM1637Display display;

// Buttons
extern const int buttonPin_1;
extern const int buttonPin_2;

extern int buttonState_1;
extern int previousButtonState_1;
extern int buttonState_2;
extern int previousButtonState_2;

// global variables
char * DOWnamesList[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
char * DOWnamesList_short[] = {"", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
char * monthsNamesList[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char * monthsNamesList_short[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

#endif // globalDeclarations_H_INCLUDED