// include our list of note pitches
#include "pitches.h"

// the pin the speaker is attached to
int speakerPin = 8;

// the notes in our melody and their duration in fractions of a second
// e.g. quarter note = 4, eighth note = 8, etc.
const int melody[][2] = 
{
    {NOTE_C4, 4},
    {NOTE_G3, 8},
    {NOTE_G3, 8},
    {NOTE_A3, 4},
    {NOTE_G3, 4},
    {NOTE_BLANK, 4},
    {NOTE_B3, 4},
    {NOTE_C4, 4}
};

void setup()
{
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
        tone(speakerPin, thisNoteTone, noteDurationMS);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        delay(noteDurationMS * 1.30);
    }
}

void loop()
{
    // no need to repeat the melody.
    // do nothing
}