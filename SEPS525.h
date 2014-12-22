#ifndef _SEPS525_OLED_H_
#define _SEPS525_OLED_H_

#include <Adafruit_GFX.h>

class SEPS525 : public Adafruit_GFX {
	public:
		SEPS525(void);

		void begin(void);

		void drawPixel(int16_t x, int16_t y, uint16_t color);
		void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
		void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
		void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
		void fillScreen(uint16_t fillcolor);
		void goTo(int16_t x, int16_t y);
		uint16_t color565(uint8_t r, uint8_t g, uint8_t b);
};

//==============================================
//	SEPS225 Register
//==============================================
#define rINDEX						0x00
#define rSTATUS_RD					0x01
#define rOSC_CTL					0x02
#define rCLOCK_DIV					0x03
#define rREDUCE_CURRENT				0x04
#define rSOFT_RST					0x05
#define rDISP_ON_OFF				0x06
#define rPRECHARGE_TIME_R			0x08
#define rPRECHARGE_TIME_G			0x09
#define rPRECHARGE_TIME_B			0x0a
#define rPRECHARGE_Current_R		0x0b
#define rPRECHARGE_Current_G		0x0c
#define rPRECHARGE_Current_B		0x0d
#define rDRIVING_CURRENT_R			0x10
#define rDRIVING_CURRENT_G			0x11
#define rDRIVING_CURRENT_B			0x12
#define rDISPLAY_MODE_SET			0x13
#define rRGB_IF						0x14
#define rRGB_POL					0x15
#define rMEMORY_WRITE_MODE			0x16
#define rMX1_ADDR					0x17
#define rMX2_ADDR					0x18
#define rMY1_ADDR					0x19
#define rMY2_ADDR					0x1A
#define rMEMORY_ACCESS_POINTER_X	0x20
#define rMEMORY_ACCESS_POINTER_Y	0x21
#define rDDRAM_DATA_ACCESS_PORT		0x22
#define rDUTY						0x28
#define rDSL						0x29
#define rD1_DDRAM_FAC				0x2E
#define rD1_DDRAM_FAR				0x2F
#define rD2_DDRAM_SAC				0x31
#define rD2_DDRAM_SAR				0x32
#define rSCR1_FX1					0x33
#define rSCR1_FX2					0x34
#define rSCR1_FY1					0x35
#define rSCR1_FY2					0x36
#define rSCR2_SX1					0x37
#define rSCR2_SX2					0x38
#define rSCR2_SY1					0x39
#define rSCR2_SY2					0x3A
#define rSCREEN_SAVER_CONTEROL		0x3B
#define rSS_SLEEP_TIMER				0x3C
#define rSCREEN_SAVER_MODE			0x3D
#define rSS_SCR1_FU					0x3E
#define rSS_SCR1_MXY				0x3F
#define rSS_SCR2_FU					0x40
#define rSS_SCR2_MXY				0x41
#define rMOVING_DIRECTION			0x42
#define rSS_SCR2_SX1				0x47
#define rSS_SCR2_SX2				0x48
#define rSS_SCR2_SY1				0x49
#define rSS_SCR2_SY2				0x4A
#define rIREF						0x80

#define Red						    (0x3f)<<11
#define Green						(0x3f)<<5
#define Blue						(0x3f)
#define White						Red|Blue|Green

#define	col		160
#define row		128

#define DrivingR		0x45	//廠內:0xff 170
#define DrivingG		0x34	//廠內:0xff	170
#define DrivingB		0x33	//廠內:0xff	200
#define PreTimeR		0x04	//廠內:0x0e 03
#define PreTimeG		0x05	//廠內:0x0e 03
#define PreTimeB		0x05	//廠內:0x0e 03
#define PreCurrentR 	0x9D	//廠內:0xff D
#define PreCurrentG		0x8C	//廠內:0xff D
#define PreCurrentB		0x57	//廠內:0xff D

#endif