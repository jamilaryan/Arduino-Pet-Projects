/*
* PROGRAMMER :  Jamil Aryan
* FIRST VERSION : 2015-11-06
* DESCRIPTION :* This sketch models a life jacket embedded
* Application where a pull cord can be pulled off to
* start the SOS flashes and allows observers to know that
*the person is in danger.
*/

#define UNITTIME 100     // This is the unit interval for SOS ON/OFF flashes

uint8_t ledPin = 10;     // the pin connected to resistor for LED
uint8_t pullUpPin = 8;   // the pin for PULL UP

// the setup routine runs once when you press reset:
void setup() {

  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
  // set pin 8 as Pullup input
  pinMode(pullUpPin, INPUT_PULLUP);

}

// This is the main loop function for Life Jacket model
void loop()
{
  if (digitalRead(pullUpPin))   // This activates the active-low pull up input .i.e. wire pull out
    flashSOS();
  else
    heartBeat();               //if wire is in place, the flash is in ready mode
}

/************************************************************
*MINI MILESTONE 4- CREATING THE FLASHS AND FLASHO FUNCTIONS *
-***********************************************************/


// This function is the first building block, accepts 2 arguments for setting length of flash and delays to construct Morse Codes
void blink( uint32_t flashOnTime, uint32_t flashOffTime)
{
  digitalWrite(ledPin, HIGH);     // turn the LED on (HIGH is the voltage level)
  delay(flashOnTime);                     // wait for
  digitalWrite(ledPin, LOW);      // turn the LED off by making the voltage LOW
  delay(flashOffTime);

}

// It creates a basic dot flash in Morse Code
void flashDot()
{
  blink(UNITTIME, UNITTIME);    // The length of a dot is one unit
}

// It creates a basic dash flash in Morse Code
void flashDash()
{
  blink(UNITTIME * 3, UNITTIME);  // The length of a dash is three units
}

// It creates the letter S in Morse Code
void flashS()
{
  for (uint8_t i = 0; i < 3; i++)
    flashDot();
  delay(3 * UNITTIME);  // The space between letters is 3 units
}

// It creates the letter O in Morse Code
void flashO()
{
  for (uint8_t i = 0; i < 3; i++)
    flashDash();
  delay(3 * UNITTIME);  // The space between letters is 3 units
}

// this integrates the sos functionality based on Internation Morse Code specifications
void flashSOS()
{
  flashS();  
  flashO();
  flashS();
  delay(7 * UNITTIME);  //The space between words is 7 units
}

//it indicates the circuits is powered by using millis() function instead of delaying the processor
void heartBeat()
{
  static unsigned long lastMillis = 0;        //one previous time
  static int8_t  ledOnOffFlag = 0;
  static unsigned long OffTime = 950;
  unsigned long currentMillis = millis();      //recording the current time

  if ((currentMillis - lastMillis) > OffTime)  //setting time interval as trigger for blinks
  {

    if ( ledOnOffFlag != 0 )
    {
      digitalWrite( ledPin, LOW );
      lastMillis = currentMillis;            //set lastMillis to >=950 after LED goes off

    }
    else
    {
      digitalWrite( ledPin, HIGH );
      lastMillis = currentMillis - OffTime;  //set lastMillies to 50
    }

    ledOnOffFlag = !ledOnOffFlag;          //invert the LED state
  }
}


/***************************************************************************************
*Baby step approach



// MINI MILESTONE 3- ADDING EXTERNAL WIRE INPUT TO PIN 8 IN PINMODE INPUT_PULLUP

//void loop()
//{
//  if(!digitalRead(pullUpPin))
//    digitalWrite( ledPin, HIGH );
//   else
//     digitalWrite( ledPin, LOW);
//
//}

//MINI MILESTONE 2- ELIMINATING DELAY FROM THE LOOP USING 50/950 ON/OFF TIME

//void loop()
//{
//  static unsigned long lastMillis = 0;
//  static int8_t  ledOnOffFlag = 0;
//  static unsigned long OnTime = 50;
//  static unsigned long OffTime = 950;
//  unsigned long currentMillis = millis();
//
//
//  if ((currentMillis-lastMillis) > OffTime)
//  {
//
//
//
//    if ( ledOnOffFlag != 0 )
//    {
//      digitalWrite( ledPin, LOW );
//      lastMillis = currentMillis;
//
//    }
//    else
//    {
//      digitalWrite( ledPin, HIGH );
//      lastMillis = currentMillis-OffTime;
//    }
//
//    ledOnOffFlag = !ledOnOffFlag;
//  }
//}

// MINI MILESTONE 1- USING EXTERNAL LED ON PIN 10 WITH 1K RESISTOR

//void loop() {
//
//
//    digitalWrite(ledPin, HIGH);     // turn the LED on (HIGH is the voltage level)
//    delay(50);                     // wait for 50ms
//    digitalWrite(ledPin, LOW);      // turn the LED off by making the voltage LOW
//    delay(950);                     // wait for 950ms
//
//}

****************************************************************************************/
