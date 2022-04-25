/**
  EEPROM Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    eeprom_lab.c

  Summary:
    This is the source file for the EEPROM lab

  Description:
    This source file contains the code on how the EEPROM lab works.
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
  Section: Macro Declaration
 */
#define EEPROM_ADDRESS (0x7000U)

/**
  Section: Variable Declarations
 */
static uint8_t adcResult;
static uint8_t ledDisplay;

void LAB_EEPROM(void)
{
    if (labState == NOT_RUNNING)
    {
       printf("Lab 10: EEPROM \r\n");
       labState = RUNNING;      
    }
    
    //The 4 MSB's of ADC result, controlled by potentiometer is written to EEPROM 
    //which is read back and displayed on LED's D4,D5,D6 ad D7.
    //Executes below section as long as this lab is running   
    if (labState == RUNNING) 
    {  
        //Get the top 4 MSBs of the ADC and write them to EEPROM
        adcResult = (uint8_t)(ADCC_GetSingleConversion(POT_CHANNEL) >> 8);
        NVM_UnlockKeySet(UNLOCK_KEY);
        EEPROM_Write(EEPROM_ADDRESS, adcResult);
        while(NVM_IsBusy());
        NVM_UnlockKeyClear();
        
        //Printing ADC result on Serial port
        printf("ADC Result: %d \r\n", ADRES);

        //Load whatever is in EEPROM to the LED Display
        ledDisplay = EEPROM_Read(EEPROM_ADDRESS);

        //Determine which LEDs will light up
        LED_D4_LAT = ledDisplay & 1;
        LED_D5_LAT = (ledDisplay & 2) >> 1;
        LED_D6_LAT = (ledDisplay & 4) >> 2;
        LED_D7_LAT = (ledDisplay & 8) >> 3;
    }

    //On switch press, moving to next lab, Lab 1
    if (isSwitchPressed) 
    {
        TURN_OFF_ALL_LEDs();
        labState = NOT_RUNNING;
    }
}
/*
 End of File
 */
