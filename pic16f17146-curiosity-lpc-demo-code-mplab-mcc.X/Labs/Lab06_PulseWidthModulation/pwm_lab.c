/**
  Pulse Width Modulation Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    pwm_lab.c

  Summary:
    This is the source file for the PWM lab

  Description:
    This source file contains the code on how the PWM lab works.
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
  Section: Local Function Prototypes
 */
void PWMOutputD7Enable(void);
void PWMOutputD7Disable(void);

/**
  Section: Variable Declarations
 */
static uint16_t adcResult;

void LAB_PWM(void) 
{
    if (labState == NOT_RUNNING) 
    {
        printf("Lab 6: Pulse Width Modulation \r\n");
        PWMOutputD7Enable();
        labState = RUNNING; 
    }

    //Executes below section as long as this lab is running 
    //Rotating potentiometer will adjust the brightness of LED D7.
    if (labState == RUNNING) 
    {
        adcResult = ADCC_GetSingleConversion(POT_CHANNEL);
        //Printing ADC result on Serial port
        printf("ADC Result: %d \r\n", adcResult);
        
        //Setting duty cycle of PWM with respect to ADC result
        PWM1_16BIT_SetSlice1Output1DutyCycleRegister(adcResult << 4);
        PWM1_16BIT_LoadBufferRegisters();
    }
    
    //On switch press, moving to next lab
    if (isSwitchPressed) 
    {
        TURN_OFF_ALL_LEDs();
        PWMOutputD7Disable();
        labState = NOT_RUNNING;
    }
}

void PWMOutputD7Enable(void)
{ 
    //Set D7 as the output of PWM1 
    RC5PPS = 0x0B;
}

void PWMOutputD7Disable(void) 
{
    //Restore D7 as a normal I/O pin
    RC5PPS = 0x00;
}
/**
 End of File
 */
