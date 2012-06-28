/* Adapted from:
 * SparkFun Cellular Shield - Pass-Through Sample Sketch
 * SparkFun Electronics Written by Ryan Owens CC by v3.0 3/8/10
 * Thanks to Ryan Owens and Sparkfun for sketch
 *
 * customized by Eric Schulte
 */

#include <string.h>
char incoming_char=0;
SoftSerial cell(2,3);

bool gsm_connect_in_txt_mode(){
  cell.println("AT+CMGF=1");
  delay(2000);
  cell.println("AT+CNMI=0,0,0,0,0");
  delay(2000);
  cell.println("AT#SMSMODE=0");
  delay(2000);
  return true;
}

bool gsm_set_band(int band){
  cell.print("AT#BND=");
  cell.println(band);
  delay(2000);
  return true;
}

bool gsm_send_text(char *number, char *message){
  cell.print("AT+CMGS=\"");
  cell.print(number);
  cell.println("\"");
  delay(500);
  cell.print(message);
  cell.println("");
  delay(2000);
  return true;
}

void setup() {
  // Initialize serial ports for communication.
  Serial.begin(9600);
  cell.begin(115200);
  Serial.println("Connecting to GSM module");
  gsm_connect_in_txt_mode();    // Connect to the network to send SMS messages
  gsm_set_band(3);              // Band 3 for North America
  gsm_send_text("14154837242", "LUDDITES");
}

void loop() {
  // If a character comes in from the cellular module...
  if(cell.available()>0) {
      incoming_char=cell.read();   // Get the character from the cellular serial port.
      Serial.print(incoming_char); // Print the incoming character to the terminal.
  }
  // If a character is coming from the terminal to the Arduino...
  if(Serial.available()>0) {
      incoming_char=Serial.read(); // Get the character coming from the terminal
      cell.print(incoming_char);   // Send the character to the cellular module.
  }
}
