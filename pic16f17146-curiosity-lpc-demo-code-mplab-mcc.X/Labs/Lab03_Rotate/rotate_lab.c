/**
  Rotate Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    rotate_lab.c

  Summary:
    This is the source file for the Rotate lab

  Description:
    This source file contains the code on how the Rotate lab works.
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
  Section: Variable Declarations
 */
static uint8_t rotateRegister;


void LAB_Rotate(void) 
{
    if (labState == NOT_RUNNING) 
    {
        printf("Lab 3: Rotate \r\n");      
        //Initialize temporary register to begin at 1
        rotateRegister = 1;
        labState = RUNNING;     
    }
    
    //Rotate lighting up LED's D4,D5,D6 and D7 in pattern until Lab 3 is running
    if (labState == RUNNING) 
    {
        //Determine which LED will light up
        //ie. which bit in the register rotateRegister , the 1 has rotated to.
        
        LED_D4_LAT = rotateRegister & 1;
        LED_D5_LAT = (rotateRegister & 2) >> 1;
        LED_D6_LAT = (rotateRegister & 4) >> 2;
        LED_D7_LAT = (rotateRegister & 8) >> 3;
        
        rotateRegister <<= 1;
        //If the last LED (D7) has been lit, restart the pattern from D4
        if (rotateRegister == ROTATE_REGISTER_VALUE_FOR_LAST_LED)
        {
            rotateRegister = 1;
        }      
     
        __delay_ms(500);      
    }
    
    //On switch press, moving to next lab
    if (isSwitchPressed) 
    {
        TURN_OFF_ALL_LEDs();
        labState = NOT_RUNNING;
    }
}

/**
 End of File
 */
