/*
 * TouchSwitchButton.cpp - Basic switch button library
 * for touch readings.
 * Created by Halil İbrahim İvedi, November 20, 2023.
 * */

#include "Arduino.h"
#include "TouchSwitchButton.h"

TouchSwitchButton::TouchSwitchButton(
    uint8_t pin,
    uint8_t releaseAreaMax,
    uint8_t releaseAreaMin,
    uint8_t pressAreaMax,
    uint8_t pressAreaMin,
    uint8_t deepPressAreaMax,
    uint8_t deepPressAreaMin) {
  buttonPin = pin;

  _releaseAreaMax = releaseAreaMax;
  _releaseAreaMin = releaseAreaMin;
  _pressAreaMax = pressAreaMax;
  _pressAreaMin = pressAreaMin;
  _deepPressAreaMax = deepPressAreaMax;
  _deepPressAreaMin = deepPressAreaMin;

  state = TOUCH_STATE_RELEASED;
}

bool TouchSwitchButton::updateState() {
  uint16_t touchValue = touchRead(buttonPin);
  if (state != TOUCH_STATE_RELEASED && touchValue >= _releaseAreaMin && touchValue < _releaseAreaMax) {
    state = TOUCH_STATE_RELEASED;
    return true;
  }
  if (state == TOUCH_STATE_RELEASED && touchValue >= _pressAreaMin && touchValue < _pressAreaMax) {
    state = TOUCH_STATE_PRESSED;
    return true;
  }
  if (state == TOUCH_STATE_PRESSED && touchValue >= _deepPressAreaMin && touchValue < _deepPressAreaMax) {
    state = TOUCH_STATE_DEEP_PRESSED;
    return true;
  }
  return false;
}
