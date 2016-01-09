
/*
* FILE : cA4.ino
* PROJECT : PROG8125 -Assignment #4
* PROGRAMMER : A. Jamil Aryan
* FIRST VERSION : 2015-11-13
* DESCRIPTION :* This sketch plays a sad or happy meloda
* based on whether a pullup wire is detached or not.
*/

#include "pitches.h"

uint8_t pullUpPin = 8;   // the pin for PULL UP wire
uint8_t loudSpeakerPin = 3;   // loudspeak is attached to pwm signal on pin 3

// Happy melody notes:
uint16_t happyMelody[] = {
  NOTE_B0,NOTE_C1,
  NOTE_CS1,NOTE_D1,NOTE_FS2,NOTE_AS2,NOTE_F3,NOTE_B3,
  NOTE_B7,NOTE_D7,NOTE_D7,NOTE_D7  
};

// Sad melody notes, based on frequency values:
uint16_t sadMelody[] = {
  456,356,122,321,432,124,453
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
uint8_t noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

// Initial setup for the sketch
void setup() {
  // sets up the wire pull out:
   pinMode(pullUpPin, INPUT_PULLUP);  
}

// Repeating function acting as main sketch function
void loop() {

  if(digitalRead(pullUpPin))    // This activates the active-low pull up input .i.e. wire pull out
    playTune(sadMelody, noteDurations,sizeof(sadMelody));
  else
    playTune(happyMelody, noteDurations,sizeof(happyMelody));
}

// This plays a tune based on a collection of tones and duration of tones
void playTune(uint16_t myTone[], uint8_t duration[], uint8_t numberOfNotes)
{
    for (uint8_t thisNote = 0; thisNote < numberOfNotes; thisNote++)
    {
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      uint16_t noteDuration = 1000 / duration[thisNote];
      
      tone(loudSpeakerPin, myTone[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      uint16_t pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(loudSpeakerPin);
    }
  
}
