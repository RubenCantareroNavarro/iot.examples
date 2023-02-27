// **I2C**
// SCL -> D1
// SDA -> D2

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_64X48_ER_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void setup(void)
{
  u8g2.begin();
  u8g2.setPowerSave(0);
}

void loop(void)
{
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_u8glib_4_hf);
  u8g2.drawStr(0, 5, "Hello friend!!");
  u8g2.drawStr(0, 15, "0123456789");

  u8g2.sendBuffer();
  delay(2000);
}