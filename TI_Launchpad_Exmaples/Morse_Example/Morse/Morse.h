/*
This is the header file for morse code flashing example
*/

#ifndef morse_h
#define morse_h

#include "Morse.h"

class Morse{
public:
	Morse(int pin);
	void dot();
	void dash();
private:
	int _pin;
};

#endif
