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

#endif // globalDeclarations_H_INCLUDED