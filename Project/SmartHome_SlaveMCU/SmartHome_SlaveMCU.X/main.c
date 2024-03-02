
#include "mcc_generated_files/mcc.h"
#define WINDOW_ON 1
#define WINDOW_OFF 0

uint8_t RecTC74_A7_TempValue = 0;
uint8_t readed_value;
uint8_t zero_crossing;
uint8_t counter=0;

static void Custom_I2C_SlaveDefRdInterruptHandler() {
    RecTC74_A7_TempValue = SSPBUF;
}

uint8_t window1_state;
uint8_t window2_state;


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();
    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    
    while (1)
    {

        

        readed_value = EUSART_Read();
        if(readed_value=='A'){
            LED0_SetHigh(); 
            
        }
        else if(readed_value=='Z'){
            LED0_SetLow(); 
        }
        else if(readed_value=='L'){
            DATAEE_WriteByte(0x01,0x01);
            LED1_SetHigh();  
        }
        else if(readed_value=='Y'){
             DATAEE_WriteByte(0x01,0x00);
             LED1_SetLow(); 
        }
        else if(readed_value=='R'){
             DATAEE_WriteByte(0x01,0x00);
                LED2_SetHigh(); 

        }
        else if(readed_value=='T'){
             DATAEE_WriteByte(0x01,0x00);
                LED2_SetLow(); 

        }
        else if(readed_value=='B'){
           
           Fire_Pin0_SetHigh();
           Fire_Pin1_SetLow();
           Fire_Led_SetHigh();
           LED2_SetLow();
           LED1_SetLow(); 
           LED0_SetLow();
           Cond_Motor_Pin0_SetLow();
           Cond_Motor_Pin1_SetLow();
           Cond_Led_SetLow();
           if(window1_state== WINDOW_OFF || window2_state== WINDOW_OFF){
                if(window1_state== WINDOW_OFF ){
                     Motor1_Pin0_SetHigh();
                     Motor1_Pin1_SetLow();
                     window1_state=WINDOW_ON;
                }
                else{
                }

                if(window2_state== WINDOW_OFF ){
                     Motor2_Pin0_SetHigh();
                     Motor2_Pin1_SetLow();
                     window2_state=WINDOW_ON;
                }
                else{
                }
                __delay_ms(1000);
           }
           else{

           }
           Motor1_Pin0_SetLow();
           Motor1_Pin1_SetLow();
           Motor2_Pin0_SetLow();
           Motor2_Pin1_SetLow();
           Radio_Switch_SetLow();
           Tv_Switch_SetLow();
           Fire_Led_Toggle();
           __delay_ms(200);
           Fire_Led_Toggle();
           __delay_ms(200);
           Fire_Led_Toggle();
           __delay_ms(200);
           Fire_Led_Toggle();
           __delay_ms(200);
           Fire_Led_Toggle();
           __delay_ms(200);
           Fire_Led_Toggle();
           __delay_ms(200);
           Fire_Led_Toggle();
           __delay_ms(200);
           Fire_Led_Toggle();
           __delay_ms(200);

           Fire_Led_SetHigh();
        }

        else if(readed_value== 'F'){
            Cond_Motor_Pin0_SetLow();
            Cond_Motor_Pin1_SetLow();
            Cond_Led_SetLow();
            Fire_Pin0_SetLow();
            Fire_Pin1_SetLow();
            Fire_Led_SetLow();
        }
        else if(readed_value== 'G'){
            Cond_Motor_Pin0_SetHigh();
            Cond_Motor_Pin1_SetLow();
            Cond_Led_SetHigh();
            Fire_Pin0_SetLow();
            Fire_Pin1_SetLow();
            Fire_Led_SetLow();
        }
        else if(readed_value== 'Q'){
            Motor1_Pin0_SetHigh();
            Motor1_Pin1_SetLow();
            __delay_ms(1000);
            Motor1_Pin0_SetLow();
            Motor1_Pin1_SetLow();
            window1_state= WINDOW_ON;
        }
        else if(readed_value== 'W'){
            Motor1_Pin0_SetLow();
            Motor1_Pin1_SetHigh();
            __delay_ms(1000);
            Motor1_Pin0_SetLow();
            Motor1_Pin1_SetLow();
            window1_state= WINDOW_OFF;
        }
        else if(readed_value== 'U'){
            Motor2_Pin0_SetHigh();
            Motor2_Pin1_SetLow();
            __delay_ms(1000);
            Motor2_Pin0_SetLow();
            Motor2_Pin1_SetLow();
            window2_state= WINDOW_ON;
        }
        else if(readed_value== 'I'){
            Motor2_Pin0_SetLow();
            Motor2_Pin1_SetHigh();
            __delay_ms(1000);
            Motor2_Pin0_SetLow();
            Motor2_Pin1_SetLow();
            window2_state= WINDOW_OFF;
        }
        else if(readed_value=='V'){
            Tv_Switch_SetHigh();
        }
        else if(readed_value=='S'){
             Tv_Switch_SetLow();
        }
        else if(readed_value=='M'){
             Radio_Switch_SetHigh();
        }
        else if(readed_value=='P'){
             Radio_Switch_SetLow();
        }
        else{
            
            
        }
        
    }
}

