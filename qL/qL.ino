#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void RedPattern()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, strip.Color(255,0,0));
  }
  strip.show(); 
}

void MidPattern()
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, strip.Color(255,127,127));
  }
  strip.show(); 
}  

void BluePattern()
{
  for(uint16_t i=0; i<strip.numPixels(); i++)
  {clear
      strip.setPixelColor(i, strip.Color(255,255,255));
  }
   strip.show();
}  

void setup() {
  // this function
  Serial.begin(9600); 
  strip.begin();
}  
    
void loop() {
  while (Serial.available() > 0) {
    int input = Serial.parseInt();
    if (input == 2)
     {
      RedPattern();
     }
    else if(input == 1)
     {
      MidPattern();   
     }
    else 
     {
      BluePattern();  
     }
    }
  // Finally showing all the LEDsstrip.show(); // Initialize all pixels to 'off
 }


