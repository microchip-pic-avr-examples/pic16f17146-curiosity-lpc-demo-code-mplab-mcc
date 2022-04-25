 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
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
#include "mcc_generated_files/system/system.h"
#include "labs.h"

/**
 * @enum Lab_State_t
 * @brief Enumeration for Lab number.
*/
typedef enum {
    RESET_LAB_STATE = 0,  
    HELLO_WORLD_LAB_STATE,
    BLINK_LAB_STATE,
    ROTATE_LAB_STATE,
    ADC_LAB_STATE,
    VSR_LAB_STATE,
    PWM_LAB_STATE,
    TIMER1_LAB_STATE,
    INTERRUPT_LAB_STATE,
    SLEEP_WAKE_UP_LAB_STATE,
    EEPROM_LAB_STATE,
    MAX_LIMIT_LAB_STATE
} Lab_State_t;

/**
 * @brief This function checks the switch state, whether it is pressed.
 * The switch debounce is tackled by adding delay of 100ms when switch is pressed.
 * Once switch is pressed , on switch release switchEvent becomes 1 
 * which indicates MCU that one switch press has occurred
 * @param none
 * @return none
*/
void checkButtonS1(void);

/**
 * @brief This function increments the Lab number count on each switch event.
 * @param none
 * @return none
*/
void nextLab(void);

Lab_State_t currentLabState = RESET_LAB_STATE;  // After reset no labs will be running unless switch is pressed 
bool isSwitchPressed = false;
uint8_t labState = NOT_RUNNING;
uint8_t btnState = NOT_PRESSED; 

/**
    Main application
*/
int main(void)
{
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 
    
    // Disable the pre-enabled interrupts of the MCC    
    INTERRUPT_TMR0InterruptDisable();
      
    printf("Curiosity Labs PIC16F17146 \r\n");

    while(1)
    {
        checkButtonS1();
        switch (currentLabState) 
        {
            case HELLO_WORLD_LAB_STATE: LAB_HelloWorld();
                break;
            case BLINK_LAB_STATE: LAB_Blink();
                break;
            case ROTATE_LAB_STATE: LAB_Rotate();
                break;
            case ADC_LAB_STATE: LAB_ADC();
                break;
            case VSR_LAB_STATE: LAB_VSR();
                break;
            case PWM_LAB_STATE: LAB_PWM();
                break;
            case TIMER1_LAB_STATE: LAB_Timer1();
                break;
            case INTERRUPT_LAB_STATE: LAB_Interrupt();
                break;
            case SLEEP_WAKE_UP_LAB_STATE: LAB_SleepWakeUp();
                break;
            case EEPROM_LAB_STATE: LAB_EEPROM();
                break;              
            default: 
                break;
        }

        if (isSwitchPressed) 
        {
            nextLab();
        }
    }    
}

void checkButtonS1(void)
{
    if (btnState == NOT_PRESSED) 
    {
        if (SWITCH_S1_PORT == LOW) 
        {
            __delay_ms(100);
            btnState = PRESSED;
        }
    }
    else if (SWITCH_S1_PORT == HIGH)
    {
        btnState = NOT_PRESSED;
        isSwitchPressed = true;
    }
}

void nextLab(void) 
{
    isSwitchPressed = false;
    currentLabState++;

    if (currentLabState >= MAX_LIMIT_LAB_STATE) 
    {
        currentLabState = HELLO_WORLD_LAB_STATE; //Start from first lab again
    }
}

/**
 End of File
 */