#include "fix_fft.h"
#include <avr/pgmspace.h>
#include <pins_arduino.h>
#define NUM_FREQS 64 /* number of frequencies to collect */

int fix_fft(char fr[], char fi[], int m, int inverse);

char im[(NUM_FREQS*2)];
char data[(NUM_FREQS*2)];

int pin_adc = 9;

void setup() {
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void send_data(char *data){
  int i;
  Serial.print("[fft] " );
  for(i=0;i<NUM_FREQS;++i){
    Serial.print((int)data[i]);
    if(i<(NUM_FREQS-1)) Serial.print(" ");
  }
  Serial.println("");
}

void loop(){
  int static i = 0;
  int total = 0;
  static long tt;
  int val;

  if (millis() > tt){
    if (i < 128){
      val = analogRead(pin_adc);
      data[i] = val / 4 - 128;
      im[i] = 0;
      i++;
    }
    else{
      //this could be done with the fix_fftr function without the im array.
      fix_fft(data, im, 7, 0);
      // I am only interessted in the absolute value of the transformation
      for (i=0; i<NUM_FREQS;i++){
        data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
      }
      // do something with the data values 1..64 and ignore im
      send_data(data);
    }

    tt = millis();
  }
}
