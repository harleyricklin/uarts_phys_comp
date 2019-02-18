/* Photo Light Sensor */
int lightPin = A0;
int ledPin = 13;
int mappedLevel = 0;
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
  // step four : set the brightness of the LED using the photo sensor

  //// read in the light level
  int lightLevel = analogRead(lightPin);
  Serial.print("lightLevel value: ");
  Serial.print(lightLevel);   
  
  //// map the lightlevel to 0<=lightlevel<=255
  mappedLevel = map(lightLevel, 0, 900, 0, 255);
  Serial.print(" : lightLevel mapped value: ");
  Serial.println(mappedLevel);   

  if ( lightLevel > 810) {
    //// turn the ledPin on, write the light level to the LED
    analogWrite(ledPin, mappedLevel);
  
  
    // read the value from the sensor: 0 - 1023
    potValue = analogRead(potPin);
    Serial.print("pot value: ");
    Serial.println(potValue);

    //  WAIT : leave the LED on at this level for this amount of milliseconds
    delay(potValue);

    //// only blink if the potentiometer is set below 1000
    if (potValue < 1000){

      //// turn the ledPin off:
      analogWrite(ledPin, 0);

      // WAIT : leave the LED off for this amount of milliseconds
      delay(potValue);
    }
  } else {
      //// turn the ledPin off:
      analogWrite(ledPin, 0);
    
  }
}
