/* 
  Receive melodies through serial input.
  Before using your melody, please convert all NOTE_* variables into 
  their respective values through the note_replacer.html file.
  (edited by Rafael Alves, 2019)
  
  Connect a piezo buzzer or speaker to pin 10 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
*/
// change this to whichever pin you want to use
#define buzzer 10

//Declare variables for LCD screen
#include <LiquidCrystal.h>
LiquidCrystal lcd(
  7, 6, //RS and E pins
  12,11,9,8 //D4, D5, D6 and D7 pins
);
String musicName, authorName;

int divider = 0, melody[700], noteDuration = 0, posArray=0, 
  posSerial=0, splitIndex, tempo, wholenote;

void setup() {
  //Turns off Arduino's built-in LED (optional)
  pinMode(13,OUTPUT);
  digitalWrite(13, LOW);

  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  lcd.print(F("Awaiting serial"));
  Serial.println(F("Insert music data in the following format: (disable line endings!)"));
  Serial.println(F(" timer,melody,-3"));
  Serial.println(F(" name-author/"));
  while(!Serial.available()){} //Wait for user input
  while (Serial.available() > 0){
    switch(posSerial){
      case 0: //Start with the value of tempo variable, which sets song's speed
        tempo = Serial.parseInt();
        posSerial++;
        break;
      case 1: //Get melody sheet until it finds the number -3 (remember to replace variables first!)
        melody[posArray] = Serial.parseInt();
        if(melody[posArray] == -3){
          posSerial++;
          posArray = 0;
        } else{
          posArray++;
        }
        break;
      case 2: //Music and Author names
        Serial.read();
        musicName = Serial.readStringUntil('/');
        splitIndex = musicName.indexOf('-');
        authorName = musicName.substring(splitIndex + 1);
        musicName = musicName.substring(0, splitIndex);
        posSerial++;
        break;
      default: //Clear garbage
        Serial.read();
        break;
    }
  }
  posSerial = 0;
  
  //End of the serial reading, now it begins playing the music!
  Serial.println(F("Reading complete!"));
  
  //Show names on the LCD screen
  lcd.clear();
  lcd.print(musicName);
  lcd.setCursor(0,1);
  lcd.print(authorName);  
  
  // this calculates the duration of a whole note in ms
  wholenote = (60000 * 4) / tempo;
  
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; melody[thisNote] != -3; thisNote += 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}
