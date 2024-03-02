#include "LCD.h"
#define eight_bits_mode

void LCD_vInit(void)
{
	/*****************************/
	RW_SetLow(); // enable write to LCD 
	LCD_vSend_cmd(EIGHT_BIT_MODE); //enable 8 bit LCD Mode 
	LCD_vSend_cmd(CLR_SCREEN); // CLR LCD screen 
	LCD_vSend_cmd(DISPLAY_ON_CURSOR_ON); // enable cursor and display on 
	__delay_ms(10); //small delay to ensure LCD finish the initialization
} // end of LCD initialization

static void send_falling_edge(void)
{
	/* to enable printing the sent character to LCD ,we should send send falling edge to the lcd*/ 
	E_SetHigh(); // set enable pin to one
	__delay_ms(2); //period of high
	E_SetLow(); // clear enable pin 
	__delay_ms(2); // period of low
}
void LCD_vSend_cmd(uint8_t cmd)
{
	DIO_write_port('D',cmd); //send the command to LCD
	RS_SetLow(); //enable LCD to receive command 
	send_falling_edge(); //send falling edge	
}

void LCD_vSend_char(uint8_t data)
{
	DIO_write_port('D',data); //send the data to LCD
	RS_SetHigh() ; //enable LCD to receive data
	send_falling_edge(); //send falling edge	
}


void LCD_vSend_string(char *data)
{
	while((*data)!=0) //keep in the loop until the end of the string 
	{
		LCD_vSend_char(*data); // print the characters of the string 
		data++; // make the pointer points to the next character
	}
}



void LCD_clearscreen(void)
{
	LCD_vSend_cmd(CLR_SCREEN); // clear the screen
}
void LCD_movecursor(uint8_t row,uint8_t coloumn)
{
	uint8_t data ; // the command which will set the position of the cursor
	/* in case of wrong input set the cursor to the first position of the LCD*/
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	/********************************************/
	/*set the postion of cursor depend on the selected row and coloumn*/
	if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	/**************************************/
	
	LCD_vSend_cmd(data); //set the position  of the cursor
}
