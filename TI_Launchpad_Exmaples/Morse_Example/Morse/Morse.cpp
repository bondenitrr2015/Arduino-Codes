/*
This is the code file for morse code flashing example
*/

#include "Energia.h"
#include "Morse.h"

Morse::Morse(int pin){
	pinMode(pin, OUTPUT);
	_pin = pin;
}

void Morse::dot(){
	//code
	digitalWrite(_pin, HIGH);
	delay(250);
	digitalWrite(_pin, LOW);
	delay(250);
}

void Morse::dash(){
	//code
	digitalWrite(_pin, HIGH);
	delay(1000);
	digitalWrite(_pin, LOW);
	delay(250);
}
