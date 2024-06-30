#include <stdint.h>

void enableOneLed(int ledNumber);
void enableMultipleLeds(uint8_t leds);
void enableAllLeds(void);
void disableAllLeds(void);

void lightUpOneLed(int ledNumber);
void lightUpMultipleLeds(uint8_t leds);
void lightUpAllLeds(void);

void lightDownOneLed(int ledNumber);
void lightDownMultipleLeds(uint8_t leds);
void lightDownAllLeds(void);

void lightToggleOneLed(int ledNumber);

void dimLed(int ledNumber, int percentage, int duration);
void fadeInLed(int ledNumber, int duration);
void fadeOutLed(int ledNumber, int duration);
void randomLEDDance(int duration);
void countdownPattern(void);
void blinkLed(void);

