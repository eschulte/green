#include "fix_fft.h"

char im[128];
char data[128];

int pin_adc = 9;
int pin_led = 13;

void blink_for(int time){
  digitalWrite(13, HIGH);       // set the LED on
  delay(time);                  // wait for some time
  digitalWrite(13, LOW);        // set the LED off
  delay(500);
}

void setup() {
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);
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
      for (i=0; i<64;i++){
        data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
        total += data[i];
      }
      //do something with the data values 1..64 and ignore im
      blink_for((int)total);
    }

    tt = millis();
  }
}
