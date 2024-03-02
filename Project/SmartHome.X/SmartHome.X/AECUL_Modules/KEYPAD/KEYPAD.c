
#include "KEYPAD.h"

uint8_t rows[4]={1,2,3,4};
uint8_t columns[4]={1,2,3,4};
static const uint8_t btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS] = {{'N','0','=','+'},{'1','2','3','-'},{'4','5','6','*'},{'7','8','9','/'}};
static void row_pin_write__logic(uint8_t value,uint8_t state)
{
    if(state == 1){
    switch (value) 
    {
            case 1:
                B1_SetHigh();
                break;
            case 2:
                B2_SetHigh();
                break;
            case 3:
                B3_SetHigh();
                break;
            case 4:
                B4_SetHigh();
                break;
            default:
                break;
    }
    }
    else {
        switch (value) 
    {
            case 1:
                B1_SetLow();
                break;
            case 2:
                B2_SetLow();
                break;
            case 3:
                B3_SetLow();
                break;
            case 4:
                B4_SetLow();
                break;
            default:
                break;
    }
        
    }
};
static uint8_t column_pin_read__logic(uint8_t value){
    uint8_t pin_state=0;
    switch (value){
            case 1:
                pin_state= A1_GetValue();
                break;
            case 2:
                pin_state= A2_GetValue();
                break;
            case 3:
                pin_state= A3_GetValue();
                break;
            case 4:
                pin_state= A4_GetValue();
                break;
        default:
            break;
    }
    return pin_state;
};




uint8_t keypad_get_value(void){
    uint8_t clicked_value=0xFF;
     uint8_t l_rows_counter = 0, l_columns_counter = 0, l_counter = 0;
    uint8_t column_logic = 0;
    for(l_rows_counter=0; l_rows_counter<ECU_KEYPAD_ROWS; l_rows_counter++){
            for(l_counter=0; l_counter<ECU_KEYPAD_ROWS; l_counter++){
                row_pin_write__logic(rows[l_counter],0);
            }
                row_pin_write__logic(rows[l_rows_counter],1);
            __delay_ms(10);
            for(l_columns_counter=0; l_columns_counter<ECU_KEYPAD_COLUMNS; l_columns_counter++){
                column_logic = column_pin_read__logic(columns[l_columns_counter]);
                if(1 == column_logic){
                    clicked_value = btn_values[l_rows_counter][l_columns_counter];
                }
            }
        }
    return clicked_value; 
};


