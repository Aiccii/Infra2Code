#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#define BUZZER_H

#define BUZZER_PIN PD3
#define BUZZER_DDR DDRD
#define BUZZER_PORT PORTD

#define C5 523.250
#define D5 587.330
#define E5 659.250
#define F5 698.460
#define G5 783.990
#define A5 880.00
#define B5 987.770
#define C6 1046.500
#define DURATION 150


void enableBuzzer();
void disableBuzzer();
void playTone(float frequency, uint32_t duration);
void playMusic(float *frequencies, uint32_t *durations, uint8_t count);