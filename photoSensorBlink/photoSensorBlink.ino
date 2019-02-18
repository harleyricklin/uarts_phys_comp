/* Photo Light Sensor */
int lightPin = A0;
int ledPin = 13;
int lastLevel = 0;
int sensorPin = A1;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  // set the led pin to output
  pinMode(ledPin, OUTPUT);
  // turn on the serial monitor
  Serial.begin(9600);
  Serial.println("Serial enabled");
}

void loop() {
  // read in the light level
  int lightLevel = analogRead(lightPin);
  // map the lightlevel to 0<=lightlevel<=255
  lightLevel = map(lightLevel, 0, 900, 0, 255);
  if (lightLevel != lastLevel) {
    lastLevel = lightLevel; 
    Serial.print("lightLevel mapped value: ");
    Serial.println(lightLevel);   
  }
  // write the light level to the LED
  analogWrite(ledPin, lightLevel); 
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  delay(sensorValue);
  if (sensorValue < 1000) {
    analogWrite(ledPin, 0);
    delay(sensorValue);
  }
}
