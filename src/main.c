/* 
 * File:   main.c
 * Author: Ludo
 *
 * Created on 18 jun. 2018, 12:28
 */

#include "clock.h"
#include "config.h"
#include "gpio.h"
#include "interrupt.h"
#include <pic12lf1571.h>
#include "pwm.h"
#include "timer.h"
#include <xc.h>

/*** MAIN macros ***/

// Alarm tonality toggle period expressed in tenth of seconds.
#define TONALITY_TOGGLE_PERIOD  5
// Tonalities frequency in Hz.
#define TONALITY1_FREQ_HZ       1700
#define TONALITY2_FREQ_HZ       2000
// Alarm time-out expressed in tenth of seconds.
#define ALARM_TIMEOUT           200

/*** MAIN structures ***/

/*******************************************************************/
typedef enum SPRD_state_t {
    SPRD_STATE_SLEEP,
    SPRD_STATE_TONALITY_1,
    SPRD_STATE_TONALITY_2
} SPRD_state_t;

/*** MAIN global variables ***/

volatile unsigned int tenth_seconds = 0;

/*** MAIN functions ***/

/*******************************************************************/
int main(void) {
    // Local variables.
    SPRD_state_t sprd_state = SPRD_STATE_SLEEP;
    unsigned int alarm_start_time = 0;
    unsigned int tonality_toggle_time = 0;
    // Init peripherals.
    CLOCK_init();
    GPIO_init();
    TIMER2_init();
    PWM1_init();
    INTERRUPT_init();
    // Main loop.
    while (1) {
        switch (sprd_state) {
        case SPRD_STATE_SLEEP:
            // Disable PWM and timer.
            PWM1_stop();
            TIMER2_stop();
            // Enter sleep mode.
            SLEEP();
            // Wake-up.
            if (GPIO_rain_detected() == 1) {
                // Update state.
                sprd_state = SPRD_STATE_TONALITY_1;
                PWM1_set_frequency(TONALITY1_FREQ_HZ);
                // Reset timers.
                alarm_start_time = tenth_seconds;
                tonality_toggle_time = tenth_seconds;
                PWM1_start();
                TIMER2_start();
            }
            break;
        case SPRD_STATE_TONALITY_1:
            // Update state.
            if ((tenth_seconds > (alarm_start_time + ALARM_TIMEOUT)) || (GPIO_button_pressed())) {
                // Come-back to sleep mode.
                sprd_state = SPRD_STATE_SLEEP;
            }
            else {
                if (tenth_seconds > (tonality_toggle_time + TONALITY_TOGGLE_PERIOD)) {
                    // Switch to tonality 2.
                    sprd_state = SPRD_STATE_TONALITY_2;
                    PWM1_set_frequency(TONALITY2_FREQ_HZ);
                    // Reset timer.
                    tonality_toggle_time = tenth_seconds;
                }
            }
            break;
        case SPRD_STATE_TONALITY_2:
            // Update state.
            if ((tenth_seconds > (alarm_start_time + ALARM_TIMEOUT)) || (GPIO_button_pressed())) {
                // Come-back to sleep mode.
                sprd_state = SPRD_STATE_SLEEP;
            }
            else {
                if (tenth_seconds > (tonality_toggle_time + TONALITY_TOGGLE_PERIOD)) {
                    // Switch to tonality 1.
                    sprd_state = SPRD_STATE_TONALITY_1;
                    PWM1_set_frequency(TONALITY1_FREQ_HZ);
                    // Reset timer.
                    tonality_toggle_time = tenth_seconds;
                }
            }
            break;
        }
    }
    return 0;
}

/*******************************************************************/
void interrupt ISR(void) {
    // TIMER2 interrupt.
    if ((PIR1 & 0x02) != 0) { // TMR2IF='1'.
        // Clear flag.
        PIR1 &= 0xFD; // TMR2IF='0'.
        // Increment counter of tenth milliseconds.
        tenth_seconds++;
        // Toggle RA5.
        //PORTA ^= 0x20;
    }
    // Interrupt on change.
    if ((IOCAF & 0x3F) != 0) {
         // Clear all external interrupt flags.
        IOCAF &= 0xC0;
    }
}