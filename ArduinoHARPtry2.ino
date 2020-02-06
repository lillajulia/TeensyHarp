int sensor1 = 0;
int sensorGuitarBlue = 0;
int sensorBassGreen = 0;
int sensorKeysOrange = 0;
float C = 130.81;
float B = 233.08;
float F = 349.23;
float G = 392.00;
float Bb = 466.16;
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code

AudioSynthWaveformSine   sine1;
AudioSynthSimpleDrum     drum1;          //xy=361,123
AudioSynthKarplusStrong  string1;        //xy=171,256
AudioOutputI2S           i2s1;           //xy=639,97
//AudioConnection          patchCord1(drum1, 0, i2s1, 0);
//AudioConnection          patchCord1(string1, 0, i2s1, 0);
AudioConnection          patchCord1(sine1, 0, i2s1, 0);
AudioControlSGTL5000    audioShield;     //xy=227,59.00000190734863
// GUItool: end automatically generated code

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) ;
  AudioMemory(2);

  audioShield.enable();
  audioShield.volume(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor1 = analogRead(0);
  Serial.print("Yellow ");
  Serial.println(sensor1);

  delay(100);
  //  if (analogRead(0) >= 100 && analogRead(0) < 200) {
  //    drum1.noteOn();
  //    drum1.frequency(60);
  //  } else if (analogRead(0) >= 200 && analogRead(0) < 300){
  //    drum1.noteOn();
  //    drum1.frequency(500);
  //    } else if (analogRead(0) >= 300){
  //
  //      drum1.noteOn();
  //      drum1.frequency(1200);
  //      }

  if (analogRead(0) > 50 && sensor1 < 100) {
    sine1.amplitude(1.0);
    sine1.frequency(C);
  }
  else if (sensor1 > 100 && sensor1 < 200 ) {
    sine1.amplitude(1.0);
    sine1.frequency(B);
  } else if (sensor1 > 200 && sensor1 < 300 ) {
    sine1.amplitude(1.0);
    sine1.frequency(F);
  } else if (sensor1 > 300 && sensor1 < 400 ) {
    sine1.amplitude(1.0);
    sine1.frequency(G);
  } else if (sensor1 > 400 && sensor1 < 1000 ) {
    sine1.amplitude(1.0);
    sine1.frequency(Bb);
  } else {
    sine1.amplitude(0);
    }
}
