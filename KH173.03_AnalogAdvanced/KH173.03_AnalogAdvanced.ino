// Basic Piece #1
// This is the library that we're using to adress our WS2812 LEDs
#include "FastLED.h"

// Basic Piece #2
// How many LEDs will you have in your array?
#define NUM_LEDS 8

// Basic Piece #3
// We'll be using Digital Data Pin #7 on the Arduino to control the WS2812
#define DATA_PIN 7

//Basic Piece #4
// Creates an array with the length set by NUM_LEDS above
// This is the array the library will read to determine how each LED in the strand should be set
CRGB leds[NUM_LEDS];

// Basic Piece #5
// This tells the library that there is a strand of NEOPIXELS attached to the Arduino
// that they are connected to the DATA_PIN specified above
// that the library should look at the array called "leds"
// and that there are the number of LEDs in the strand as defined above in "NUM_LEDS" 
// It also opens the serial port for the PinDebug() function
void setup()
{
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
}

// This function prints the Analog pin value to the serial console
// For debugging only, not necessary for the strand to light
void PinDebug(int AnalogVal)
{
  Serial.println(AnalogVal);
  delay(100);
}

// This function is called if the value of (aRead) is 0-49
// I first clear the values of the LEDs in the strand, then I fill the array with color values, then set brightness, then pushed the values to the strand with "FastLED.show();"
// It would be REALLY easy to replace the manual setting of each array value with a loop. Why not try it?
void WS2812_Low()
{
  FastLED.clear();

  for(int fill = 0; fill < NUM_LEDS; fill++)
  {
    leds[fill] = CRGB::Purple;
  }

//  leds[0] = CRGB::Purple;
//  leds[1] = CRGB::Purple;
//  leds[2] = CRGB::Purple;
//  leds[3] = CRGB::Purple;
//  leds[4] = CRGB::Purple;
//  leds[5] = CRGB::Purple;
//  leds[6] = CRGB::Purple;
//  leds[7] = CRGB::Purple; 
//  leds[8] = CRGB::Purple;
//  leds[9] = CRGB::Purple;
//  leds[10] = CRGB::Purple;
//  leds[11] = CRGB::Purple;
//  leds[12] = CRGB::Purple;
//  leds[13] = CRGB::Purple;
//  leds[14] = CRGB::Purple;
//  leds[15] = CRGB::Purple; 
  
  FastLED.setBrightness(30);
  FastLED.show();
}

// This function is called if the value of (aRead) is 50-999
// The main loop passes (aRead), which is read into the (position) variable
// The value of (position) is used to determin the state of the WS2812 LEDs
void WS2812_Mid(int position)
{
    // This creates an integer named "LightMap" that remaps the analog pin range to the range of leds
    int LightMap = map(position, 0, 800, 0, NUM_LEDS);
 
    // Resets the LED values
    FastLED.clear();
 
    // Change led colors based on the value of the analog pin
    // Starts with blue, then green, then orange, then red. Two LEDs for each color
    for(int led = 0; led < LightMap; led++) 
    { 
      if(led < (NUM_LEDS * .25))                             leds[led] = CRGB::Blue;
      if(led >= (NUM_LEDS * .25) & led < (NUM_LEDS * .5))    leds[led] = CRGB::Green;
      if(led >= (NUM_LEDS * .5) & led < (NUM_LEDS * .75))    leds[led] = CRGB::Yellow;
      if(led >= (NUM_LEDS * .75) & led < (NUM_LEDS))         leds[led] = CRGB::Red;
     }
 
     FastLED.setBrightness(60);
     FastLED.show();
}

// This function is called if the value of (aRead) is 1000 or greater
// This fills the array twice each loop: First with Green/Red/Green/Red/Green/Red/Green/Red, then with R/G/R/G/R/G/R/G
void WS2812_High()
{
  FastLED.clear();
  leds[0] = 0x009000;
  leds[1] = 0xFF0000;
  leds[2] = 0x009000;
  leds[3] = 0xFF0000;
  leds[4] = 0x009000;
  leds[5] = 0xFF0000;
  leds[6] = 0x009000;
  leds[7] = 0xFF0000; 
  FastLED.setBrightness(30);
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
  FastLED.setBrightness(30);
  FastLED.show();
  delay(200);
}

// This loop reads the value of Analog Pin 1 into (aRead), then calls one of three functions (WS2812_Low, WS2812_Mid, or WS2812_High) depending on that value
// If it calls WS2812_Mid, it also passes the (aRead) value which is used to determine which lights should be lit in the strand
void loop()
{  
  int aRead = analogRead(1);
  PinDebug(aRead);

  if (aRead >= 0 & aRead < 50)
  {
    WS2812_Low();
  }
  
  else if (aRead >=50 & aRead < 800) 
  {
    WS2812_Mid (aRead);
  }
  
   else 
  {
    WS2812_High();
  }

}

