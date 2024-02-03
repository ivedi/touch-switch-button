/*
 * TouchSwitchButton.h - Basic switch button library
 * for touch readings.
 * Created by Halil İbrahim İvedi, November 20, 2023.
 * */
#ifndef TOUCH_SWITCH_BUTTON_H
#define TOUCH_SWITCH_BUTTON_H

#include "Arduino.h"

#define TOUCH_STATE_RELEASED 1
#define TOUCH_STATE_PRESSED 2
#define TOUCH_STATE_DEEP_PRESSED 4

class TouchSwitchButton
{
  public:
    TouchSwitchButton(
      uint8_t pin,
      uint8_t releaseMin,
      uint8_t pressMin);
    uint8_t buttonPin;
    uint8_t state;
    uint16_t touchValue;
    bool updateState();
  private:
    uint8_t _releaseMin;
    uint8_t _pressMin;
};

#endif

