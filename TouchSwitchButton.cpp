/*
 * TouchSwitchButton.cpp - Basic switch button library
 * for touch readings.
 * Created by Halil İbrahim İvedi, November 20, 2023.
 * */

#include "Arduino.h"
#include "TouchSwitchButton.h"

TouchSwitchButton::TouchSwitchButton(
    uint8_t pin,
    uint8_t releasePressBorder,
    uint8_t pressDeepPressBorder,
    uint8_t noiseCancelLevel) {
  buttonPin = pin;

  _releasePressBorder = releasePressBorder;
  _pressDeepPressBorder = pressDeepPressBorder;

  _noiseCancelLevel = noiseCancelLevel;
  _signals = (uint16_t*)malloc(sizeof(uint16_t)*_noiseCancelLevel);
  if (_noiseCancelLevel > 1) {
    for (byte i = 0; i < _noiseCancelLevel; i++) {
      _signals[i] = _releasePressBorder;
    }
  }
  _signalIndex = 0;

  state = TOUCH_STATE_RELEASED;
}

bool TouchSwitchButton::updateState() {
  // touchValue = touchRead(buttonPin);
  touchValue = _cancelNoise(touchRead(buttonPin));
  if (state != TOUCH_STATE_RELEASED && touchValue >= _releasePressBorder) {
    state = TOUCH_STATE_RELEASED;
    return true;
  }
  if (state == TOUCH_STATE_RELEASED && touchValue < _releasePressBorder && touchValue >= _pressDeepPressBorder) {
    state = TOUCH_STATE_PRESSED;
    return true;
  }
  if (state != TOUCH_STATE_DEEP_PRESSED && touchValue < _pressDeepPressBorder) {
    state = TOUCH_STATE_DEEP_PRESSED;
    return true;
  }
  return false;
}

uint16_t TouchSwitchButton::_cancelNoise(uint16_t readValue) {
  if (_noiseCancelLevel <= 1) {
    return readValue;
  }

  _signals[_signalIndex] = readValue;
  _signalIndex = (_signalIndex + 1) % _noiseCancelLevel;
  uint16_t signalSum = 0;
  for (byte i = 0; i < _noiseCancelLevel; i++) {
    signalSum += _signals[i];
  }
  return signalSum / _noiseCancelLevel;
}
