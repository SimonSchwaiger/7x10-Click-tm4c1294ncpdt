#define TARGET_IS_TM4C129_RA2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <driverlib/gpio.h>
#include <driverlib/sysctl.h>
#include <driverlib/systick.h>
#include <driverlib/pin_map.h>
#include <driverlib/rom.h>
#include <driverlib/interrupt.h>
#include <driverlib/ssi.h>
#include <driverlib/uart.h>
#include <inc/hw_memmap.h>
#include <driverlib/sysctl.h>
#include <inc/tm4c1294ncpdt.h>
#include <inc/hw_types.h>

#define F_CPU (16000000)
#define UART_BAUDRATE (9600)

#define REFRESHRATE (700)                              //refreshrate of the display in Hz

#define POSTSCALEMAX (REFRESHRATE*BRIGHTNESS_SCALE_MAX)
#define BRIGHTNESS_SCALE_MAX (10)

#define MAX_STRING_LEN (16)

uint16_t display[7]={0,0,0,0,0,0,0};                    //array for the active pix
uint8_t brightness[7]={10,10,10,10,10,10,10};           //array for the per row brighntess (0-10)

uint8_t currentcd = 0;                                  //current state of the hw counter
uint8_t brightnesscd = 0;                               //counter for the per row brightness
uint16_t postscale = 0;                                 //postscaler for various timings

uint16_t displaybuffer[7] = {0,0,0,0,0,0,0};            //buffer for scrolling text
char displaytext[MAX_STRING_LEN];                       //array for scrolling text
int8_t charcd = 0;                                      //counter for the scrolling characters

#include "7x10driver.h"
#include "7x10font.h"
#include "7x10scrollingText.h"

//Connections for 7x10 Click to Tiva-Board on BoosterPack1
/*
 *  #MR     PC7
 *  R_CLK   PE4
 *  LATCH   PH2
 *  SCK     PD3
 *  SDO     PD0
 *  SDI     PD1
 *  R_RST   PM3
 */

//Connections for the UART0 connection to the PC
/*
 *  RX   PA0
 *  TX   PA1
 */

//Input Syntax for the UART0 Connection upon startup
/*
 * 1) Text: hello world0
 *
 * 2) Brightness per Row: 10,10,10,10,10,10,10,
 */

interrupt void SystickHandler(void) //calls the display printing function and the scrolling text function periodically
{
    printDisplay();

    scrollingText();
}

void setupSysTick(void)     //sets up the systick counter
{
    uint32_t g_ui32SysClock;

    SysTickIntRegister(SystickHandler);

    SysTickIntEnable();

    g_ui32SysClock = SysCtlClockFreqSet(SYSCTL_XTAL_25MHZ | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480,25000000);

    SysTickPeriodSet(g_ui32SysClock/(REFRESHRATE*BRIGHTNESS_SCALE_MAX));

    SysTickEnable();
}

void setupSSI2(void)        //sets up ssi2
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_SSI2))
    {
    }

    GPIOPinConfigure(GPIO_PD0_SSI2XDAT1);
    GPIOPinConfigure(GPIO_PD1_SSI2XDAT0);
    GPIOPinConfigure(GPIO_PD3_SSI2CLK);

    GPIOPinTypeSSI(GPIO_PORTD_BASE,GPIO_PIN_0);
    GPIOPinTypeSSI(GPIO_PORTD_BASE,GPIO_PIN_1);
    GPIOPinTypeSSI(GPIO_PORTD_BASE,GPIO_PIN_3);

    SSIClockSourceSet(SSI2_BASE, SSI_CLOCK_SYSTEM);

    SSIConfigSetExpClk(SSI2_BASE,
    F_CPU,
    SSI_FRF_MOTO_MODE_1,
    SSI_MODE_MASTER,
    8000000,
    16);

    SSIEnable(SSI2_BASE);
}

void SetupBoosterPack1Peripherals(void) //sets up the peripherals for BoosterPack1
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);

    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_1 | GPIO_PIN_3);
    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_2);
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_7);
    GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_3);

    GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_0);
}

void setupUART0(void)    //sets up the uart0 connection to the pc
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0))
    {
    }

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    UARTClockSourceSet(UART0_BASE, UART_CLOCK_SYSTEM);

    UARTConfigSetExpClk(
    UART0_BASE,
    F_CPU,
    UART_BAUDRATE,
    (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE));
}

int main (void)
{
    //activate the Peripherals for Booster Pack 1
    SetupBoosterPack1Peripherals();

    //reset the latch pin
    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_2, (0<<2));

    //launch SPI setup
    setupSSI2();

    //reset row counter
    resetcd();

    //reset shift registers
    SSI2_DR_R=0b0000000000000000;
    resetregister();

    ROM_SysCtlDelay(F_CPU/2/3);

    //setup the UARTconnection to the PC
    setupUART0();

    //read text over the uart0 connection
    inputText();

    //read brightness over the uart0 connection
    inputBrightness();

    //launch Systick setup
    setupSysTick();

    while(1)
    {

    }

}
