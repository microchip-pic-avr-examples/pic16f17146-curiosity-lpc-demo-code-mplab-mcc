/**
  Analog-to-Digital Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    adc)lab.c

  Summary:
    This is the source file for the ADC lab

  Description:
    This source file contains the code on how the ADC lab works.
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

/**
  Section: Variable Declaration
 */
static uint8_t adcResult; // Used to store the result of the ADC


void LAB_ADC(void) 
{
    if (labState == NOT_RUNNING) 
    {
        printf("Lab 4: Analog To Digital Conversion \r\n");
        labState = RUNNING;   
    }

    //Executing ADC conversion and printing results until this lab is running
    //Rotating potentiometer helps to change analog input and eventually ADC result
    if (labState == RUNNING)
    {
        //Get the top 4 MSBs and display it on the LEDs
        adcResult = ADCC_GetSingleConversion(POT_CHANNEL) >> 8;

        //Printing ADC result on Serial port
        printf("ADC Result: %d \r\n", ADRES);
        
        //Determine which LEDs will light up
        LED_D4_LAT = adcResult & 1;
        LED_D5_LAT = (adcResult & 2) >> 1;
        LED_D6_LAT = (adcResult & 4) >> 2;
        LED_D7_LAT = (adcResult & 8) >> 3;
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
