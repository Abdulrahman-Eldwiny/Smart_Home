/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K20
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set A1 aliases
#define A1_TRIS                 TRISBbits.TRISB0
#define A1_LAT                  LATBbits.LATB0
#define A1_PORT                 PORTBbits.RB0
#define A1_WPU                  WPUBbits.WPUB0
#define A1_ANS                  ANSELHbits.ANS12
#define A1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define A1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define A1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define A1_GetValue()           PORTBbits.RB0
#define A1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define A1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define A1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define A1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define A1_SetAnalogMode()      do { ANSELHbits.ANS12 = 1; } while(0)
#define A1_SetDigitalMode()     do { ANSELHbits.ANS12 = 0; } while(0)

// get/set A2 aliases
#define A2_TRIS                 TRISBbits.TRISB1
#define A2_LAT                  LATBbits.LATB1
#define A2_PORT                 PORTBbits.RB1
#define A2_WPU                  WPUBbits.WPUB1
#define A2_ANS                  ANSELHbits.ANS10
#define A2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define A2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define A2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define A2_GetValue()           PORTBbits.RB1
#define A2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define A2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define A2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define A2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define A2_SetAnalogMode()      do { ANSELHbits.ANS10 = 1; } while(0)
#define A2_SetDigitalMode()     do { ANSELHbits.ANS10 = 0; } while(0)

// get/set A3 aliases
#define A3_TRIS                 TRISBbits.TRISB2
#define A3_LAT                  LATBbits.LATB2
#define A3_PORT                 PORTBbits.RB2
#define A3_WPU                  WPUBbits.WPUB2
#define A3_ANS                  ANSELHbits.ANS8
#define A3_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define A3_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define A3_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define A3_GetValue()           PORTBbits.RB2
#define A3_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define A3_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define A3_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define A3_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define A3_SetAnalogMode()      do { ANSELHbits.ANS8 = 1; } while(0)
#define A3_SetDigitalMode()     do { ANSELHbits.ANS8 = 0; } while(0)

// get/set A4 aliases
#define A4_TRIS                 TRISBbits.TRISB3
#define A4_LAT                  LATBbits.LATB3
#define A4_PORT                 PORTBbits.RB3
#define A4_WPU                  WPUBbits.WPUB3
#define A4_ANS                  ANSELHbits.ANS9
#define A4_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define A4_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define A4_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define A4_GetValue()           PORTBbits.RB3
#define A4_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define A4_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define A4_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define A4_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define A4_SetAnalogMode()      do { ANSELHbits.ANS9 = 1; } while(0)
#define A4_SetDigitalMode()     do { ANSELHbits.ANS9 = 0; } while(0)

// get/set B1 aliases
#define B1_TRIS                 TRISBbits.TRISB4
#define B1_LAT                  LATBbits.LATB4
#define B1_PORT                 PORTBbits.RB4
#define B1_WPU                  WPUBbits.WPUB4
#define B1_ANS                  ANSELHbits.ANS11
#define B1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define B1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define B1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define B1_GetValue()           PORTBbits.RB4
#define B1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define B1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define B1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define B1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define B1_SetAnalogMode()      do { ANSELHbits.ANS11 = 1; } while(0)
#define B1_SetDigitalMode()     do { ANSELHbits.ANS11 = 0; } while(0)

// get/set B2 aliases
#define B2_TRIS                 TRISBbits.TRISB5
#define B2_LAT                  LATBbits.LATB5
#define B2_PORT                 PORTBbits.RB5
#define B2_WPU                  WPUBbits.WPUB5
#define B2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define B2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define B2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define B2_GetValue()           PORTBbits.RB5
#define B2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define B2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define B2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define B2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)

// get/set B3 aliases
#define B3_TRIS                 TRISBbits.TRISB6
#define B3_LAT                  LATBbits.LATB6
#define B3_PORT                 PORTBbits.RB6
#define B3_WPU                  WPUBbits.WPUB6
#define B3_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define B3_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define B3_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define B3_GetValue()           PORTBbits.RB6
#define B3_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define B3_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define B3_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define B3_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set B4 aliases
#define B4_TRIS                 TRISBbits.TRISB7
#define B4_LAT                  LATBbits.LATB7
#define B4_PORT                 PORTBbits.RB7
#define B4_WPU                  WPUBbits.WPUB7
#define B4_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define B4_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define B4_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define B4_GetValue()           PORTBbits.RB7
#define B4_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define B4_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define B4_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define B4_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS                 TRISCbits.TRISC0
#define RS_LAT                  LATCbits.LATC0
#define RS_PORT                 PORTCbits.RC0
#define RS_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RS_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RS_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RS_GetValue()           PORTCbits.RC0
#define RS_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set RW aliases
#define RW_TRIS                 TRISCbits.TRISC1
#define RW_LAT                  LATCbits.LATC1
#define RW_PORT                 PORTCbits.RC1
#define RW_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RW_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RW_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RW_GetValue()           PORTCbits.RC1
#define RW_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RW_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set E aliases
#define E_TRIS                 TRISCbits.TRISC2
#define E_LAT                  LATCbits.LATC2
#define E_PORT                 PORTCbits.RC2
#define E_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define E_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define E_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define E_GetValue()           PORTCbits.RC2
#define E_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define E_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set IO_RD0 aliases
#define IO_RD0_TRIS                 TRISDbits.TRISD0
#define IO_RD0_LAT                  LATDbits.LATD0
#define IO_RD0_PORT                 PORTDbits.RD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)

// get/set D1 aliases
#define D1_TRIS                 TRISDbits.TRISD1
#define D1_LAT                  LATDbits.LATD1
#define D1_PORT                 PORTDbits.RD1
#define D1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define D1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define D1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define D1_GetValue()           PORTDbits.RD1
#define D1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define D1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)

// get/set D2 aliases
#define D2_TRIS                 TRISDbits.TRISD2
#define D2_LAT                  LATDbits.LATD2
#define D2_PORT                 PORTDbits.RD2
#define D2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define D2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define D2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define D2_GetValue()           PORTDbits.RD2
#define D2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define D2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)

// get/set D3 aliases
#define D3_TRIS                 TRISDbits.TRISD3
#define D3_LAT                  LATDbits.LATD3
#define D3_PORT                 PORTDbits.RD3
#define D3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define D3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define D3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define D3_GetValue()           PORTDbits.RD3
#define D3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define D3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISDbits.TRISD4
#define D4_LAT                  LATDbits.LATD4
#define D4_PORT                 PORTDbits.RD4
#define D4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define D4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define D4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define D4_GetValue()           PORTDbits.RD4
#define D4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS                 TRISDbits.TRISD5
#define D5_LAT                  LATDbits.LATD5
#define D5_PORT                 PORTDbits.RD5
#define D5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define D5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define D5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define D5_GetValue()           PORTDbits.RD5
#define D5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS                 TRISDbits.TRISD6
#define D6_LAT                  LATDbits.LATD6
#define D6_PORT                 PORTDbits.RD6
#define D6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define D6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define D6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define D6_GetValue()           PORTDbits.RD6
#define D6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISDbits.TRISD7
#define D7_LAT                  LATDbits.LATD7
#define D7_PORT                 PORTDbits.RD7
#define D7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define D7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define D7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define D7_GetValue()           PORTDbits.RD7
#define D7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);
void DIO_write_port(uint8_t portname,uint8_t portvalue);


#endif // PIN_MANAGER_H
/**
 End of File
*/