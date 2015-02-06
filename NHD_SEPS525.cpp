#include <NHD_SEPS525.h>
#include <SPI.h>

static const int pinVddEnable = 7;
static const int pinRS = 4;
static const int pinSS = 5;
static const int pinReset = 6;

static void SEPS525_reg(int idx, int value)
{
  digitalWrite(pinSS, LOW);
  digitalWrite(pinRS, LOW);
  SPI.transfer(idx);
  digitalWrite(pinRS, HIGH);
  digitalWrite(pinSS, HIGH);
  digitalWrite(pinSS, LOW);
  SPI.transfer(value);
  digitalWrite(pinSS, HIGH);
}

static inline void SEPS525_datastart(void)
{
  digitalWrite(pinSS, LOW);
  digitalWrite(pinRS, LOW);
  SPI.transfer(rDDRAM_DATA_ACCESS_PORT);
  digitalWrite(pinRS, HIGH);
}

static inline void SEPS525_data(int value)
{
  SPI.transfer((value>>8)& 0xFF);
  SPI.transfer(value & 0xFF);
}

static inline void SEPS525_dataend(void)
{
  digitalWrite(pinSS, HIGH);
}

static void SEPS525_set_region(int x, int y, int xs, int ys)
{
  // draw region
  SEPS525_reg(rMX1_ADDR,x);
  SEPS525_reg(rMX2_ADDR,x+xs-1);
  SEPS525_reg(rMY1_ADDR,y);
  SEPS525_reg(rMY2_ADDR,y+ys-1);
  
  // start position
  SEPS525_reg(rMEMORY_ACCESS_POINTER_X,x);
  SEPS525_reg(rMEMORY_ACCESS_POINTER_Y,y);
}

static void SEPS525_setup(void) 
{
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE3);
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  
  // pin for switcher enable (off by default)
  digitalWrite(pinVddEnable, HIGH);
  pinMode(pinVddEnable, OUTPUT);
  
  // pins for SEPS525
  digitalWrite(pinRS, HIGH);
  digitalWrite(pinSS, HIGH);
  digitalWrite(pinReset, HIGH);
  pinMode(pinRS, OUTPUT);
  pinMode(pinSS, OUTPUT);
  pinMode(pinReset, OUTPUT);
}
  
