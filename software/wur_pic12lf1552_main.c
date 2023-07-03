/*
 * File:   main.c
 * Author: timschroder
 *
 * Created on June 13, 2023, 6:03 PM
 */


#include <xc.h>

// Configuration bits
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

#define _XTAL_FREQ 16000000  // 16 MHz Internal Oscillator

void __interrupt() isr(void) {
    if (INTCONbits.INTF) { // Interrupt on Preamble Channel RA2
        IOCANbits.IOCAN0 = 1; // Activate int on RA0
        INTCONbits.INTF = 0; // Reset the interrupt flag
    }
    else if (IOCAFbits.IOCAF0) {
        if (IOCANbits.IOCAN0) {
            TMR0 = 128; // Interrupt Falling on Data Channel RA edge
            INTCONbits.TMR0IF = 0;
            INTCONbits.TMR0IE = 1;

            // LED1 = 0;
            // Clear Timer1 interrupt flag
            // ENABLE TIMER0 INTERRUPT

            IOCANbits.IOCAN0 = 0; // Deactivate int on RA0 on falling edge
            IOCAPbits.IOCAP0 = 1; // Activate int on RA0 on rising edge
            timerCycles = 0;
        }
    }
    else if (IOCAPbits.IOCAP0) {
        if (timerCycles == address) {
            // CORRECT ADDRESS
            // WAKE MCU
        }
        INTCONbits.TMR0IE = 0; // DISABLE TIMER0
        IOCAPbits.IOCAP0 = 0; // Deactivate INT INTERRUPT on RA0
    }
    IOCAFbits.IOCAF0 = 0; // Reset IOC Interrupt flag
    else if (INTCONbits.TMR0IF) {
        // Timer1 overflow interrupt
        timerCycles++; // count numbers of timer overflows
        INTCONbits.TMR0IF = 0; // Clear Timer1 interrupt flag
    }
}

void main(void)
{
    OSCCON = 0b01111000;  // Set internal oscillator to 4 MHz
    
    TRISA2 = 1;  // Set RA2 as input for the interrupt signal
    TRISA3 = 0;  // Set RA3 as output for the LED
    
    OPTION_REGbits.INTEDG = 0;  // Interrupt on falling edge of RA2
    INTCONbits.INTE = 1;       // Enable external interrupt (INT)
    INTCONbits.GIE = 1;        // Enable global interrupts
    
    while (1) {
        // Main program loop
        SLEEP();
    }
}
