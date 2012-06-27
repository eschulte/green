int i;

void setup() {
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void send_data(int value){
  Serial.print(".oO(data:");
  Serial.print(value);
  Serial.println(")");
}

void loop(){
  i++;
  digitalWrite(13, HIGH);   // set the LED on
  delay(500);               // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(500);               // wait for a second
  send_data(i);
}