static void SEPS525_init(void)
{
  SEPS525_setup();
  
  digitalWrite(pinReset, LOW);
  delay(2);
  digitalWrite(pinReset, HIGH);
  delay(1);
  // display off, analog reset
  SEPS525_reg(rREDUCE_CURRENT, 0x01);
  delay(1);
  // normal mode
  SEPS525_reg(rREDUCE_CURRENT, 0x00);
  delay(1);
  // display off
  SEPS525_reg(rDISP_ON_OFF, 0x00);
  // turn on internal oscillator using external resistor
  SEPS525_reg(rOSC_CTL, 0x01);
  // 90 hz frame rate, divider 0
  SEPS525_reg(rCLOCK_DIV, 0x30);
  // duty cycle 127
  SEPS525_reg(rDUTY, 0x7f);
  // start on line 0
  SEPS525_reg(rDSL, 0x00);
  // rgb_if
  SEPS525_reg(rRGB_IF, 0x31);
  // memory write mode
  SEPS525_reg(rMEMORY_WRITE_MODE, 0x66);

  // driving current r g b (uA)
  SEPS525_reg(rDRIVING_CURRENT_R, DrivingR);
  SEPS525_reg(rDRIVING_CURRENT_G, DrivingG);
  SEPS525_reg(rDRIVING_CURRENT_B, DrivingB);

  // precharge time r g b
  SEPS525_reg(rPRECHARGE_TIME_R, PreTimeR);
  SEPS525_reg(rPRECHARGE_TIME_G, PreTimeG);
  SEPS525_reg(rPRECHARGE_TIME_B, PreTimeB);

  // precharge current r g b (uA)
  SEPS525_reg(rPRECHARGE_Current_R, PreCurrentR);
  SEPS525_reg(rPRECHARGE_Current_G, PreCurrentG);
  SEPS525_reg(rPRECHARGE_Current_B, PreCurrentB);

  	SEPS525_reg(rDISPLAY_MODE_SET,0x00); 						//Reg:13h	Action:Col D0 to D159/col normal display
	  SEPS525_reg(rMX1_ADDR,0x00); 										//Reg:17h	Action:Memory addr.X start
	  SEPS525_reg(rMX2_ADDR,col-1); 									//Reg:18h	Action:Memory addr.X end
	  SEPS525_reg(rMY1_ADDR,0x00); 										//Reg:18h	Action:Memory addr.Y start
	  SEPS525_reg(rMY2_ADDR,row-1);  									//Reg:1Ah	Action:Memory addr.Y end
	  SEPS525_reg(rMEMORY_ACCESS_POINTER_X,0x00);			//Reg:20h	Action:Memory X start addr.
	  SEPS525_reg(rMEMORY_ACCESS_POINTER_Y,0x00); 		//Reg:21h	Action:Memory Y start addr.
	  SEPS525_reg(rD1_DDRAM_FAC,0x00);     						//Reg:2Eh	Action:Display First screen X start point
	  SEPS525_reg(rD1_DDRAM_FAR,0x00);								//Reg:2Fh	Action:Display First screen Y start point
	  SEPS525_reg(rD2_DDRAM_SAR,0x00); 								//Reg:31h	Action:Display Second screen X start point
	  SEPS525_reg(rD2_DDRAM_SAR,0x00); 								//Reg:32h	Action:Display Second screen Y start point
	  SEPS525_reg(rSCR1_FX1,0x00); 										//Reg:33h	Action:Display size X start
	  SEPS525_reg(rSCR1_FX2,col-1); 									//Reg:34h	Action:Display size X end
	  SEPS525_reg(rSCR1_FY1,0x00); 										//Reg:35h	Action:Display size Y start
	  SEPS525_reg(rSCR1_FY2,row-1); 						//Reg:04h	Action:Normal current and PS OFF
  SEPS525_reg(rDISP_ON_OFF, 0x01);
}

SEPS525::SEPS525(void) : Adafruit_GFX(col, row) 
{
}

void SEPS525::begin(void)
{
	SEPS525_init();
}

void SEPS525::goTo(int16_t x, int16_t y)
{
	SEPS525_set_region(x, y, col-x, row-y);  
}

void SEPS525::drawPixel(int16_t x, int16_t y, uint16_t color)
{
	SEPS525_set_region(x, y, 1, 1);
	SEPS525_datastart();
	SEPS525_data(color);
	SEPS525_dataend();
}

void SEPS525::drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
	SEPS525_set_region(x, y, 1, h);
	SEPS525_datastart();
	int n;
	for(n = 0; n < h; n++) SEPS525_data(color);
	SEPS525_dataend();
}

void SEPS525::drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
{
	SEPS525_set_region(x, y, w, 1);
	SEPS525_datastart();
	int n;
	for(n = 0; n < w; n++) SEPS525_data(color);
	SEPS525_dataend();
}

void SEPS525::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
	SEPS525_set_region(x, y, w, h);
	SEPS525_datastart();
	int n;
	for(n = 0; n < h*w; n++) SEPS525_data(color);
	SEPS525_dataend();
}

void SEPS525::fillScreen(uint16_t fillcolor) {
  fillRect(0, 0, col, row, fillcolor);
}

uint16_t SEPS525::color565(uint8_t r, uint8_t g, uint8_t b)
{
	//return (r << 11) | (g << 5) | b;
	uint16_t c;
  c = r >> 3;
  c <<= 6;
  c |= g >> 2;
  c <<= 5;
  c |= b >> 3;

  return c;
}