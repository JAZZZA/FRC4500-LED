#include <Adafruit_NeoPixel.h>

// specify the pin that we use to control the
// light strip 
#define PIN            6

// in our case we have 3 LEDs per pixel so 240 LEDs
// equates to 240/3=80 pixels 
#define NUMPIXELS      90

// delay to control speed of the light effect
#define DELAYVAL       0.1

#define ROBOT_STATE    1

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
  if (ROBOT_STATE == 1) {
    Shooter(); 
  }
}

void Shooter() {
  for(int i=1; i<NUMPIXELS+1;i++) {
    pixels.setPixelColor(i/1.01, pixels.Color(237,6,120));
    pixels.setPixelColor(i+1/1.01, pixels.Color(237,6,120));
    pixels.setPixelColor(i+2/1.01, pixels.Color(237,6,120));
    pixels.show();
    delay(DELAYVAL);
    pixels.setPixelColor(i/1.01, pixels.Color(0, 0, 255));
    pixels.show();
    delay(DELAYVAL+i/10);
  }
  for(int i=1; i<NUMPIXELS+1;i++) {
    pixels.setPixelColor(i/1.01, pixels.Color(237,6,120));
    pixels.show();
    delay(DELAYVAL);
    pixels.setPixelColor(i/1.01, pixels.Color(0, 0, 0));
    pixels.show();
    delay(DELAYVAL+i/10);
  }
}
