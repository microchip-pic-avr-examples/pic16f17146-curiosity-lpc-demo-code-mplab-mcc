/**
  Interrupt Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    interrupt_lab.c

  Summary:
    This is the source file for the Interrupt lab

  Description:
    This source file contains the code on how the Interrupt lab works.
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

/**
  Section: Included Files
 */
#include "../../mcc_generated_files/system/system.h"
#include "../../labs.h"

#define ROTATE_REGISTER_VALUE_FOR_LAST_LED  (0x10)

/**
 * @brief Timer0 user ISR
 * @param none
 * @return none
*/
void LAB_ISR(void);

/**
  Section: Local Variable Declarations
 */
static uint8_t rotateRegister;

void LAB_Interrupt(void) 
{

    if (labState == NOT_RUNNING) 
    {  
       printf("Lab 8: Interrupts \r\n");
        
        //Initialize temporary register to begin at 8
        rotateRegister = ROTATE_REGISTER_VALUE_FOR_LAST_LED >> 1;
       
        //Set User defined Interrupt Handler for Timer0
        Timer0.TimeoutCallbackRegister(LAB_ISR);
        
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        INTERRUPT_TMR0InterruptEnable();
        Timer0.Start();
        labState = RUNNING;
    }

    if(labState == RUNNING)
    { 
        //Do nothing. Just wait for an interrupt event 
    }
    
    //On switch press, moving to next lab
    if (isSwitchPressed)
    {
        TURN_OFF_ALL_LEDs();
        INTERRUPT_TMR0InterruptDisable();
        INTERRUPT_GlobalInterruptDisable();
        INTERRUPT_PeripheralInterruptDisable();
        Timer0.Stop();
        labState = NOT_RUNNING;
    }
}

void LAB_ISR(void) 
{    
    //Determine which LED should be lit. LED's D7-D4 rotate from left to right
    LED_D4_LAT = rotateRegister & 1;
    LED_D5_LAT = (rotateRegister & 2) >> 1;
    LED_D6_LAT = (rotateRegister & 4) >> 2;
    LED_D7_LAT = (rotateRegister & 8) >> 3;
    
    rotateRegister >>= 1;
    
    //Return to initial position of LED (D7) if the last LED D4 is lit up, repeat the pattern 
    if (rotateRegister == 0)
    {
        rotateRegister = ROTATE_REGISTER_VALUE_FOR_LAST_LED >> 1;
    }   
}
/**
 End of File
 */
