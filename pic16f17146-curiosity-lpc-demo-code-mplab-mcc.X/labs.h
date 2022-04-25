/**
  Lab Header File

  @Company
    Microchip Technology Inc.

  @File Name
    labs.h

  @Summary
    This is the header file for the variables declarations and function prototypes

  @Description
    This header file provides all the variables and function prototypes used in this project.
 */

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef LABS_H
#define	LABS_H

#include <xc.h>
#include <stdint.h>
    
/**
  Section: Macro Declarations
 */   
#define PRESSED             (1)
#define NOT_PRESSED         (0)
#define RUNNING             (1)
#define NOT_RUNNING         (0)
#define TURN_OFF_ALL_LEDs()       do { LED_D4_LAT  = 0; LED_D5_LAT  = 0; LED_D6_LAT  = 0; LED_D7_LAT  = 0; } while(0)

#define INTERRUPT_TMR0InterruptEnable()         do { PIE0bits.TMR0IE = 1; } while(0)
#define INTERRUPT_TMR0InterruptDisable()        do { PIE0bits.TMR0IE = 0; } while(0)

/**
  Section: Variable Declaration
 */
extern uint8_t labState;
extern bool isSwitchPressed;

/**
  Section: Function Prototypes
 */  
/**
 * @brief Performs the HelloWorld Lab.
 * This turns on LED_D4 on the Curiosity Board. 
 * @pre SYSTEM_Initialize() functions should have been called before calling this function.
 * @param none
 * @return none
*/
void LAB_HelloWorld(void);

/**
 * @brief Performs the Blink Lab.
 * LED_D4 blinks at a rate of approximately 500 milliseconds. 
 * @pre SYSTEM_Initialize() functions should have been called before calling this function.
 * @param none
 * @return none
*/
void LAB_Blink(void);

/**
 * @brief Performs the Rotate Lab.
 * The LEDs rotate from right to left at a rate of 0.5s
 * @pre SYSTEM_Initialize() functions should have been called before calling this function.
 * @param none
 * @return none
*/
void LAB_Rotate(void);

/**
 * @brief Performs the Analog to Digital Conversion Lab.
 * The top 4 MSbs of the ADC are displayed on the LEDs. Rotate the potentiometer 
 * to change the display
 * @pre SYSTEM_Initialize() functions should have been called before calling this function.
 * @param none
 * @return none
*/
void LAB_ADC(void);

/**
 * @brief Performs the Variable Speed Rotate Lab.
 * The LEDs rotate from right to left similar to Rotate Lab with varying speed.
 * Rotate the POT counterclockwise to see the LEDs shift faster.
 * @pre SYSTEM_Initialize() functions should have been called before calling this function.
 * @param none
 * @return none
*/
void LAB_VSR(void);

/**
 * @brief Performs the Pulse Width Modulation Lab.
 * Rotating the potentiometer will adjust the brightness of a single LED, LED_D7. 
 * @pre SYSTEM_Initialize() functions should have been called before calling this function.
 * @param none
 * @return none
*/
void LAB_PWM(void);

/**
 * @brief Performs the Timer1 Lab.
 * The LEDs rotate from right to left, similar to Rotate Lab, at a rate of ~0.5 seconds. 
 * @pre SYSTEM_Initialize() functions should have been called before calling this function.
 * @param none
 * @return none
*/
void LAB_Timer1(void);

/**
 * @brief Performs the Interrupt Lab.
 * The LEDs rotate at a constant speed of ~0.5s from left to right. 
 * @pre SYSTEM_Initialize() functions should have been called before calling this function.
 * @param none
 * @return none
*/
void LAB_Interrupt(void);

/**
 * @brief Performs the Sleep-Wakeup Lab.
 * LED_D4 and LED_D6 are ON while the MCU is in sleep mode. After 4 seconds, the Watchdog 
 * Timer will wake up the device from sleep then both LED_D5 and LED_D7 will turn ON, 
 * while LED_D4 and LED_D6 will turn OFF. 
 * @pre SYSTEM_Initialize() functions should have been called before calling this function.
 * @param none
 * @return none
*/
void LAB_SleepWakeUp(void);

/**
 * @brief Performs the EEPROM Lab.
 * The top 4 MSBs of the ADC is written to EEPROM. These are read 
 * afterwards and displayed on the LEDs. Rotating the potentiometer changes value of the 
 * ADC to be stored/read to/from EEPROM.  
 * @pre SYSTEM_Initialize() functions should have been called before calling this function.
 * @param none
 * @return none
*/
void LAB_EEPROM(void);

#endif	/* LABS_H */
/**
 End of File
 */
 
 
 