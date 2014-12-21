#include <SEPS525.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

// Assign to some 16bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

SEPS525 OLED;

void setup(void) {
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  OLED.begin();
}

void loop(void) {
  testFillScreen();
}

void testFillScreen() {
  OLED.fillScreen(BLACK);
  delay(500);
  OLED.fillScreen(RED);
  delay(500);
  OLED.fillScreen(GREEN);
  delay(500);
  OLED.fillScreen(BLUE);
  delay(500);
  OLED.fillScreen(BLACK);
  delay(500);
}