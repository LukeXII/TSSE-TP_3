#include "leds.h"

#define LEDS_OFFSET     1
#define FIRST_BIT_ON    1
#define LEDS_ALL_OFF    0

static uint16_t * puerto;

static uint16_t LedToMask(uint8_t led)
{
    return (1 << (led - 1));
}

void LedsCreate(uint16_t * address)
{
    puerto = address;
    *puerto = 0;
}

void LedsSingleTurnOn(uint8_t led)
{
    *puerto |= LedToMask(led);
}

void LedsSingleTurnOff(uint8_t led)
{
    *puerto &= ~LedToMask(led);
}