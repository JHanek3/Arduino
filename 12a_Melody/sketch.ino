// include our list of note pitches
#include "pitches.h"
// Handles our button
#include <ezButton.h>
ezButton button(2);

// the pin the speaker is attached to
int speakerPin = 3;

// the leds and corresponding notes
const int ledC4 = 4;
const int ledG3 = 5;
const int ledA3 = 6;
const int ledB3 = 7;
// not going to represent blank with an led, so made it zero
const int ledBlank = 0;




// the notes in our melody and their duration in fractions of a second
// e.g. quarter note = 4, eighth note = 8, etc.
// added the corresponding led to the note
const int melody[][3] = 
{
    {NOTE_C4, 4, ledC4},
    {NOTE_G3, 8, ledG3},
    {NOTE_G3, 8, ledG3},
    {NOTE_A3, 4, ledA3},
    {NOTE_G3, 4, ledG3},
    {NOTE_BLANK, 4, ledBlank},
    {NOTE_B3, 4, ledB3},
    {NOTE_C4, 4, ledC4}
};

void setup()
{
  pinMode(ledC4, OUTPUT);
  
}

void loop()
{
  button.loop();
  if (button.isReleased()) {
    // I should make this a function, the melody an actual function
    
    // figure out the number of notes in our melody
    int numberOfNotes = sizeof(melody) / sizeof(melody[0]);

    // iterate over the notes of the melody
    for (int thisNote = 0; thisNote < numberOfNotes; thisNote++)
    {
        
        // grab our note and note duration from our array
        int thisNoteTone = melody[thisNote][0];
        int thisNoteDuration = melody[thisNote][1];

        // to calculate the note duration in ms
        int noteDurationMS = 1000 / thisNoteDuration;

        // play the note
        digitalWrite(melody[thisNote][2], HIGH);
        tone(speakerPin, thisNoteTone, noteDurationMS);
        

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        delay(noteDurationMS * 1.30);
        digitalWrite(melody[thisNote][2], LOW);
        
    } 
  }
}