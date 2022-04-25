/**
  Timer1 Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    timer1_lab.c

  Summary:
    This is the source file for the Timer1 lab

  Description:
    This source file contains the code on how the Timer1 lab works.
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

void LAB_Timer1(void) 
{
    if (labState == NOT_RUNNING) 
    {
        printf("Lab 7: Timers \r\n");

        //Initialize temporary register to begin at 1
        rotateRegister = 1;

        Timer1.Start();

        labState = RUNNING;      
    }

    //Executing below section as long as Lab 7 is running
    //Timer1 used to create 500ms delay between LED light up
    if (labState == RUNNING) 
    {     
        //Determine which LED will light up
        LED_D4_LAT = rotateRegister & 1;
        LED_D5_LAT = (rotateRegister & 2) >> 1;
        LED_D6_LAT = (rotateRegister & 4) >> 2;
        LED_D7_LAT = (rotateRegister & 8) >> 3;
        
        rotateRegister <<= 1;

        //Return to initial position of LED (D4) if the last LED (D7) is lit up
        if (rotateRegister == ROTATE_REGISTER_VALUE_FOR_LAST_LED)
        {
            rotateRegister = 1;
        }
        
        while(!Timer1_HasOverflowOccured());       
        TMR1IF = 0;                
        Timer1_Reload(); 
    }
    
    //On switch press, moving to next lab
    if (isSwitchPressed) 
    {
        TURN_OFF_ALL_LEDs();
        Timer1.Stop();
        labState = NOT_RUNNING;
    }
}
/**
 End of File
 */
