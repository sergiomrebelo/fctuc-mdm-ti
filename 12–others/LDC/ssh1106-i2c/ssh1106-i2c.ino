#include <U8g2lib.h>
#include <Wire.h>

// 128 x 64
U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);


void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.firstPage();      
  do {
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(0, 20, "Hello World!");
  } while (u8g2.nextPage()); 

  delay(1000);
}