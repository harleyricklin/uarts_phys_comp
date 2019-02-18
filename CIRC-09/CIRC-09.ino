// CIRC09 - Light
int lightPin = A0;
int ledPin = 13;

void setup()
{
  // set the ledPin for ouput
  pinMode(ledPin, OUTPUT); 

  // enable the serial monitor at 9600 baud
  Serial.begin(9600);
  // print a message so we know this is working
  Serial.println("Serial Monitor Started");
}

void loop()
{
  // read in the light level
  int lightLevel = analogRead(lightPin); 

  // print the lightLevel we are getting from the sensor
  Serial.print("photo sensor level : ");
  Serial.print(lightLevel);

  // change the lightLevel to be inside the range 0-255 to be compatible with the LED
  lightLevel = map(lightLevel, 0, 900, 0, 255);

  // print the newly mapped lightLevel
  Serial.print(" : LED mapped level : ");
  Serial.println(lightLevel);

  // turn on the LED, set the brightness to lightLevel
  analogWrite(ledPin, lightLevel);
}
