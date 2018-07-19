/* 
 * File:   main.c
 * Author: Ludovic
 *
 * Created on 18 juin 2018, 12:28
 */

#include "clock.h"
#include "config.h"
#include "gpio.h"
#include "interrupt.h"
#include <pic12lf1571.h>
#include "pwm.h"
#include "timer.h"
#include <xc.h>

/*** Global macros ***/

// Alarm tonality toggle period expressed in tens of milliseconds.
#define TONALITY_TOGGLE_PERIOD  50
// Tonalities frequency in Hz.
#define TONALITY1_FREQ_HZ       1000
#define TONALITY2_FREQ_HZ       2000
// Alarm time-out expressed in tens of milliseconds.
#define ALARM_TIMEOUT           6000

/*** Main state machine ***/

typedef enum SPRD_State {
    SPRD_STATE_SLEEP,
    SPRD_STATE_TONALITY_1,
    SPRD_STATE_TONALITY_2
} SPRD_State;

/*** Global variables ***/

volatile unsigned int tens_milliseconds = 0;

/* MAIN FUNCTION.
 * @param:  None.
 * @return: None.
 */
int main(void) {
    
    // Init peripherals.
    Clock_Init();
    GPIO_Init();
    TIMER2_Init();
    PWM1_Init();
    Interrupt_Init();
    
    // Local variables.
    SPRD_State sprd_state = SPRD_STATE_SLEEP;
    unsigned int alarm_start_time = 0;
    unsigned int tonality_toggle_time = 0;
    
    // Main loop.
    while (1) {
        switch (sprd_state) {
        case SPRD_STATE_SLEEP:
            // Disable PWM and timer.
            PWM1_Stop();
            TIMER2_Stop();
            // Enter sleep mode.
            SLEEP();
            // Wake-up.
            if (GPIO_RainDetected() == 1) {
                // Update state.
                sprd_state = SPRD_STATE_TONALITY_1;
                PWM1_SetFrequency(TONALITY1_FREQ_HZ);
                PWM1_Start();
                // Reset timers.
                alarm_start_time = tens_milliseconds;
                tonality_toggle_time = tens_milliseconds;
                TIMER2_Start();
            }
            break;
        case SPRD_STATE_TONALITY_1:
            // Update state.
            if ((tens_milliseconds > (alarm_start_time + ALARM_TIMEOUT)) || (GPIO_ButtonPressed())) {
                // Come-back to sleep mode.
                sprd_state = SPRD_STATE_SLEEP;
            }
            else {
                if (tens_milliseconds > (tonality_toggle_time + TONALITY_TOGGLE_PERIOD)) {
                    // Switch to tonality 2.
                    sprd_state = SPRD_STATE_TONALITY_2;
                    PWM1_SetFrequency(TONALITY2_FREQ_HZ);
                    // Reset timer.
                    tonality_toggle_time = tens_milliseconds;
                }
            }
            break;
        case SPRD_STATE_TONALITY_2:
            // Update state.
            if ((tens_milliseconds > (alarm_start_time + ALARM_TIMEOUT)) || (GPIO_ButtonPressed())) {
                // Come-back to sleep mode.
                sprd_state = SPRD_STATE_SLEEP;
            }
            else {
                if (tens_milliseconds > (tonality_toggle_time + TONALITY_TOGGLE_PERIOD)) {
                    // Switch to tonality 1.
                    sprd_state = SPRD_STATE_TONALITY_1;
                    PWM1_SetFrequency(TONALITY1_FREQ_HZ);
                    // Reset timer.
                    tonality_toggle_time = tens_milliseconds;
                }
            }
            break;
        }
    }
    return 0;
}

/* HANDLER FOR ALL INTERRUPTS.
 * @param :     None.
 * @return :    None.
 */
void interrupt ISR(void) {
    
    // TIMER2 interrupt.
    if ((PIR1 & 0x02) != 0) { // TMR2IF='1'.
        // Clear flag.
        PIR1 &= 0xFD; // TMR2IF='0'.
        // Increment counter of 10*milliseconds.
        tens_milliseconds++;
        // Toggle RA5.
        //PORTA ^= 0x20;
    }
    
    // Interrupt on change.
    if ((IOCAF & 0x3F) != 0) {
         // Clear all external interrupt flags.
        IOCAF &= 0xC0;
    }
}