
// This is the library that we're using to adress our WS2812 LEDs
#include "FastLED.h"

// How many LEDs will you have in your array?
#define NUM_LEDS 50

// We'll be using Digital Data Pin #7 on the Arduino to control the WS2812
#define DATA_PIN 7

// Creates an array with the length set by NUM_LEDS above
// This is the array the library will read to determine how each LED in the strand should be set
CRGB leds[NUM_LEDS];

// We need to specify which pins will be used to receive PWM input
// In our case, we want TWO different inputs, so we specify two different pins
int pin1 = 6;
int pin2 = 5;

CRGB LEDcolor[4] = {0x0000FF, 0xFF0000, 0x008000, 0xEE82EE};

// It also opens the serial port so we can debug
void setup()
{
  // This tells the library that there is a strand of NEOPIXELS attached to the Arduino
  // that they are connected to the DATA_PIN specified above
  // that the library should look at the array called "leds"
  // and that there are the number of LEDs in the strand as defined above in "NUM_LEDS" 
  FastLED.addLeds<NEOPIXEL,DATA_PIN>(leds, NUM_LEDS);
  
  // These lines tell the Ardino that I should set the two pins listed in pin1/pin2 to "INPUT" mode
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  
  // Open up that serial port so we can get some debugging information!
  Serial.begin(9600);
}

void SerialDebug(int a, int b, int c, int d)
{
  Serial.print(a);
  Serial.print("\t");
  Serial.print(b);
  Serial.print("\t");
  Serial.print(c);
  Serial.print("\t");
  Serial.println(d);
}



// So much of this should be in separate functions... but you know what... YOU do it!
void loop()
{  
int PWMinput1;
int Remapped1;  
// These are the high and low values of PWM device 1  
int PWMlow1 = 905;
int PWMhigh1 = 2090;

int PWMinput2;
int Remapped2;  
// These are the high and lwo values of PWM device 2
int PWMlow2 = 1016;
int PWMhigh2 = 2010; 
  
for (int y=0; y<4; y++)
{
  for(int x=0; x<NUM_LEDS; x++)
  {
    // This gets the input from the first PWM encoder
    PWMinput1 = pulseIn(pin1, HIGH);
    // This remapps the PWM value to a value between 0 and 100: the proper settings for brightness    
    Remapped1 = map(PWMinput1, PWMlow1, PWMhigh1, 0, 100);
  
    
    // This gets the input from the second PWM encoder
    PWMinput2 = pulseIn(pin2, HIGH);
    // This remapps the PWM value to a value between 0 and 500: allowing us a decent range for the delay
    Remapped2 = map(PWMinput2, PWMlow2, PWMhigh2, 0, 500);

    SerialDebug(PWMinput1, Remapped1, PWMinput2, Remapped2);
    
    // This sets the color of the LEDs in this loop
    leds[x] = LEDcolor[y];
    
    // This sets the brightness of the LEDs based on the PWM device attached to pin 6
    FastLED.setBrightness(Remapped1);
    
    // This pushes the color and brightness of the LED to the Pixel strand
    FastLED.show();
    
    // This sets the delay based on the PWM device attached to pin 5
    delay(Remapped2);
  }
  
  for(int x=NUM_LEDS; x>0; x=x-1)
  {
    // This gets the input from the first PWM encoder
    PWMinput1 = pulseIn(pin1, HIGH);
    // This remapps the PWM value to a value between 0 and 100: the proper settings for brightness    
    Remapped1 = map(PWMinput1, PWMlow1, PWMhigh1, 0, 100);
  
    
    // This gets the input from the second PWM encoder
    PWMinput2 = pulseIn(pin2, HIGH);
    // This remapps the PWM value to a value between 0 and 500: allowing us a decent range for the delay
    Remapped2 = map(PWMinput2, PWMlow2, PWMhigh2, 0, 500);

    SerialDebug(PWMinput1, Remapped1, PWMinput2, Remapped2);
    
    // This sets the color of the LEDs in this loop
    leds[x] = LEDcolor[y-1];
    
    // This sets the brightness of the LEDs based on the PWM device attached to pin 6
    FastLED.setBrightness(Remapped1);
    
    // This pushes the color and brightness of the LED to the Pixel strand
    FastLED.show();
    
    // This sets the delay based on the PWM device attached to pin 5
    delay(Remapped2);
  }
}
  for(int x=0; x<NUM_LEDS; x++)
  {
    leds[x] = 0x0000FF;
 
  }

  for(int y=0; y<101; y++)
  {
  FastLED.setBrightness(y);
  FastLED.show();
  delay(10);
  }
  
  for(int y=100; y>0; y--)
  {
  FastLED.setBrightness(y);
  FastLED.show();
  delay(10);
  }
 
}


