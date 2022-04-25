/**
  HelloWorld Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    hello_world_lab.c

  Summary:
    This is the source file for the Hello World lab

  Description:
    This source file contains the code on how the Hello World lab works.
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

void LAB_HelloWorld(void) 
{
    if (labState == NOT_RUNNING) 
    {        
        printf("Lab 1: Hello World \r\n");
        labState = RUNNING;   
    }
    
    //Keeping the LED D4 ON as long as Lab 1 is executing
    if (labState == RUNNING)  
    {
        LED_D4_SetHigh();
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
