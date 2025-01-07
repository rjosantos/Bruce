#ifndef __LED_CONTROL_H__
#define __LED_CONTROL_H__
#include <globals.h>
#ifdef HAS_RGB_LED
#include <Arduino.h>
#include <FastLED.h>

CRGB hsvToRgb(uint16_t h, uint8_t s, uint8_t v);
void setColor(CRGB c);
void setBrightness(int b);
void ledColorConfig();
void ledBrightnessConfig();
void ledBlink(int c, int d);
void ledBlink(int c);
void ledBlink();

#define LED_RED 1
#define LED_GREEN 2
#define LED_BLUE 3

#define LED_BLINK_SLOW 500
#define LED_BLINK_FAST 100
#define LED_BLINK_VERY_FAST 50

#endif
#endif