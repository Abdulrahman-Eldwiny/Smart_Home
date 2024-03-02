
#include "mcc_generated_files/examples/i2c_master_example.h"

#include "mcc_generated_files/mcc.h"
#include "AECUL_Modules/RealTimeClockDS1307/RealTimeClockDS1307.h"
#include "AECUL_Modules/EEPROM_24C02C/EEPROM_24C02C.h"
#include "AECUL_Modules/TemSensor_TC74/TemSensor_TC74.h"
#include "AECUL_Modules/LCD/LCD.h"
#include "AECUL_Modules/KEYPAD/KEYPAD.h"

//defines
#define PASS_SIZE 4
#define PASS_EMPTY 0xFF
#define CHARACTER_PREVIEW_TIME (uint16_t)300
#define PASSWORD_SYMBOL (uint8_t)'*'
#define DEGREES_SYMBOL		   (uint8_t)0xDF
#define ASCII_ZERO      (uint8_t)'0'




//0x00 ---> OFF
//0x01 ---> ON






// variables
uint8_t U4RecValue, U5RecValue;
uint8_t TC74_A7_TempValue = 0;
uint8_t ON_counter =0; //EEPROM number of times the device have been ON
uint8_t pass_counter=0;//the counter of the characters of the password
uint8_t pass_entry_counter=0; //EEPROM number of times the password have been entered
RealTimeClockDS1307_T RealTimeClockDS1307;
uint8_t Full_Password[PASS_SIZE]={PASS_EMPTY,PASS_EMPTY,PASS_EMPTY,PASS_EMPTY};//the array where it stored the password
uint8_t Password_Check[PASS_SIZE]={PASS_EMPTY,PASS_EMPTY,PASS_EMPTY,PASS_EMPTY};
uint8_t Password_Approval=0; 
uint8_t Input_temp=30;
uint8_t conditioner_state=0;
uint8_t    pressed_button = 0xFF;
uint8_t opened_flag;
uint8_t opened_in_flag;
uint8_t led1_state;
uint8_t led2_state;
uint8_t led3_state;
uint8_t tv_state;
uint8_t windows1_state;
uint8_t windows2_state;
uint8_t radio_state;
uint8_t fire_alarm;
uint8_t first_time;
uint8_t back_to_safety=0xFF;

