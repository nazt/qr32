#include <Arduino.h>
#include "defs.h"
#include <CMMC_Legend.h>
#include <WiFi.h>
#include <rom/rtc.h>

#include "modules/ConfigModule.h"
#include <HardwareSerial.h>
#include "tasks/lcd/CMMC_LCD.h"
static CMMC_LCD *lcd;
// #include <CMMC_DustSensor.h>
// #include <CMMC_RTC.h>
SCREEN_PAGE xpage = LCD_RUN;

CMMC_Legend *os;
HardwareSerial mySerial(0);


void hook_init_ap(char* name, IPAddress ip) {
  mySerial.println("----------- hook_init_ap -----------");
  mySerial.println(name);
  mySerial.println(ip);
  mySerial.println("/----------- hook_init_ap -----------");
  xpage = LCD_CONFIG;
}

void hook_button_pressed() {
  mySerial.println("[user] hook_button_pressed");
  xpage = LCD_BUTTON_PRESSED;
}

void hook_button_released() {
  mySerial.println("[user] hook_button_released");
  xpage = LCD_RUN;
}

void hook_button_long_pressed() {
  mySerial.println("[user] hook_button_long_pressed");
  xpage = LCD_BUTTON_LONG_PRESSED;
}


#include "tasks/app.hpp"

void setup()
{
  WiFi.disconnect();
  WiFi.mode(WIFI_OFF);
  mySerial.begin(115200);
  String taskMessage = "[main] Task running on core ";
  taskMessage = taskMessage + xPortGetCoreID();
  mySerial.println(taskMessage);
  // delay(200);

  os = new CMMC_Legend(&mySerial);

  static os_config_t config = {
    .BLINKER_PIN = 21,
    .BUTTON_MODE_PIN = 0,
    .SWITCH_PIN_MODE = INPUT_PULLUP,
    .SWITCH_PRESSED_LOGIC = LOW,
    .delay_after_init_ms = 200,
    .hook_init_ap = hook_init_ap,
    .hook_button_pressed =  hook_button_pressed,
    .hook_button_long_pressed = hook_button_long_pressed,
    .hook_button_released = hook_button_released,
  };

  // os->addModule(new ConfigModule());

  tasks_init();
  
  os->setup(&config);
  //
  mySerial.printf("free heap = %lu\r\n", ESP.getFreeHeap());
  mySerial.printf("free heap = %lu\r\n", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));

  // dustSensor = new CMMC_DustSensor(&Serial1);
  // modules[0] = dustSensor;
  // modules[1] = new CMMC_GPS(&Serial1);
  // lcd = new CMMC_LCD();
  // lcd->setup()
}

// extern struct shared_pool pool;

uint32_t prev = 0;
void loop()
{
  os->run();
  // String taskMessage = "[main] Task running on core ";
  // taskMessage = taskMessage + xPortGetCoreID();
  // lcd->pm2_5 = pool.pm2_5;
  // lcd->pm10 = pool.pm10;
  // // mySerial.println(taskMessage);
  if ( (millis() - prev) > 1*100L) {
    // mySerial.println(taskMessage);
  //   // lcd->pm10 = millis()/1000;
  //   prev = millis();
  //   lcd->loop();
  }
}
