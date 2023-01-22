/*
 * hmi_ecu.h
 *
 *  Created on: Oct 31, 2022
 *      Author: Mahmoud Qotp
 */

#ifndef HMI_ECU_H_
#define HMI_ECU_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define PASSWORD_SIZE 5
#define PASSWORDS_ARE_MATCHED 0xE8
#define PASSWORDS_ARE_MISMATCHED 0xE2
#define SET_PASSWORD 0xD3
#define SEND_PASSWORD 0xD7
#define CHANGE_PASSWORD 0xC1
#define SENDING_STATUS 0xC6
#define READY_TO_RECEIVE 0xAA
#define OPEN_DOOR 0xBB
#define ENTER '='

#define TIMER_INITIAL_VALUE 0
#define TIMER_COMPARE_VALUE 15624
#define TIMER_PRESCALER 256
#define MOTOR_ROTATING_TIME 30 /*15 Sec = 30 Interrupts*/
#define HOLDING_TIME 6 /*3 Sec = 6 Interrupts*/
#define ERROR_DELAY 120 /*60 Sec = 120 Interrupts*/
#define UART_BAUD_RATE 9600


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * [Function Name]: HMI_ECU_init
 * [Function Description]: This Function should initialize the HMI ECU by Initializing all the peripherals
 * 							it depends on by:
 * 							1- initialize LCD
 * 							2- define structure of type Timer1_ConfigType to initialize Timer1.
 * 							3- define structure of type UART_ConfigType to initialize UART.
 * 							4- Setting the call back function.
 * 							5- Enabling the interrupts.
 *
 * Interrupt each half second.
 * Based On The next Calculations:
 * 		Timer Frequency = CPU Frequency / Prescaler
 * 		Timer Instruction Time = 1 / Timer Frequency
 * 		Total Number of Counts = (Required Time / Timer Instruction Time) - 1
 *
 *
 * Inputs: No inputs.
 * Outputs: No Outputs.
 */
void HMI_ECU_init(void);

/*
 * [Function Name]: sendPassword
 * [Function Description]: Function to send Array (Password) by UART.
 *
 *
 * Inputs: Array of characters.
 * Outputs: No Outputs.
 */
void sendPassword(uint8 *sendPassword);

/*
 * [Function Name]: HMI_getPassword
 * [Function Description]: Function to get Password from Keypad.
 *
 *
 * Inputs: Array of characters.
 * Outputs: No Outputs. (Actually it returns the change happened in the input array.
 */

/*void HMI_getPassword(uint8 *str);*/

/*
 * [Function Name]: setPassword
 * [Function Description]: Function to set password of the Door Locker Security System.
 *
 *
 * Inputs: No inputs (It manipulate global variables)
 * Outputs: No Outputs. (Doesn't return any thing but it is using UART to send and receive data)
 */
void setPassword(void);

/*
 * [Function Name]: resetPassword
 * [Function Description]: Function to reset password of the Door Locker Security System.
 *
 *
 * Inputs: No inputs (It manipulate global variables)
 * Outputs: No Outputs. (Doesn't return any thing but it is using UART to send and receive data)
 */
void resetPassword(void);

/*
 * [Function Name]: HMI_ECU_newTimerTick
 * [Function Description]: Function to be called by the ISR.
 *
 *
 * Inputs: No inputs.
 * Outputs: No Outputs.
 */

void HMI_ECU_newTimerTick(void);

/*
 * [Function Name]: Delay
 * [Function Description]: Function to make delay for certain time based on the interrupt time.
 *
 *
 * Inputs: Number of interrupts to be delayed with.
 * Outputs: No Outputs.
 */
void Delay(uint8 interruptsCount);

/*
 * [Function Name]: HMI_Open_Locker
 * [Function Description]: Function to interact with user based on what happens in the control ECU.
 *
 *
 * Inputs: No Inputs.
 * Outputs: No Outputs.
 */
void HMI_Open_Locker(void);

/*
 * [Function Name]: openDoor
 * [Function Description]: Function responsible about Opening door of the locker.
 *
 *
 * Inputs: No Inputs.
 * Outputs: No Outputs.
 */
void openDoor(void);


/*
 * [Function Name]: HMI_mainOptions
 * [Function Description]: Function display the main options and get the option from user to proceed.
 *
 *
 * Inputs: No Inputs.
 * Outputs: No Outputs.
 */
/*void HMI_mainOptions(void);*/

#endif /* HMI_ECU_H_ */