void main(void)
{
    DATAEE_WriteByte(0x00,0); 
    DATAEE_WriteByte(0x40,0); 
    // Initialize the device
    SYSTEM_Initialize();
    LCD_vInit();
    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();
    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();
//    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
     
        ////   For The First Time
        DATAEE_WriteByte(0x10,Input_temp/10);
        DATAEE_WriteByte(0x11,Input_temp%10);      
        ON_counter= DATAEE_ReadByte(0x00);
        if(ON_counter == 0){

            __delay_ms(2000);
            LCD_clearscreen();
            LCD_vSend_string("Login for");//printing login menu
            LCD_movecursor(2,1);//move the cursor to the second line
            LCD_vSend_string("first time");
            __delay_ms(1000);//Halt the system for the given time in (ms)
            LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
            LCD_vSend_string("Set guest pass");//printing the set admin password menu
            LCD_movecursor(2,1);
            LCD_vSend_string("Guest Pass:");

            while (pass_counter<PASS_SIZE)//loop till the user finish inserting the pass
            {
                pressed_button = 0xFF;//return the variable that holds the pressed key from keypad to its initial value
                while (pressed_button == 0xFF)//repeat till the user press any key
                {
                    pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                }
                Full_Password[pass_counter]= pressed_button;//add the entered character to the pass array
                LCD_vSend_char(pressed_button);//print the entered character
                __delay_ms(CHARACTER_PREVIEW_TIME);//Halt the system for the given time in (ms)
                LCD_movecursor(2,12+pass_counter);//move the lcd cursor to the previous location to write the password symbol over the character
                LCD_vSend_char(PASSWORD_SYMBOL); // to display (Password sign *)
                __delay_ms(100);//Halt the system for the given time in (ms)
                pass_counter++;//increase the characters count


            }
            DATAEE_WriteByte(0x08,Full_Password[0]);
            DATAEE_WriteByte(0x09,Full_Password[1]);
            DATAEE_WriteByte(0x0A,Full_Password[2]);
            DATAEE_WriteByte(0x0B,Full_Password[3]);
            LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
            LCD_vSend_string("Pass Saved");// show pass saved message
            __delay_ms(500);//Halt the system for the given time in (ms)
            LCD_clearscreen();
            ON_counter++;
            DATAEE_WriteByte(0x00,ON_counter);
    }
  
        
        
//        after setting password
        
        
        
        
        
        
    while(1)
    {
    __delay_ms(1500);
//     
//    
//    
//    
//  
//                        Working Remote loop
//    
//    
//    
//    
    if(pressed_button == 'N' || first_time==0){
        pressed_button=0xFF;
        pass_counter=0;
        first_time=1;

        LCD_vSend_string("Welcome to smart");
        LCD_movecursor(2,1);
        LCD_vSend_string("home system");
        ON_counter= DATAEE_ReadByte(0x00);
        __delay_ms(1500);

		LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
        
//        Checking for The password
        while(Password_Approval==0)
        {
                
            LCD_vSend_string("Enter guest pass");//printing the set admin password menu
            LCD_movecursor(2,1);
            LCD_vSend_string("Guest Pass:");

            while (pass_counter<PASS_SIZE)//loop till the user finish inserting the pass
            {
                pressed_button = 0xFF;//return the variable that holds the pressed key from keypad to its initial value
                while (pressed_button == 0xFF)//repeat till the user press any key
                {
                    pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                }
                 if(pressed_button == 'N'){
                      break;
                 } 
                Password_Check[pass_counter]= pressed_button;//add the entered character to the pass array
                LCD_vSend_char(pressed_button);//print the entered character
                __delay_ms(CHARACTER_PREVIEW_TIME);//Halt the system for the given time in (ms)
                LCD_movecursor(2,12+pass_counter);//move the lcd cursor to the previous location to write the password symbol over the character
                LCD_vSend_char(PASSWORD_SYMBOL); // to display (Password sign *)
                __delay_ms(100);//Halt the system for the given time in (ms)
                pass_counter++;//increase the characters count
            }
            if(pressed_button == 'N'){
                    break;
                 } 
            if(Password_Check[0] == DATAEE_ReadByte(0x08) && Password_Check[1]==DATAEE_ReadByte(0x09) && Password_Check[2]==DATAEE_ReadByte(0x0A) && Password_Check[3]==DATAEE_ReadByte(0x0B))
            {
                LCD_clearscreen();
                LCD_vSend_string("Login Approved");
                __delay_ms(500);
                LCD_clearscreen();
                Password_Approval=1;
            }
            else
            {
                LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                LCD_vSend_string("Wrong Password");// show pass saved message
                pass_counter=0;
                __delay_ms(500);//Halt the system for the given time in (ms)
                LCD_clearscreen(); 
                if(pass_entry_counter <2){
                pass_entry_counter++;
                }
                else
                {
                    for(int i=0x39;i>0x30;i--)
                    {
                        LCD_vSend_string("Please wait: ");
                        LCD_movecursor(2,4);
                        LCD_vSend_char(i);
                        __delay_ms(1000);
                        LCD_clearscreen(); 
                    }
                    continue;
                    pass_entry_counter=0;
                }
            }
        }
                     
        
//       
//        
//        
//        
//        
//        
//        
//        
//                             MAIN CODE
//                        Entered the system
//        
//        
//        
//        
//        
//        
//        
//        
//        
//        
//    
      if(pressed_button == 'N'){
        pressed_button= 0xFF;
      } 
      else{  
        while(1){
                TC74_A7_TempValue = TempSensor_TC74_Read_Temp(0x9E);
                conditioner_state= DATAEE_ReadByte(0x40);
            if(conditioner_state==0x01 && TC74_A7_TempValue > Input_temp){
                if(opened_flag==0){
                EUSART_Write('G');
                opened_flag=1;
            }
            }
            else{
                    if(opened_flag==1){
                    EUSART_Write('F');
                    opened_flag=0;
                    }
            }
            LCD_clearscreen(); 
            LCD_vSend_string("1:Room1 2:Room2");
            LCD_movecursor(2,1);
            LCD_vSend_string("3:Room3 ON/C:Off");
            pressed_button = 0xFF;//return the variable that holds the pressed key from keypad to its initial value
            while (pressed_button == 0xFF)//repeat till the user press any key
            {
                pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
            }
            
            
            
            
            
//            Room One
            
            
            
            if(pressed_button == '1'){
                
                LCD_clearscreen(); 
                __delay_ms(1000);
                LCD_vSend_string("1:Light");
                LCD_movecursor(2,1);
                LCD_vSend_string("2:conditioner");
                pressed_button = 0xFF;//return the variable that holds the pressed key from keypad to its initial value
                while (pressed_button == 0xFF)//repeat till the user press any key
                {
                    pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                }
                if(pressed_button == '1')
                {
                    LCD_clearscreen(); 
                    __delay_ms(1000);
                    LCD_vSend_string("1-On 2-Off");
                    pressed_button = 0xFF;
                     while (pressed_button == 0xFF)//repeat till the user press any key
                    {
                        pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                    }
                    if(pressed_button == '1'){
                        if(led1_state==0){
                            led1_state=0x01;
                            EUSART_Write('A');
                            DATAEE_WriteByte(0x80,led1_state); 
                        }
                       
                    }
                    else if(pressed_button == '2'){
                        if(led1_state==1){
                            EUSART_Write('Z');
                            led1_state=0x00;
                            DATAEE_WriteByte(0x80,led1_state);
                        }       
                    }
                    else if(pressed_button == 'N'){
                         pressed_button=0xFF;
                         break;
                    } 
                    else
                    {
                        LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                        LCD_vSend_string("Wrong input");//print error message
                        __delay_ms(500);//Halt the system for the given time in (ms)
                        continue;//return to #while (temperature==0)# line 672
                    }
                }
                else if(pressed_button == 'N'){
                            pressed_button=0xFF;
                            break;
                        } 
                else if(pressed_button == '2'){
                     LCD_clearscreen(); 
                      __delay_ms(500);
                    LCD_vSend_string("1:Control 2:state");
                    LCD_movecursor(2,1);
                    LCD_vSend_string("3-Set temperature");
                    pressed_button = 0xFF;
                     while (pressed_button == 0xFF)//repeat till the user press any key
                    {
                        pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                    }
                    if(pressed_button == '1'){
                             LCD_clearscreen(); 
                            __delay_ms(1000);
                            
                            LCD_vSend_string("1- On 2-Off");
                            pressed_button = 0xFF;
                            while (pressed_button == 0xFF)//repeat till the user press any key
                           {
                               pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                           }
                            if(pressed_button == '1'){
                                if(conditioner_state==0){
                                    conditioner_state=1;
                                    DATAEE_WriteByte(0x40,0x01);
                                }
                                
                            }
                            else if(pressed_button == '2'){
                                 if(conditioner_state==1){
                                conditioner_state=0;
                                DATAEE_WriteByte(0x40,0x00);
                                 }
                            }
                            else if(pressed_button == 'N'){
                            pressed_button=0xFF;
                            break;
                            } 
                            else{
                            LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                            LCD_vSend_string("Wrong input");//print error message
                            __delay_ms(500);//Halt the system for the given time in (ms)
                            continue;//return to #while (temperature==0)# line 672
                            }
                        }
                    else if(pressed_button == 'N'){
                         pressed_button=0xFF;
                         break;
                    } 
                    else if(pressed_button =='2'){
                        LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                        if(conditioner_state==1){
                        LCD_vSend_string("state:ON");//print the format of inserting temperature
                        LCD_movecursor(2,1);
                        LCD_vSend_string("Temp: ");
                        LCD_vSend_char(DATAEE_ReadByte(0x10)+ASCII_ZERO);
                        LCD_vSend_char(DATAEE_ReadByte(0x11)+ASCII_ZERO);
                        }
                        else{
                            LCD_vSend_string("state: OFF");
                        }
                        __delay_ms(1500);
                    }
                    else if(pressed_button == '3')
                    {
                        LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                        LCD_vSend_string("Set temp.:__ ");//print the format of inserting temperature
                        LCD_vSend_char(DEGREES_SYMBOL); // print the symbol of degree
                        LCD_vSend_char('C'); // print the C character
                        LCD_movecursor(1,11);//move the cursor to the place to write the entered temperature
                        __delay_ms(200);//Halt the system for the given time in (ms)
                        pressed_button = 0xFF;
                         while (pressed_button == 0xFF)//repeat till the user press any key
                        {
                            pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                        }
                        if (pressed_button <'0' || pressed_button >'9' )//show wrong input message if the user entered non numeric value
                        {
                            LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                            LCD_vSend_string("Wrong input");//print error message
                            __delay_ms(500);//Halt the system for the given time in (ms)
                            continue;//return to #while (temperature==0)# line 672
                        }
                        else{
                            LCD_vSend_char(pressed_button);//print the value on the lcd
                            Input_temp = pressed_button-ASCII_ZERO;//save the entered value
                            pressed_button = 0xFF;;//set the key pressed to the default value
                            DATAEE_WriteByte(0x10, Input_temp);
                        }
                        __delay_ms(300);
                        
                        while (pressed_button == 0xFF)//repeat till the user press any key
                        {
                            pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                        }
                        if (pressed_button <'0' || pressed_button >'9')//show wrong input message if the user entered non numeric value
                        {
                            LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                            LCD_vSend_string("Wrong input");//print error message
                            __delay_ms(500);//Halt the system for the given time in (ms)
                            continue;//return to #while (temperature==0)# line 672
                        }
                        else{
                            LCD_vSend_char(pressed_button);//print the value on the lcd
                            Input_temp = pressed_button-ASCII_ZERO;//save the entered value
                            pressed_button = 0xFF;;//set the key pressed to the default value
                            DATAEE_WriteByte(0x11, Input_temp);
                        }
                    Input_temp=DATAEE_ReadByte(0x10)*10+ DATAEE_ReadByte(0x11);
                    }
                    
                }
                else{
                            LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                            LCD_vSend_string("Wrong input");//print error message
                            __delay_ms(500);//Halt the system for the given time in (ms)
                            continue;//return to #while (temperature==0)# line 672  
                }
            }
            
            
            
//            Room Two
            
            
            
            else if(pressed_button == '2'){
                LCD_clearscreen(); 
                __delay_ms(1000);
                LCD_vSend_string("1:Light 2:Windows");
                
                pressed_button = 0xFF;//return the variable that holds the pressed key from keypad to its initial value
                while (pressed_button == 0xFF)//repeat till the user press any key
                {
                    pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                }
                if(pressed_button == '1')
                {
                    
                    LCD_clearscreen(); 
                    __delay_ms(1000);
                    LCD_vSend_string("1-On 2-Off");
                    pressed_button = 0xFF;
                     while (pressed_button == 0xFF)//repeat till the user press any key
                    {
                        pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                    }
                    if(pressed_button == '1'){
                        if(led2_state== 0x00){
                        EUSART_Write('L');
                        led2_state=0x01;
                        DATAEE_WriteByte(0x81,led2_state);
                        }
                    }
                    else if(pressed_button == 'N'){
                         pressed_button=0xFF;
                         break;
                    } 
                    else if(pressed_button == '2'){
                        if(led2_state== 0x01){
                        EUSART_Write('Y');
                        led2_state=0x00;
                        DATAEE_WriteByte(0x81,led2_state);
                        }
                    }
                    else
                    {
                        LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                        LCD_vSend_string("Wrong input");//print error message
                        __delay_ms(500);//Halt the system for the given time in (ms)
                        continue;//return to #while (temperature==0)# line 672
                    }
                }
                
                else if(pressed_button == 'N'){
                     pressed_button=0xFF;
                     break;
                    } 
                
                
//                WINDOOOWS
                
                else if(pressed_button == '2')
                {
                     LCD_clearscreen(); 
                     __delay_ms(500);
                    LCD_vSend_string("1-ON   2-OFF");
                    pressed_button = 0xFF;
                     while (pressed_button == 0xFF)//repeat till the user press any key
                    {
                        pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                    }
                    if(pressed_button == '1'){
                        if(windows1_state==0x00){
                            EUSART_Write('Q');
                            windows1_state=0x01;
                            DATAEE_WriteByte(0x82,windows1_state);
                        }
                        }
                    else if(pressed_button == 'N'){
                         pressed_button=0xFF;
                         break;
                    } 
                    else if(pressed_button == '2')
                    {
                        if(windows1_state==0x01){
                        EUSART_Write('W');
                        windows1_state=0x00;
                        DATAEE_WriteByte(0x82,windows1_state);
                        }
                    }
                    else
                    {
                            LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                            LCD_vSend_string("Wrong input");//print error message
                            __delay_ms(500);//Halt the system for the given time in (ms)
                            continue;//return to #while (temperature==0)# line 672  
                    }
                }
            }
            
            
            
            
//            Room 3
            
            
            
            
            
            else if(pressed_button == '3')
            {
                LCD_clearscreen(); 
                __delay_ms(1000);
                LCD_vSend_string("1:Light 2:windows");
                LCD_movecursor(2,1);
                LCD_vSend_string("3:TV  4:Radio");
                pressed_button = 0xFF;//return the variable that holds the pressed key from keypad to its initial value
                while (pressed_button == 0xFF)//repeat till the user press any key
                {
                    pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                }
                if(pressed_button == '1')
                {
                    LCD_clearscreen(); 
                    __delay_ms(1000);
                    LCD_vSend_string("1-On 2-Off");
                    pressed_button = 0xFF;
                     while (pressed_button == 0xFF)//repeat till the user press any key
                    {
                        pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                    }
                    if(pressed_button == '1'){
                        if(led3_state==0x00){  
                        EUSART_Write('R');
                        led3_state=0x01;
                        DATAEE_WriteByte(0x83,led3_state);
                        }
                    }
                    else if(pressed_button == '2'){
                        if(led3_state==0x01){ 
                        EUSART_Write('T');
                        led3_state=0x00;
                        DATAEE_WriteByte(0x83,led3_state);
                        }
                    }
                    else
                    {
                        LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                        LCD_vSend_string("Wrong input");//print error message
                        __delay_ms(500);//Halt the system for the given time in (ms)
                        continue;//return to #while (temperature==0)# line 672
                    }
                }
//                
//                
//                
//                
                //windows 
//                
//                
//                
//                
                else if(pressed_button == '2')
                {
                     LCD_clearscreen(); 
                     __delay_ms(500);
                    LCD_vSend_string("1-ON   2-OFF");
                    pressed_button = 0xFF;
                     while (pressed_button == 0xFF)//repeat till the user press any key
                    {
                        pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                    }
                    if(pressed_button == '1'){
                        if(windows2_state==0x00){
                            EUSART_Write('U');
                            windows2_state=0x01;
                            DATAEE_WriteByte(0x84,windows2_state);
                        }
                        }
                    else if(pressed_button == 'N'){
                         pressed_button=0xFF;
                         break;
                    } 
                    else if(pressed_button == '2')
                    {
                        if(windows2_state== 0x01){
                        EUSART_Write('I');
                        windows2_state=0x00;
                        DATAEE_WriteByte(0x84,windows2_state);
                        }
                    }
                    else{
                            LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                            LCD_vSend_string("Wrong input");//print error message
                            __delay_ms(500);//Halt the system for the given time in (ms)
                            continue;//return to #while (temperature==0)# line 672  
                    }        
                }

            
                else if(pressed_button == '3')
                {
                    LCD_clearscreen(); 
                     __delay_ms(500);
                    LCD_vSend_string("1-ON   2-OFF");
                    pressed_button = 0xFF;
                     while (pressed_button == 0xFF)//repeat till the user press any key
                    {
                        pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                    }
                    if(pressed_button == '1'){
                        if(tv_state==0x00){
                            EUSART_Write('V');
                            tv_state=0x01;
                            DATAEE_WriteByte(0x85,tv_state);
                        }
                        }
                    else if(pressed_button == 'N'){
                         pressed_button=0xFF;
                         break;
                    } 
                    else if(pressed_button == '2')
                    {
                        if(tv_state==0x01){
                        EUSART_Write('S');
                        tv_state=0x00;
                        DATAEE_WriteByte(0x85,tv_state);
                        }
                    }

                    else{
                            LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                            LCD_vSend_string("Wrong input");//print error message
                            __delay_ms(500);//Halt the system for the given time in (ms)
                            continue;//return to #while (temperature==0)# line 672  
                    }
                }
                else if(pressed_button == '4')
                {
                    LCD_clearscreen(); 
                     __delay_ms(500);
                    LCD_vSend_string("1-ON   2-OFF");
                    pressed_button = 0xFF;
                     while (pressed_button == 0xFF)//repeat till the user press any key
                    {
                        pressed_button = keypad_get_value();//if the user pressed any button in keypad save the value in key_pressed
                    }
                    if(pressed_button == '1'){
                        if(radio_state==0x00){
                            EUSART_Write('M');
                            radio_state=0x01;
                            DATAEE_WriteByte(0x86,radio_state);
                        }
                        }
                    else if(pressed_button == 'N'){
                         pressed_button=0xFF;
                         break;
                    } 
                    else if(pressed_button == '2')
                    {
                        if(radio_state==0x01){
                        EUSART_Write('P');
                        radio_state=0x00;
                        DATAEE_WriteByte(0x86,radio_state); 
                        }
                    }
                    else{
                            LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                            LCD_vSend_string("Wrong input");//print error message
                            __delay_ms(500);//Halt the system for the given time in (ms)
                            continue;//return to #while (temperature==0)# line 672  
                    }
                }
            
            
//           Shut Down
                else if(pressed_button == 'N')
                {
                         pressed_button=0xFF;
                         break;
                } 
            
            
                else{
                    LCD_clearscreen(); 
                    LCD_vSend_string("please select one");
                    LCD_movecursor(2,1);
                    LCD_vSend_string("of the options");
                    continue;
                }
            }
            else if(pressed_button =='N'){
                pressed_button=0xFF;
                break;
            }
            else{
                LCD_clearscreen();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
                LCD_vSend_string("Wrong input");//print error message
                __delay_ms(500);//Halt the system for the given time in (ms)
                continue;//return to #while (temperature==0)# line 672  
            }
        
        }
    } 
}
//    
//    
//    
//    
//    
//    
//    
//    non Working Remote loop
//    
//    
//    
//    
//    
//    
//    
//    
//    
   
    else{
    while (1)
    { 
         LCD_clearscreen(); 
         TC74_A7_TempValue = TempSensor_TC74_Read_Temp(0x9E);
         Input_temp=DATAEE_ReadByte(0x10)*10+ DATAEE_ReadByte(0x11);
         conditioner_state= DATAEE_ReadByte(0x40);
         Password_Approval=0;
            if((conditioner_state==0x01 )&&( TC74_A7_TempValue > Input_temp) && (TC74_A7_TempValue < 0x37)){
                if(back_to_safety==0){
                    EUSART_Write('G');
                    back_to_safety=1;
                }
                if(opened_flag==0){
                EUSART_Write('G');
                opened_flag=1;
                fire_alarm=0;
            }
            }
            if(((conditioner_state==0x00) ||( TC74_A7_TempValue < Input_temp) )&& (TC74_A7_TempValue < 0x37)){
                    if(back_to_safety==0){
                        EUSART_Write('F');
                        back_to_safety=1;
                    }
                    if(opened_flag==1){
                        EUSART_Write('F');
                        opened_flag=0;
                        fire_alarm=0;
                    }
            }
            if(TC74_A7_TempValue>0x37)
            {
                if(fire_alarm==0){
                    EUSART_Write('B');
                    fire_alarm=1;
                    back_to_safety=0;
                    opened_flag=0;
                    windows1_state=0x01;
                    windows2_state=0x01;
		    led1_state=0x00;
		    led2_state=0x00;
	            led3_state=0x00;
                    tv_state=0x00;
		    radio_state=0x00;
                }
            }

               

          pressed_button = keypad_get_value();//if the user presses any button in the keypad save the value in key_pressed
          if(pressed_button == 'N'){
              break;
          }
          else{
              
          }
    }
    }
    }
}
