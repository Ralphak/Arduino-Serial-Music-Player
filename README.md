# Arduino Serial Music Player
A piezo buzzer player built with an Arduino board which receives melody strings through a serial (USB) connection.

Based on Robson Couto's song player for Arduino:
https://github.com/robsoncouto/arduino-songs

## Instructions
You will need:
* Arduino board (I made this with an UNO R3)
* Piezoelectric buzzer module
* USB cable, to connect the Arduino to your computer/smartphone/anything that supports serial communication
* Jumper cables and resistors for connections, if needed
* (optional) 16x2 LCD display
* (optional but strongly recommended) Breadboard or something suitable enough to attach the components onto

After linking all components together and uploading the code into the Arduino, you can play your song by copying its sequence into a serial terminal, such as the IDE's serial monitor, and pressing the Send button. Once the device finishes playing the song, it will prompt for another.

### Example of a song sequence
```
// Speed at which the song is played. Higher means faster.
140,

// Notes of the melody, followed by their durations (a 4 means a quarter note, 8 an eighth and so on)
// Negative numbers are used to represent dotted notes, so -4 means a dotted quarter note.
// All melodies must end with a -3, indicating to the player it is over.
// There's a note reference table in the note_replacer.html file.
262,4, 262,8, 
  294,-4, 262,-4, 349,-4,
  330,-2, 262,4, 262,8, 
  294,-4, 262,-4, 392,-4,
  349,-2, 262,4, 262,8,

  523,-4, 440,-4, 349,-4, 
  330,-4, 294,-4, 466,4, 466,8,
  440,-4, 349,-4, 392,-4,
  349,-2, -3

// The song's name and the author to be shown on the LCD display, if available.
Happy Birthday-Unknown/

// Remember to remove comments before using this!
```

## Contents
* **music_player_serial.ino:** The code to be loaded into the Arduino.
* **note_replacer.html:** A tool to convert melody strings with NOTE_* variables into their respective values. Contains a reference table for the notes.
* **songs folder:** Some examples of melodies you can try. Simply copy a file's contents and paste on the terminal.

## Known glitches
* If you enabled line endings on the serial terminal, the song may play twice.
* If a melody is too long, it may not play properly due to lack of memory. You can however increase the melody array's size, but at your own risk.
* The Super Mario file has some flaws on the melody. Please don't blame us! :/
