/* Photo Light Sensor */
int lightPin = A0;
int ledPin = 13;
int lastLevel = 0;
int potPin = A1;
int potValue = 0;

void setup(){
  // set the led pin to output
  pinMode(ledPin, OUTPUT);
  // turn on the serial monitor
  Serial.begin(9600);
  Serial.println("Serial enabled");
}

void loop(){
  // step two : keep the LED on when pot is all the way turned

  // turn the ledPin on
  digitalWrite(ledPin, HIGH);

  // read the value from the sensor: 0 - 1023
  potValue = analogRead(potPin);

  //  WAIT : leave the LED on at this level for this amount of milliseconds
  delay(potValue);

  // only blink if the potentiometer is set below 1000
  if (potValue < 1000){

    // turn the ledPin off:
    digitalWrite(ledPin, LOW);

    // WAIT : leave the LED off for this amount of milliseconds
    delay(potValue);
  }
}
