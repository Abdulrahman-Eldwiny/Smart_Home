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

// get/set Z aliases
#define Z_TRIS                 TRISAbits.TRISA2
#define Z_LAT                  LATAbits.LATA2
#define Z_PORT                 PORTAbits.RA2
#define Z_ANS                  ANSELbits.ANS2
#define Z_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define Z_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define Z_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define Z_GetValue()           PORTAbits.RA2
#define Z_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define Z_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define Z_SetAnalogMode()      do { ANSELbits.ANS2 = 1; } while(0)
#define Z_SetDigitalMode()     do { ANSELbits.ANS2 = 0; } while(0)

// get/set Tv_Switch aliases
#define Tv_Switch_TRIS                 TRISAbits.TRISA4
#define Tv_Switch_LAT                  LATAbits.LATA4
#define Tv_Switch_PORT                 PORTAbits.RA4
#define Tv_Switch_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define Tv_Switch_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define Tv_Switch_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define Tv_Switch_GetValue()           PORTAbits.RA4
#define Tv_Switch_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define Tv_Switch_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set Radio_Switch aliases
#define Radio_Switch_TRIS                 TRISAbits.TRISA5
#define Radio_Switch_LAT                  LATAbits.LATA5
#define Radio_Switch_PORT                 PORTAbits.RA5
#define Radio_Switch_ANS                  ANSELbits.ANS4
#define Radio_Switch_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define Radio_Switch_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define Radio_Switch_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define Radio_Switch_GetValue()           PORTAbits.RA5
#define Radio_Switch_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define Radio_Switch_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define Radio_Switch_SetAnalogMode()      do { ANSELbits.ANS4 = 1; } while(0)
#define Radio_Switch_SetDigitalMode()     do { ANSELbits.ANS4 = 0; } while(0)

// get/set Motor1_Pin0 aliases
#define Motor1_Pin0_TRIS                 TRISBbits.TRISB0
#define Motor1_Pin0_LAT                  LATBbits.LATB0
#define Motor1_Pin0_PORT                 PORTBbits.RB0
#define Motor1_Pin0_WPU                  WPUBbits.WPUB0
#define Motor1_Pin0_ANS                  ANSELHbits.ANS12
#define Motor1_Pin0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define Motor1_Pin0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define Motor1_Pin0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define Motor1_Pin0_GetValue()           PORTBbits.RB0
#define Motor1_Pin0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define Motor1_Pin0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define Motor1_Pin0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define Motor1_Pin0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define Motor1_Pin0_SetAnalogMode()      do { ANSELHbits.ANS12 = 1; } while(0)
#define Motor1_Pin0_SetDigitalMode()     do { ANSELHbits.ANS12 = 0; } while(0)

// get/set Motor1_Pin1 aliases
#define Motor1_Pin1_TRIS                 TRISBbits.TRISB1
#define Motor1_Pin1_LAT                  LATBbits.LATB1
#define Motor1_Pin1_PORT                 PORTBbits.RB1
#define Motor1_Pin1_WPU                  WPUBbits.WPUB1
#define Motor1_Pin1_ANS                  ANSELHbits.ANS10
#define Motor1_Pin1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define Motor1_Pin1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define Motor1_Pin1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define Motor1_Pin1_GetValue()           PORTBbits.RB1
#define Motor1_Pin1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define Motor1_Pin1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define Motor1_Pin1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define Motor1_Pin1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define Motor1_Pin1_SetAnalogMode()      do { ANSELHbits.ANS10 = 1; } while(0)
#define Motor1_Pin1_SetDigitalMode()     do { ANSELHbits.ANS10 = 0; } while(0)

// get/set Motor2_Pin0 aliases
#define Motor2_Pin0_TRIS                 TRISBbits.TRISB2
#define Motor2_Pin0_LAT                  LATBbits.LATB2
#define Motor2_Pin0_PORT                 PORTBbits.RB2
#define Motor2_Pin0_WPU                  WPUBbits.WPUB2
#define Motor2_Pin0_ANS                  ANSELHbits.ANS8
#define Motor2_Pin0_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define Motor2_Pin0_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define Motor2_Pin0_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define Motor2_Pin0_GetValue()           PORTBbits.RB2
#define Motor2_Pin0_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define Motor2_Pin0_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define Motor2_Pin0_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define Motor2_Pin0_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define Motor2_Pin0_SetAnalogMode()      do { ANSELHbits.ANS8 = 1; } while(0)
#define Motor2_Pin0_SetDigitalMode()     do { ANSELHbits.ANS8 = 0; } while(0)

