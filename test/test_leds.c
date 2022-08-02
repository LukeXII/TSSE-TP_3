#include "unity.h"
#include "leds.h"

/**

Prender un LED individual
 * 
 */

// Con la inicializacion todos los LEDs quedan apagados
void test_todos_los_leds_inician_apagados(void)
{
    uint16_t leds_virtuales = 0xFFFF;
    LedsCreate(&leds_virtuales);
    TEST_ASSERT_EQUAL(0x0000, leds_virtuales);
}

// Prender un LED individual
void test_prender_un_led_individual(void)
{
    uint16_t leds_virtuales;
    LedsCreate(&leds_virtuales);
    LedsSingleTurnOn(3);
    TEST_ASSERT_EQUAL(1 << 2, leds_virtuales);
}