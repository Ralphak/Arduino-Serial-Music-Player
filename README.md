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

## Contents
* **music_player_serial.ino:** The code to be loaded into the Arduino
* **note_replacer.html:** A tool to convert melody strings with NOTE_* variables into their respective values
* **songs folder:** Some examples of melodies you can try. Simply copy a file's contents and paste on the terminal.
