#ifndef dateTimeConfigFunctions_H_INCLUDED
#define dateTimeConfigFunctions_H_INCLUDED

void configDowSelectionHandler(char * selectionName, char ** selectionValues, int *selectionCounter, int limitValue, int initialValue);
void configSelectionHandler(char * selectionName, int *selectionValue, int *limitValue, int *initialValue);
void clockConfigFunction();

#endif // dateTimeConfigFunctions_H_INCLUDED