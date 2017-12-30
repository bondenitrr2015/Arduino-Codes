// import the library
#include <Morse.h>

// defining the constructor
Morse morse(RED_LED);

void setup()
{
  // put your setup code here, to run once:
  // we do not need to put anything here since we define the use in
  // library itself
}

void loop()
{
  // put your main code here, to run repeatedly:
  morse.dot(); morse.dot(); morse.dot();
  morse.dash(); morse.dash(); morse.dash();
  morse.dot(); morse.dot(); morse.dot();
  delay(3000);
}
