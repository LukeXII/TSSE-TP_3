#include "unity.h"
#include "leds.h"

uint16_t leds_virtuales;

void setUp(void)
{

    LedsCreate(&leds_virtuales);
}

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
    LedsSingleTurnOn(3);
    TEST_ASSERT_EQUAL(1 << 2, leds_virtuales);
}

// Apagar un LED individual
void test_apagar_un_led_individual(void)
{
    LedsSingleTurnOn(3);
    LedsSingleTurnOff(3);
    TEST_ASSERT_EQUAL(0, leds_virtuales);
}

// Prender y apagar multiples LEDs
void test_prender_y_apagar_varios_leds(void)
{
    LedsSingleTurnOn(3);
    LedsSingleTurnOn(7);
    LedsSingleTurnOff(7);
    TEST_ASSERT_EQUAL(1 << 2, leds_virtuales);
}