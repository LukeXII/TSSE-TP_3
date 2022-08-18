#include "leds.h"

#define LEDS_OFFSET     1
#define FIRST_BIT_ON    1
#define LEDS_ALL_OFF    0
#define LEDS_ALL_ON     0xFFFF
#define LED_ON          1
#define LED_OFF         0

static uint16_t * puerto;

static uint16_t LedToMask(uint8_t led)
{
    return (FIRST_BIT_ON << (led - LEDS_OFFSET));
}

void LedsCreate(uint16_t * address)
{
    puerto = address;
    *puerto = LEDS_ALL_OFF;
}

void LedsSingleTurnOn(uint8_t led)
{
    *puerto |= LedToMask(led);
}

void LedsSingleTurnOff(uint8_t led)
{
    *puerto &= ~LedToMask(led);
}

void LedsAllOn(void)
{
    *puerto |= LEDS_ALL_ON;
}

void LedsAllOff(void)
{
    *puerto &= LEDS_ALL_OFF;
}

uint8_t LedsGetState(uint8_t led)
{
    return (*puerto & LedToMask(led)) > 0 ? LED_ON : LED_OFF;
}