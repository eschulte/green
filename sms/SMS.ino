#include <gsmSMS.h>
#include <HardwareSerial.h>
// #define turnOnPin 40

int counter = 0;
bool success = true;
bool checkNetworkSendMessage();

// First you have to make the gsmSMS object
gsmSMS myGsmSMS(Serial, &millis, &Serial);

bool checkNetworkSendMessage(){
  return
    ((myGsmSMS.checkCREG()) &&
     (myGsmSMS.checkCSQ() > 15) &&
     myGsmSMS.sendNoSaveCMGS("14154837242",
                             "version 4, "
                             "not out killing hobos at night anymore"));
}

void setup(){
  Serial.begin(9600);
  // only needed if you have supporing hardware to turn on the Telit
  // myGsmSMS.turnOn(turnOnPin);

  /* Then call the init function which sets the band to use.
   * http://en.wikipedia.org/wiki/GSM_frequency_bands
   *
   * 0 - GSM 900MHz + DCS 1800MHz (eroupe,africa,some asia/south america)
   * 1 - GSM 900MHz + PCS 1900MHz
   * 2 - GMS 850MHz + DCS 1800MHz
   * 3 - GMS 850MHz + PCS 1900MHz (north america,some south america)
   */
  myGsmSMS.init(3);
}

void loop(){
  counter++;                          // 5 Blinks then send
  if(success) digitalWrite(13, HIGH); // set the LED on
  delay(500);                         // wait for a second
  if(success) digitalWrite(13, LOW);  // set the LED off
  delay(500);                         // wait for a second
  if(counter == 5) success = checkNetworkSendMessage();
}
