/*

Hardware: (Note most of these pins can be swapped)
    Color OLED Pin----------------Arduino Pin
       MOSI       ----------------  11
       SCK        ----------------  13
       DC         ----------------  4
       RESET      ----------------  6
       OLEDCS     ----------------  5
       Vin        ----------------  5V or 3.3V
       GND        ----------------  GND

*/

#include <NHD_SEPS525.h>
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

float p = 3.1415926;


void setup(void) {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  OLED.begin();

  testdrawrects(GREEN);
  delay(1000);

  testlines(BLUE);
  delay(500);
  
  OLED.fillScreen(BLACK);
  
  testdrawtext("Full Color OLEDs are passive matrix displays that have a sharper viewing quality when compared to LCDs because of their rich black levels.", WHITE);
  delay(3500);
  
  tftPrintTest();
  delay(500);
  
}

void loop() {
}

void testdrawrects(uint16_t color) {
 OLED.fillScreen(BLACK);
 for (uint16_t x=0; x < OLED.height()-1; x+=6) {
   OLED.drawRect((OLED.width()-1)/2 -x/2, (OLED.height()-1)/2 -x/2 , x, x, color);
 }
}

void tftPrintTest() {
  OLED.fillScreen(BLACK);
  OLED.setCursor(0, 5);
  OLED.setTextColor(RED);  
  OLED.setTextSize(1);
  OLED.println("Hello World!");
  OLED.setTextColor(YELLOW);
  OLED.setTextSize(2);
  OLED.println("Hello World!");
  OLED.setTextColor(BLUE);
  OLED.setTextSize(3);
  OLED.print(1234.567);
  delay(1500);
  OLED.setCursor(0, 5);
  OLED.fillScreen(BLACK);
  OLED.setTextColor(WHITE);
  OLED.setTextSize(0);
  OLED.println("Hello World!");
  OLED.setTextSize(1);
  OLED.setTextColor(GREEN);
  OLED.print(p, 6);
  OLED.println(" Want pi?");
  OLED.println(" ");
  OLED.print(8675309, HEX); // print 8,675,309 out in HEX!
  OLED.println(" Print HEX!");
  OLED.println(" ");
  OLED.setTextColor(WHITE);
  OLED.println("Sketch has been");
  OLED.println("running for: ");
  OLED.setTextColor(MAGENTA);
  OLED.print(millis() / 1000);
  OLED.setTextColor(WHITE);
  OLED.print(" seconds.");
}

void testlines(uint16_t color) {
   OLED.fillScreen(BLACK);
   for (uint16_t x=0; x < OLED.width()-1; x+=6) {
     OLED.drawLine(0, 0, x, OLED.height()-1, color);
   }
   for (uint16_t y=0; y < OLED.height()-1; y+=6) {
     OLED.drawLine(0, 0, OLED.width()-1, y, color);
   }
   
   OLED.fillScreen(BLACK);
   for (uint16_t x=0; x < OLED.width()-1; x+=6) {
     OLED.drawLine(OLED.width()-1, 0, x, OLED.height()-1, color);
   }
   for (uint16_t y=0; y < OLED.height()-1; y+=6) {
     OLED.drawLine(OLED.width()-1, 0, 0, y, color);
   }
   
   OLED.fillScreen(BLACK);
   for (uint16_t x=0; x < OLED.width()-1; x+=6) {
     OLED.drawLine(0, OLED.height()-1, x, 0, color);
   }
   for (uint16_t y=0; y < OLED.height()-1; y+=6) {
     OLED.drawLine(0, OLED.height()-1, OLED.width()-1, y, color);
   }

   OLED.fillScreen(BLACK);
   for (uint16_t x=0; x < OLED.width()-1; x+=6) {
     OLED.drawLine(OLED.width()-1, OLED.height()-1, x, 0, color);
   }
   for (uint16_t y=0; y < OLED.height()-1; y+=6) {
     OLED.drawLine(OLED.width()-1, OLED.height()-1, 0, y, color);
   }
   
}

void testdrawtext(char *text, uint16_t color) {
  OLED.setCursor(0,0);
  OLED.setTextColor(color);
  OLED.print(text);
}
