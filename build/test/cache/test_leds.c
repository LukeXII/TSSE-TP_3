#include "src/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"














uint16_t leds_virtuales;



void setUp(void)

{



    LedsCreate(&leds_virtuales);

}





void test_todos_los_leds_inician_apagados(void)

{

    uint16_t leds_virtuales = 0xFFFF;

    LedsCreate(&leds_virtuales);

    UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_un_led_individual(void)

{

    LedsSingleTurnOn(3);

    UnityAssertEqualNumber((UNITY_INT)((1 << 2)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}





void test_apagar_un_led_individual(void)

{

    LedsSingleTurnOn(3);

    LedsSingleTurnOff(3);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_y_apagar_varios_leds(void)

{

    LedsSingleTurnOn(3);

    LedsSingleTurnOn(7);

    LedsSingleTurnOff(7);

    UnityAssertEqualNumber((UNITY_INT)((1 << 2)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

}
