char my_str[] = "Blue";
int sensorDrumYellow = 0;
int sensorGuitarBlue = 0;
int sensorBassGreen = 0;
int sensorKeysOrange = 0;
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthSimpleDrum     drum1;          //xy=361,123
AudioSynthSimpleDrum     drum2;
AudioSynthSimpleDrum     drum3;
AudioSynthSimpleDrum     drum4;
AudioOutputI2S           i2s1;           //xy=639,97
AudioConnection          patchCord1(drum1, 0, i2s1, 0);
AudioConnection          patchCord2(drum2, 0, i2s1, 0);
AudioConnection          patchCord3(drum3, 0, i2s1, 0);
AudioConnection          patchCord4(drum4, 0, i2s1, 0);
AudioControlSGTL5000    audioShield;     //xy=227,59.00000190734863
// GUItool: end automatically generated code

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) ;
  AudioMemory(2);

  audioShield.enable();
  audioShield.volume(10);
}

void updateSerial () {
  sensorDrumYellow = analogRead(A0);
  Serial.println(sensorDrumYellow);
  sensorGuitarBlue = analogRead(A1);
  Serial.println(my_str);
  Serial.println(sensorGuitarBlue);
  sensorBassGreen = analogRead(A2);
  Serial.println( sensorBassGreen);
  sensorKeysOrange = analogRead(A3);
  Serial.println(sensorKeysOrange);


}

void playMusic () {
  delay(100);
  if (analogRead(A0) > 100) {
    drum1.noteOn();
  }
  if (analogRead(A1) > 100) {
    drum2.noteOn();
  }
  if (analogRead(A2) > 100) {
    drum3.noteOn();
  }
  if (analogRead(A3) > 100) {
    drum4.noteOn();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  updateSerial ();
  playMusic ();

  //  if (sensorValue < 100){
  //    drum1.pitchMod(0.7);
  //    } else if(sensorValue >= 100 && sensorValue < 300){
  //      drum1.pitchMod(0.5);
  //      } else if(sensorValue >= 300 && sensorValue < 500){
  //      drum1.pitchMod(0.3);
  //      }
}
