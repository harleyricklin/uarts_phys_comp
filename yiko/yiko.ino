#include <Adafruit_NeoPixel.h>

#define PIN 5               // this is the pin of your neopixels
#define N_LEDS 10           // make sure this is the number of pixels in your project
#define WAIT 100            // this is the number of milliseconds to wait between checking the potentiometer setting
int potentiometerPin = A0;  // select the input pin for the potentiometer
int potentiometerValue = 0; // variable to store the value coming from the potentiometer

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  // turn on the serial monitor
  Serial.begin(9600);
  Serial.println("Serial enabled");
  strip.begin();
}

void loop(){
  // read the setting of the potentiometer
  potentiometerValue = analogRead(potentiometerPin);
  Serial.print("potentiometerValue: ");
  Serial.println(potentiometerValue);   
  
  // map the potentiometer value from 0 to 1023 into a value from 0 to 255
  int lightLevel = map(potentiometerValue, 0, 1023, 0, 255);

  Serial.print("lightLevel: ");
  Serial.println(lightLevel);   
  
  // depending on which type of neopixel you have try one of the following lines
  setPixels(strip.Color(lightLevel, lightLevel, lightLevel));
  // setPixels(strip.Color(lightLevel, lightLevel, lightLevel, lightLevel));

  delay(WAIT);
}

static void setPixels(uint32_t c){
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++)
  {
    strip.setPixelColor(i, c); // set the pixel color on the strip
  }
  // change all the pixels at the same time
  strip.show();
}
