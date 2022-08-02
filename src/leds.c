#include "leds.h"

uint16_t * puerto;

void LedsCreate(uint16_t * address)
{
    puerto = address;
    *puerto = 0;
}

void LedsSingleTurnOn(uint8_t led)
{
    *puerto = 4;
}