/* 
* PROGRAMMER : Jamil Aryan
* FIRST VERSION : 2015-12-13
* DESCRIPTION :
* This sketch measures the periods of sound waves
* laying basis for deciphering short pulses of alarms 
* such as in Morse code, music tunes and human speech
* The circuit can be viewed here: http://1drv.ms/1RjoMYc
*/
#include <LiquidCrystal.h>

int pin = 14;       // mic-opamp Vout pin
long count = 0;     // keeps track of pulses with period > 100uS
unsigned long duration = 0;   // duration of a single sound pulse
LiquidCrystal lcd(12, 11, 6, 5, 4, 7);

// This function initializes the board
void setup()
{
  Serial.begin(115200);
  pinMode(pin, INPUT);
  lcd.begin(16, 7);
}

/* 
* FUNCTION : loop
*
* DESCRIPTION : This function acts as the main loop function calculating 
* the pulse period of incoming sound pulses to mic.
*
* PARAMETERS : none
*
* RETURNS : void: runs the sketch repeatedly, calculating duration
* and count of sound pulses
*/
void loop()
{
  duration = pulseIn(pin, HIGH,2000000);
  count++;
  if(duration<=100)
    count = 0;
  printSerial();
  printLCD();
}

/* 
* FUNCTION : printSerial
*
* DESCRIPTION : This function only print the outputs to comport for 
* debugging purpose, also keeps historic data about sound pulses
*
* PARAMETERS : none
*
* RETURNS : void: only for debugging purposes
*/
void printSerial(){
  Serial.print("count: ");
  Serial.println(count);
  Serial.print("duration: ");
  Serial.println(duration);
}

/* 
* FUNCTION : printLCD
*
* DESCRIPTION : This function handles type conversion from long data type
* to character array and passes the appropriate format to manageLCD function.
*
* PARAMETERS : double purchaseAmount : none
*
* RETURNS : void: puts long data type into a char string
*/
void printLCD(){
  char lcdDuration[16]; 
  char lcdCount[16];   
  sprintf(lcdDuration,"Duration: %d uS",duration);
  sprintf(lcdCount,"Count: %d",count);
  manageLCD(lcdDuration,lcdCount);
}

/* 
* FUNCTION : manageLCD
*
* DESCRIPTION : This function handles printing on rows, cols of lcd display.
*
* PARAMETERS : double purchaseAmount : none
*
* RETURNS : row0, row1: the respective physical display rows on lcd
*/
void manageLCD(char* row0, char* row1)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(row0);
  lcd.setCursor(0,1);
  lcd.print(row1);
}

