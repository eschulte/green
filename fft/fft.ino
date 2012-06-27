#include "fix_fft.h"
#include <avr/pgmspace.h>
#include <pins_arduino.h>
#define NUM_FREQS 64 /* number of frequencies to collect */

int fix_fft(char fr[], char fi[], int m, int inverse);

char im[(NUM_FREQS*2)];
char data[(NUM_FREQS*2)];

int pin_adc = 0;

void setup() {
  Serial.begin(9600);
}

void send_data(char *data){
  int i;
  for(i=(NUM_FREQS-1);i>=0;i--){
    Serial.print((int)data[i]);
    if(i != 0) Serial.print(" ");
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
    } else {
      fix_fft(data, im, 7, 0);
      for (i=0; i<NUM_FREQS;i++){
        data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
      }
      send_data(data);
    }
    tt = millis();
  }
}
