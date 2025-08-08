// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_HDC302x.h>
#include <SPI.h>
#include "RTClib.h"

#define DC     8
#define CS     9
#define SCLK  10
#define PICO  11
#define RST   12

Adafruit_ST7735 tft = Adafruit_ST7735(CS, DC, PICO, SCLK, RST);
Adafruit_HDC302x hdc = Adafruit_HDC302x();

RTC_DS3231 rtc;

char daysOfTheWeek[7][10] = {"Sunday   ", "Monday   ", "Tuesday  ", "Wednesday", "Thursday ", "Friday   ", "Saturday "};

void setup () {
  Wire.setSDA(4);
  Wire.setSCL(5);
  if (!rtc.begin() || !hdc.begin(0x44, &Wire)) {
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(DateTime(F(__DATE__), F(__TIME__)).unixtime() + 12));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  tft.initR(INITR_MINI160x80_PLUGIN);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
}

void loop () {
    DateTime now = rtc.now();
    float t3231 = rtc.getTemperature();
    double t3022;
    double h3022;
    hdc.readTemperatureHumidityOnDemand(t3022, h3022, TRIGGERMODE_LP0);
    double disc = abs(t3231 - t3022) / min(t3231, t3022) * 100;
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.setCursor(0,0);
    tft.setTextSize(1);
    tft.println(daysOfTheWeek[now.dayOfTheWeek()]);
    tft.print(now.year(), DEC);
    tft.print('-');
    tft.print(now.month(), DEC);
    tft.print('-');
    tft.print(now.day(), DEC);
    tft.println("   ");
    tft.print(now.hour(), DEC);
    tft.print(':');
    tft.print(now.minute(), DEC);
    tft.print(':');
    tft.print(now.second(), DEC);
    tft.println("   ");
    tft.print("DS3231 temp: ");
    tft.print(t3231);
    tft.println(" C   ");
    tft.print("HDC3022 temp: ");
    tft.print(t3022);
    tft.println(" C  ");
    tft.print(disc);
    tft.println("% discrepancy   ");
    tft.print("RH: ");
    tft.print(h3022);
    tft.print("%   ");
    delay(10);
}