// get/set Motor2_Pin1 aliases
#define Motor2_Pin1_TRIS                 TRISBbits.TRISB3
#define Motor2_Pin1_LAT                  LATBbits.LATB3
#define Motor2_Pin1_PORT                 PORTBbits.RB3
#define Motor2_Pin1_WPU                  WPUBbits.WPUB3
#define Motor2_Pin1_ANS                  ANSELHbits.ANS9
#define Motor2_Pin1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define Motor2_Pin1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define Motor2_Pin1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define Motor2_Pin1_GetValue()           PORTBbits.RB3
#define Motor2_Pin1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define Motor2_Pin1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define Motor2_Pin1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define Motor2_Pin1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define Motor2_Pin1_SetAnalogMode()      do { ANSELHbits.ANS9 = 1; } while(0)
#define Motor2_Pin1_SetDigitalMode()     do { ANSELHbits.ANS9 = 0; } while(0)

// get/set Fire_Led aliases
#define Fire_Led_TRIS                 TRISBbits.TRISB5
#define Fire_Led_LAT                  LATBbits.LATB5
#define Fire_Led_PORT                 PORTBbits.RB5
#define Fire_Led_WPU                  WPUBbits.WPUB5
#define Fire_Led_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define Fire_Led_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define Fire_Led_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define Fire_Led_GetValue()           PORTBbits.RB5
#define Fire_Led_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define Fire_Led_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define Fire_Led_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define Fire_Led_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)

// get/set Fire_Pin0 aliases
#define Fire_Pin0_TRIS                 TRISBbits.TRISB6
#define Fire_Pin0_LAT                  LATBbits.LATB6
#define Fire_Pin0_PORT                 PORTBbits.RB6
#define Fire_Pin0_WPU                  WPUBbits.WPUB6
#define Fire_Pin0_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define Fire_Pin0_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define Fire_Pin0_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define Fire_Pin0_GetValue()           PORTBbits.RB6
#define Fire_Pin0_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define Fire_Pin0_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define Fire_Pin0_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define Fire_Pin0_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set Fire_Pin1 aliases
#define Fire_Pin1_TRIS                 TRISBbits.TRISB7
#define Fire_Pin1_LAT                  LATBbits.LATB7
#define Fire_Pin1_PORT                 PORTBbits.RB7
#define Fire_Pin1_WPU                  WPUBbits.WPUB7
#define Fire_Pin1_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define Fire_Pin1_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define Fire_Pin1_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define Fire_Pin1_GetValue()           PORTBbits.RB7
#define Fire_Pin1_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define Fire_Pin1_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define Fire_Pin1_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define Fire_Pin1_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set Cond_Motor_Pin0 aliases
#define Cond_Motor_Pin0_TRIS                 TRISCbits.TRISC0
#define Cond_Motor_Pin0_LAT                  LATCbits.LATC0
#define Cond_Motor_Pin0_PORT                 PORTCbits.RC0
#define Cond_Motor_Pin0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Cond_Motor_Pin0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Cond_Motor_Pin0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Cond_Motor_Pin0_GetValue()           PORTCbits.RC0
#define Cond_Motor_Pin0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Cond_Motor_Pin0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set LED0 aliases
#define LED0_TRIS                 TRISCbits.TRISC1
#define LED0_LAT                  LATCbits.LATC1
#define LED0_PORT                 PORTCbits.RC1
#define LED0_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LED0_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LED0_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LED0_GetValue()           PORTCbits.RC1
#define LED0_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISCbits.TRISC2
#define LED1_LAT                  LATCbits.LATC2
#define LED1_PORT                 PORTCbits.RC2
#define LED1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED1_GetValue()           PORTCbits.RC2
#define LED1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

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

// get/set Cond_Led aliases
#define Cond_Led_TRIS                 TRISDbits.TRISD0
#define Cond_Led_LAT                  LATDbits.LATD0
#define Cond_Led_PORT                 PORTDbits.RD0
#define Cond_Led_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define Cond_Led_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define Cond_Led_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define Cond_Led_GetValue()           PORTDbits.RD0
#define Cond_Led_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define Cond_Led_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)

// get/set Cond_Motor_Pin1 aliases
#define Cond_Motor_Pin1_TRIS                 TRISDbits.TRISD1
#define Cond_Motor_Pin1_LAT                  LATDbits.LATD1
#define Cond_Motor_Pin1_PORT                 PORTDbits.RD1
#define Cond_Motor_Pin1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define Cond_Motor_Pin1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define Cond_Motor_Pin1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define Cond_Motor_Pin1_GetValue()           PORTDbits.RD1
#define Cond_Motor_Pin1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define Cond_Motor_Pin1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISDbits.TRISD5
#define LED2_LAT                  LATDbits.LATD5
#define LED2_PORT                 PORTDbits.RD5
#define LED2_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define LED2_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define LED2_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define LED2_GetValue()           PORTDbits.RD5
#define LED2_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/