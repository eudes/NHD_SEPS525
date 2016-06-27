# NHD_SEPS525

This is a library for the 1.69" Newhaven Displays NHD-1.69-AU-SHIELD (160x128) Graphic Color OLED with the SEPS525 controller.

This controller library will allow you to access the SD card slot on the NHD-1.69-AU-SHIELD to read files and images from the SD card.
The code is written for the Arduino Uno R3.
 
To download this library, click the DOWNLOADS button in the top right corner.
1.) Uncompress the folder and verify that the NHD_SEPS525 folder contains both the NHD_SEPS525.cpp and NHD_SEPS525.h files

2.) Copy the NHD_SEPS525-master library folder into your <arduinosketchfolder>/libraries/ folder. 

3.) Install the Aidafruit GFX Library using the Library Manager within the Arduino IDE Manage Libraries.  
Or download the Adafruit GFX Graphics core from https://github.com/adafruit/Adafruit-GFX-Library and copy the Adafruit-GFX-Library-master folder into your <arduinosketchfolder>/libraries/ folder. 

5.) Restart the IDE.

6.) Verify that both of these libraries are displayed in the list of Libraries when you select Include Libraries from the Sketch menu.

You will now be able to run the example code located in the \examples folder of this repository.

When the example Arduino Uno program (located in the \bmp folder) "bmp.ino" is run, it will display the 5 bitmap images when they are placed onto a FAT32 microSD card in the NHD-1.69-AU-SHIELD.  

Newhaven Displays Datasheet:
  [1.69" Color OLED NHD-1.69-AU-SHIELD](http://www.newhavendisplay.com/specs/NHD-1.69-160128UGC3.pdf).
 
  [Controller - SEPS525](http://www.newhavendisplay.com/app_notes/SEPS525.pdf).
