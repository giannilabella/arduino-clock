#ifndef customChars_H_INCLUDED
#define customChars_H_INCLUDED

byte customHumidityChar[] = {
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

byte customTemperatureChar[] = {
  B00100,
  B01010,
  B01010,
  B01110,
  B11111,
  B11111,
  B01110,
  B00000
};

byte customCelsiusChar[] = {
  B11000,
  B11000,
  B00110,
  B01001,
  B01000,
  B01001,
  B00110,
  B00000
};

#endif // customChars_H_INCLUDED