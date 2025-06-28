#include <Adafruit_HDC302x.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Fonts/Font7x5Aurebesh.h>

#define OLED_W 128
#define OLED_H 64

#define OLED_R -1

/*
 * this might be different based on your specific
 * i2c display, different vendors tend to use
 * different addresses
 */
#define OLED_A 0x3C

Adafruit_HDC302x hdc = Adafruit_HDC302x();

Adafruit_SSD1306 display(OLED_W, OLED_H, &Wire1, OLED_R);

void setup() {
  delay(1000);
  Serial.begin(115200);

  if (!hdc.begin(0x44, &Wire1)) {
    Serial.println(F("HDC3022 wasn't found."));
    Serial.println(F("you might need to use &Wire1 for Stemma QT/QWIIC."));
    for (;;);
  }

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_A)) {
    Serial.println(F("SSD1306 allocation failed."));
    for (;;);
  }
}

void loop() {
  double temp = 0.0;
  double RH = 0.0;
  hdc.readTemperatureHumidityOnDemand(temp, RH, TRIGGERMODE_LP0);
  display.clearDisplay();
  display.setFont(&Font7x5Aurebesh);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);
  display.setCursor(0, 6);
  display.println("Fruit Spirit \"XIMBI\"");
  display.setCursor(0, 22);
  display.setTextSize(2);
  display.print(temp, 0);
  display.println(" deg C");
  display.print(RH, 0);
  display.println("% RH");
  display.display();
}
