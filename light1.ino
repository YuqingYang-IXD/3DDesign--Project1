 /* 
  * Modified by Yuqing Yang
  * Modified from NeoPixel Ring simple sketch (c) 2013 Shae Erisson, Released under the GPLv3 license to match the rest of the Adafruit NeoPixel library
  * This code works with a 12 ring adafruit neopixel
  * It makes the lights changes over time randomly
  */
  
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        6 // Attach the neopixel on pin 6
#define NUMPIXELS 12 // NeoPixel 12 ring

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}
int a,b,c;

void loop() {
  a=random(0,255);
  b=random(0,255);
  c=random(0,255);
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(a, b, c));
    pixels.show();   // Send the updated pixel colors to the hardware.
  }
  delay(1000);
}
