
#include "FastLED.h"
#define NUM_LEDS 8
#define DATA_PIN 7
CRGB leds[NUM_LEDS];

// We need to specify which pins will be used to receive PWM input
// In our case, we want TWO different inputs, so we specify two different pins
int pin1 = 6;
int pin2 = 5;

int PWMinput1;
int Remapped1;
int PWMinput2;
int Remapped2;

void setup()
{
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);

  // These lines tell the Ardino that I should set the two pins listed in pin1/pin2 to "INPUT" mode
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  
  // Open up that serial port so we can get some debugging information!
  Serial.begin(9600);
}

void loop()
{  

int PWMlow1 = 900;
int PWMhigh1 = 2091;
int PWMlow2 = 1015;
int PWMhigh2 = 2010;

PWMinput1 = pulseIn(pin1, HIGH);
Remapped1 = map(PWMinput1, PWMlow1, PWMhigh1, 0, 100);

PWMinput2 = pulseIn(pin2, HIGH);
Remapped2 = map(PWMinput2, PWMlow2, PWMhigh2, 0, 500);

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
  delay(Remapped2);

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
  delay(Remapped2);
  
Serial.print(PWMinput1);
Serial.print("\t");
Serial.print(Remapped1);
Serial.print("\t");
Serial.print(PWMinput2);
Serial.print("\t");
Serial.println(Remapped2);
}


