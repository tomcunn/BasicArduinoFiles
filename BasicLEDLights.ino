#include <Adafruit_NeoPixel.h>

#define PIN D3
#define LED_STRING_LENGTH 8
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, PIN);

void setup() 
{
  pixels.begin();
}

void loop() 
{
  //Loop through every LED
  for(int n = 0; n <= LED_STRING_LENGTH ; n++)
  {
    pixels.setPixelColor(n,pixels.Color(0,0,255));
  }
  //Call the show pixel function
  pixels.show();
  
  //Add this in here to service the watchdog
  delay(10);
}
