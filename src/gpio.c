/* 
 * File:   gpio.c
 * Author: Ludo
 *
 * Created on 18 jun 2018, 13:09
 */

#include "gpio.h"
#include <pic12lf1571.h>

/*** GPIO functions ***/

/* CONFIGURE GPIOs.
 * @parzm:  None.
 * @return: None.
 */
void GPIO_init(void) {
    // PWM1 peripheral mapped on RA5.
    APFCON = 0x01; // P1SEL='1'.
    // Configure RA5 as output, RA2 and RA4 as input.
    TRISA = 0x14; // TRISA5='0', TRISA4='1' and TRISA2='1'.
    ANSELA = 0x00; // None analog pin.
    WPUA = 0x00; // None pull-up resistor.
    ODCONA = 0x00; // All pins using push-pull stage.
    SLRCONA &= 0xD0; // RA5 slew rate at maximum.
    // Enable rising edge external interrupt on RA4 (for wake-up).
    IOCAP &= 0xC0; // Reset bits 0-5.
    IOCAP |= 0x10; // IOCAP4='1'.
    IOCAN &= 0xC0; // Negative edge disabled.
    INTCON |= 0x08; // IOCIE='1'.
}

/* CHECK RAIN SENSOR.
 * @param:                  None.
 * @return sensor_state:    1 if rain detected, 0 otherwise.
 */
unsigned char GPIO_rain_detected(void) {
    unsigned char sensor_state = 0;
    if ((PORTA & 0x10) != 0) { // Check PORTA4 bit.
        sensor_state = 1;
    }
    return sensor_state;
}

/* CHECK USER BUTTON.
 * @param:                  None.
 * @return button_state:    1 if button is pressed, 0 otherwise.
 */
unsigned char GPIO_button_pressed(void) {
    unsigned char button_state = 0;
    if ((PORTA & 0x04) != 0) { // Check PORTA2 bit.
        button_state = 1;
    }
    return button_state;
}