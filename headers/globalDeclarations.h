#ifndef globalDeclarations_H_INCLUDED
#define globalDeclarations_H_INCLUDED

#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

extern LiquidCrystal_I2C lcd;

extern RTC_DS1307 rtc;

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