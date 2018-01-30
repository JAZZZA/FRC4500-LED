#include <Adafruit_NeoPixel.h>

// specify the pin that we use to control the
// light strip 
#define PIN            6

// in our case we have 3 LEDs per pixel so 240 LEDs
// equates to 240/3=80 pixels 
#define NUMPIXELS      80

// delay to control speed of the light effect
#define DELAYVAL       20


// construct and configure the pixel array
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

// Most of the world specifies colours in the order "R-G-B"
// but for some reason this library (or maybe it is the
// cheap LED light strip that we have) has the order "R-B-G"
// instead. Anyway, here are some colours to play with ...
//
//       R   B   G   COLOUR
//     ====================
//       0   0   0   OFF
//     255   0   0   RED
//       0   0 255   GREEN
//       0 255   0   BLUE
//     255 255 255   WHITE
//     255   0 255   YELLOW
//     128 255   0   PURPLE
//     175 148  75   PINK
//     237   6 120   ORANGE

void loop() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1
  // all the way up to the count of pixels minus one

  // There are alternative ways of writing this code but this
  // code illustrates how easy it is to get some good effects
  // with some very simple software ...

  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RBG values
    // from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255,0,0)); // RED
    // send updated pixel color to the hardware
    pixels.show();
    // Delay for a period of time (in milliseconds).
    delay(DELAYVAL);
  }

  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RBG values
    // from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // OFF
    // send updated pixel color to the hardware
    pixels.show();
    // Delay for a period of time (in milliseconds).
    delay(DELAYVAL);
  }

  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RBG values
    // from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,255)); // GREEN
    // send updated pixel color to the hardware
    pixels.show();
    // Delay for a period of time (in milliseconds).
    delay(DELAYVAL);
  }

  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RBG values
    // from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // OFF
    // send updated pixel color to the hardware
    pixels.show();
    // Delay for a period of time (in milliseconds).
    delay(DELAYVAL);
  }

  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RBG values
    // from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,255,0)); // BLUE
    // send updated pixel color to the hardware
    pixels.show();
    // Delay for a period of time (in milliseconds).
    delay(DELAYVAL);
  }

  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RBG values
    // from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // OFF
    // send updated pixel color to the hardware
    pixels.show();
    // Delay for a period of time (in milliseconds).
    delay(DELAYVAL);
  }
  //Fade Code
for(int i=0; i<NUMPIXELS;i++) {
  pixels.setPixelColor(i, pixels.Color(255,0,0));
  pixels.setBrightness(i);
  pixels.show();
  delay(DELAYVAL);
}
for(int i=255; i>NUMPIXELS;i--) {
  pixels.setPixelColor(i, pixels.Color(0,255,0));
  pixels.setBrightness(i);
  pixels.show();
  delay(DELAYVAL);
}
}
