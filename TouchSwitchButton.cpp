/*
 * TouchSwitchButton.cpp - Basic switch button library
 * for touch readings.
 * Created by Halil İbrahim İvedi, November 20, 2023.
 * */

#include "Arduino.h"
#include "TouchSwitchButton.h"

TouchSwitchButton::TouchSwitchButton(
    uint8_t pin,
    uint8_t releaseMin,
    uint8_t pressMin) {
  buttonPin = pin;

  _releaseMin = releaseMin;
  _pressMin = pressMin;

  state = TOUCH_STATE_RELEASED;
}

bool TouchSwitchButton::updateState() {
  touchValue = touchRead(buttonPin);
  if (state != TOUCH_STATE_RELEASED && touchValue >= _releaseMin) {
    state = TOUCH_STATE_RELEASED;
    return true;
  }
  if (state == TOUCH_STATE_RELEASED && touchValue >= _pressMin) {
    state = TOUCH_STATE_PRESSED;
    return true;
  }
  if (state != TOUCH_STATE_DEEP_PRESSED && touchValue < _pressMin) {
    state = TOUCH_STATE_DEEP_PRESSED;
    return true;
  }
  return false;
}
