
#include "FastLED.h"
#define NUM_LEDS 8
#define DATA_PIN 7
CRGB leds[NUM_LEDS];

// We need to specify which pins will be used to receive PWM input
// In our case, we want TWO different inputs, so we specify two different pins
int pin1 = 6;

int PWMinput1;
int Remapped1;


void setup()
{
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);

  // These lines tell the Ardino that I should set the two pins listed in pin1/pin2 to "INPUT" mode
  pinMode(pin1, INPUT);
  
  // Open up that serial port so we can get some debugging information!
  Serial.begin(9600);
}

void loop()
{  

int PWMlow1 = 900;
int PWMhigh1 = 2091;

PWMinput1 = pulseIn(pin1, HIGH);
    // This remapps the PWM value to a value between 0 and 100: the proper settings for brightness    
Remapped1 = map(PWMinput1, PWMlow1, PWMhigh1, 0, 100);
    // This gets the input from the second PWM encoder

  FastLED.clear();
  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Blue;
  leds[4] = CRGB::Blue;
  leds[5] = CRGB::Blue;
  leds[6] = CRGB::Blue;
  leds[7] = CRGB::Blue; 
  
  FastLED.setBrightness(Remapped1);
  FastLED.show();
  delay(200);

  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[2] = CRGB::Red;
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red; 
  
  FastLED.setBrightness(Remapped1);
  FastLED.show();
  delay(200);
  
Serial.print(PWMinput1);
Serial.print("\t");
Serial.println(Remapped1);

}


