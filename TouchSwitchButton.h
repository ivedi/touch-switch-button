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

#define NOISE_CANCEL_LEVEL_MAX 5

class TouchSwitchButton
{
  public:
    TouchSwitchButton(
      uint8_t pin,
      uint8_t releasePressBorder,
      uint8_t pressDeepPressBorder,
      uint8_t noiseCancelLevel = 0);
    uint8_t buttonPin;
    uint8_t state;
    uint16_t touchValue;
    bool updateState();
  private:
    uint8_t _releasePressBorder;
    uint8_t _pressDeepPressBorder;
    uint8_t _noiseCancelLevel;
    // uint16_t _signals[NOISE_CANCEL_LEVEL_MAX];
    uint16_t *_signals;
    byte _signalIndex;
    uint16_t _cancelNoise(uint16_t readValue);
};

#endif

