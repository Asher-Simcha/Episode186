#include "FastLED.h"
#define NUM_LEDS 8
#define DATA_PIN 7
CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
}


void loop()
{  
  int aRead = analogRead(1);
   
  Serial.println(aRead);


  FastLED.clear();
  leds[0] = 0x009000;
  leds[1] = 0xFF0000;
  leds[2] = 0x009000;
  leds[3] = 0xFF0000;
  leds[4] = 0x009000;
  leds[5] = 0xFF0000;
  leds[6] = 0x009000;
  leds[7] = 0xFF0000; 
  FastLED.setBrightness(aRead);
  FastLED.show();
  delay(200);

  FastLED.clear();
  leds[0] = 0xFF0000;
  leds[1] = 0x009000;
  leds[2] = 0xFF0000;
  leds[3] = 0x009000;
  leds[4] = 0xFF0000;
  leds[5] = 0x009000;
  leds[6] = 0xFF0000; 
  leds[7] = 0x009000;
  FastLED.setBrightness(aRead);
  FastLED.show();
  delay(200);

}

