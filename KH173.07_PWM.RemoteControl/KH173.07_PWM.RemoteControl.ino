
#include "FastLED.h"
#define NUM_LEDS 26
#define DATA_PIN 7
CRGB leds[NUM_LEDS];

int pin1 = 6;
int pin2 = 5;

int PWMinput1;
int Remapped1;
int PWMinput2;
int Remapped2;  

void setup()
{
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  
  Serial.begin(9600);
}


void loop()
{  
int PWMlow1 = 980;
int PWMhigh1 = 1955;

int PWMlow2 = 975;
int PWMhigh2 = 1955; 
  
  for(int x=0; x<NUM_LEDS; x++)
  {
    // This gets the input from the first PWM encoder
    PWMinput1 = pulseIn(pin1, HIGH);
    // This remapps the PWM value to a value between 0 and 100: the proper settings for brightness    
    Remapped1 = map(PWMinput1, PWMlow1, PWMhigh1, 0, 100);
    // This gets the input from the second PWM encoder
    PWMinput2 = pulseIn(pin2, HIGH);
    // This remapps the PWM value to a value between 0 and 500: allowing us a decent range for the delay
    Remapped2 = map(PWMinput2, PWMlow1, PWMhigh1, 0, 500);

    // Yah for debug!
    Serial.print(PWMinput1);
    Serial.print("\t");
    Serial.print(Remapped1);
    Serial.print("\t");
    Serial.print(PWMinput2);
    Serial.print("\t");
    Serial.println(Remapped2);
    
    // This sets the color of the LEDs in this loop
    leds[x] = CRGB::Red;
    
    // This sets the brightness of the LEDs based on the PWM device attached to pin 6
    FastLED.setBrightness(Remapped1);
    
    // This pushes the color and brightness of the LED to the Pixel strand
    FastLED.show();
    
    // This sets the delay based on the PWM device attached to pin 5
    delay(Remapped2);
  }

for(int x=0; x<NUM_LEDS; x++)
  {
    // This gets the input from the first PWM encoder
    PWMinput1 = pulseIn(pin1, HIGH);
    // This remapps the PWM value to a value between 0 and 100: the proper settings for brightness    
    Remapped1 = map(PWMinput1, PWMlow1, PWMhigh1, 0, 100);
    // This gets the input from the second PWM encoder
    PWMinput2 = pulseIn(pin2, HIGH);
    // This remapps the PWM value to a value between 0 and 500: allowing us a decent range for the delay
    Remapped2 = map(PWMinput2, PWMlow1, PWMhigh1, 0, 500);
    Serial.print(PWMinput1);
    Serial.print("\t");
    Serial.print(Remapped1);
    Serial.print("\t");
    Serial.print(PWMinput2);
    Serial.print("\t");
    Serial.println(Remapped2);
    leds[x] = CRGB::Green;
    FastLED.setBrightness(Remapped1);
    FastLED.show();
    delay(Remapped2);
}

for(int x=0; x<NUM_LEDS; x++)
  {
    // This gets the input from the first PWM encoder
    PWMinput1 = pulseIn(pin1, HIGH);
    // This remapps the PWM value to a value between 0 and 100: the proper settings for brightness    
    Remapped1 = map(PWMinput1, PWMlow1, PWMhigh1, 0, 100);
    // This gets the input from the second PWM encoder
    PWMinput2 = pulseIn(pin2, HIGH);
    // This remapps the PWM value to a value between 0 and 500: allowing us a decent range for the delay
    Remapped2 = map(PWMinput2, PWMlow1, PWMhigh1, 0, 500);
    Serial.print(PWMinput1);
    Serial.print("\t");
    Serial.print(Remapped1);
    Serial.print("\t");
    Serial.print(PWMinput2);
    Serial.print("\t");
    Serial.println(Remapped2);
    leds[x] = CRGB::Blue;
    FastLED.setBrightness(Remapped1);
    FastLED.show();
    delay(Remapped2);
}

 
}


