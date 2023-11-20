/*
 * TouchSwitchButton.h - Basic switch button library
 * for touch readings.
 * Created by Halil İbrahim İvedi, November 20, 2023.
 * */
#ifndef TOUCH_SWITCH_BUTTON_H
#define TOUCH_SWITCH_BUTTON_H

#include "Arduino.h"

#define TOUCH_STATE_RELEASED 0
#define TOUCH_STATE_PRESSED 1
#define TOUCH_STATE_DEEP_PRESSED 2

class TouchSwitchButton
{
  public:
    TouchSwitchButton(
      uint8_t pin,
      uint8_t releaseAreaMax,
      uint8_t releaseAreaMin,
      uint8_t pressAreaMax,
      uint8_t pressAreaMin,
      uint8_t deepPressAreaMax,
      uint8_t deepPressAreaMin);
    uint8_t buttonPin;
    uint8_t state;
    bool updateState();
  private:
    uint8_t _releaseAreaMax;
    uint8_t _releaseAreaMin;
    uint8_t _pressAreaMax;
    uint8_t _pressAreaMin;
    uint8_t _deepPressAreaMax;
    uint8_t _deepPressAreaMin;
};

#endif

