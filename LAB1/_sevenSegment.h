#ifndef _SEVENSEGMENT_H
#define _SEVENSEGMENT_H

#include <Arduino.h>

class SevenSegment {
public:
  SevenSegment(const byte segPins[7]);

  void begin();
  void showDigit(byte d);
  void setCommonAnode(bool enabled);

private:
  byte _segPins[7];
  bool _commonAnode = false;
  static const byte _digitMap[10][7];
};

class Buttons {
public:
  Buttons(byte b1, byte b2, byte b3, byte b4, byte b5);

  void begin();

  bool bt1Pressed();
  bool bt2Pressed();
  bool bt3Pressed();
  bool bt4Pressed();
  bool bt5Pressed();

private:
  byte _b1, _b2, _b3, _b4, _b5;
  bool _prev1, _prev2, _prev3, _prev4, _prev5;

  bool pressedNow(byte pin, bool &prevState);
};

#endif