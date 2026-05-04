#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <avr/pgmspace.h>
#include "happy_animation.h"  //includes happy sprites for good soil
#include "sad_animation.h"    //includes sad sprites for dry soil
#include "too_wet_animation.h" // includes sad sprites for wet soil

/* pin definitions lcd*/
#define TFT_CS   10
#define TFT_DC    7
#define TFT_RST   8
/*sensor data*/
int CS = A0;
int Dirt = 0;


Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

const int IMG_W = 32;
const int IMG_H = 37;



void drawScaledImageFullScreen(const uint16_t *sprite) {
  for (int y = 0; y < 280; y++) {
    int srcY = (y * IMG_H) / 280;

    for (int x = 0; x < 240; x++) {
      int srcX = (x * IMG_W) / 240;
      uint16_t color = pgm_read_word(&sprite[srcY * IMG_W + srcX]);
      tft.drawPixel(x, y, color);
    }
  }
}

void setup() {
  tft.init(240, 280); //size of lcd
  tft.setRotation(0); // orientation
  Serial.begin(9600);       // Initialize serial communication


}

void loop() {
  Dirt = analogRead(CS);
  Serial.print("Mositure: "); Serial.println(Dirt);
  if (Dirt > 500){
    drawScaledImageFullScreen(cat_sad_1);
    drawScaledImageFullScreen(cat_sad_2);
    drawScaledImageFullScreen(cat_sad_3);
    drawScaledImageFullScreen(cat_sad_2);
  }
  else if (Dirt < 250){
    drawScaledImageFullScreen(too_wet_1);
    drawScaledImageFullScreen(too_wet_2);
    drawScaledImageFullScreen(too_wet_1);
    drawScaledImageFullScreen(too_wet_2);

  }
  else{
    drawScaledImageFullScreen(happy_tail_up);
    drawScaledImageFullScreen(happy_tail_down);
    drawScaledImageFullScreen(happy_tail_up);
    drawScaledImageFullScreen(happy_tail_down);

  }






}