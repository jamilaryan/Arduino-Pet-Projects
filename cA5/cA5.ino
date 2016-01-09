/*
* FILE : cA5.ino
* PROJECT : PROG8125 -Assignment #5
* PROGRAMMER : A. Jamil Aryan
* FIRST VERSION : 2015-11-27
* DESCRIPTION :* This sketch models a sound alarm trigger
*system with two input wires
*/

#include <LiquidCrystal.h>

uint8_t wire2 = 22;    // wire for pullup resistor on pin 22
uint8_t wire1 = 21;    // wire for pullup resistor on pin 21
uint8_t speakerPin = 13; // the speaker is attached on pin 13

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

// function prototypes, although not necessary for arduino
void checkAlarm(uint8_t zone1, uint8_t zone2);
void lcdMessage(char* message, char* zone1Status, char* zone2Status);

// Initial setup for the sketch
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 3);

  // wire pin for pullup resistor
  pinMode(wire2, INPUT_PULLUP);
  pinMode(wire1, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
}

// main loop function in charge of running the sketche repeatedly
void loop() {
  // Turn off the display:

  checkAlarm(digitalRead(wire1), digitalRead(wire2));
}

// checks the state of input parameter and signals the lcd based on
void checkAlarm(uint8_t zone1, uint8_t zone2)
{
  if (zone1 && zone2)
  {
    tone(speakerPin, 1500, 500);    // plays tone with the specified freq and duration
    lcdMessage("ALARM", "**", "**");
  }
  else if (zone2)
  {
    tone(speakerPin, 1500, 500);
    lcdMessage("ALARM", "**", "OK");
  } else if (zone1)
  {
    tone(speakerPin, 1500, 500);
    lcdMessage("ALARM", "OK", "**");
  } else {
    lcdMessage("Alarm Status: OK", "OK", "OK");
  }
}

// comprises the text string that should be displayed on the lcd
void lcdMessage(char* message, char* zone1Status, char* zone2Status)
{
  lcd.display();
  lcd.setCursor(0, 0);
  lcd.print(message);
  lcd.print("                ");   // clear the lcd
  lcd.setCursor(0, 1);
  lcd.print("Z1: ");
  lcd.print(zone1Status);
  lcd.print(" Z2: ");
  lcd.print(zone2Status);
}



