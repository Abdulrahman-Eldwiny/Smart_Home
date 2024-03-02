/* 
 * File:   KEYPAD.h
 * Author: abdoe
 * Created on February 7, 2024, 10:52 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H


/* ----------------- Includes -----------------*/
#include "../../mcc_generated_files/mcc.h"

/* ----------------- Macro Declarations -----------------*/
#define ECU_KEYPAD_ROWS    4
#define ECU_KEYPAD_COLUMNS 4 

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

/* ----------------- Software Interfaces Declarations -----------------*/
uint8_t keypad_get_value(void);



#endif	/* KEYPAD_H */

