void resetcd(void)  //reset the hardware counter and the its internal variable
{
    GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_3, (1<<3));
    ROM_SysCtlDelay(1);
    GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_3, (0<<3));
    currentcd=0;
}

void pingcd(void)   //increments the the hardware counter and resets it in case of an overflow
{
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, (1<<4));
    ROM_SysCtlDelay(1);
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, (0<<4));
    if (currentcd<7)    currentcd++;
    if (currentcd>=7)   resetcd();
}

void pinglatch(void)    //transfer the state of the shift register to the storage register
{
    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_2, (1<<2));
    ROM_SysCtlDelay(1);
    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_2, (0<<2));
}

void resetregister(void)    //reset shift registers and transfer the reset to the storage registers
{
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, (0<<7));
    pinglatch();
}

void setregister(void)      //set the not mr pin in order to enable the shift registers
{
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, (1<<7));
    ROM_SysCtlDelay(1);
}

void writeROW(uint16_t col)     //send the active pixels for one row through ssi2 and apply it to the storage registers
{
    setregister();

    uint16_t data = 0b0000000000000000;
    if (col&(1<<0)) data|=0b0000000000000010;               //encode the pix into ssi data:   |x|x|col10|col9|col8|col7|col6|x|x|x|col5|col4|col3|col2|col1|x|
    if (col&(1<<1)) data|=0b0000000000000100;
    if (col&(1<<2)) data|=0b0000000000001000;
    if (col&(1<<3)) data|=0b0000000000010000;
    if (col&(1<<4)) data|=0b0000000000100000;

    if (col&(1<<5)) data|=0b0000001000000000;
    if (col&(1<<6)) data|=0b0000010000000000;
    if (col&(1<<7)) data|=0b0000100000000000;
    if (col&(1<<8)) data|=0b0001000000000000;
    if (col&(1<<9)) data|=0b0010000000000000;

    SSI2_DR_R=data;
    pinglatch();
}

void printDisplay(void)     //function that periodically plots each line from the global "display[7]" array and controls the brightness
{
    resetregister();                                                    //reset the storage register each cycle

    if (brightnesscd>=BRIGHTNESS_SCALE_MAX)    brightnesscd=0;          //check for end of duty cycle

    pingcd();                                                           //increment the row counter

    if(currentcd==0)    brightnesscd++;                                 //synchronize start of the duty cycle

    if((brightnesscd<=brightness[currentcd]))                           //if duty cycle is active and row needs to be rendered, plot the respective row
        {
        writeROW(display[currentcd]);                                   //prints the display
        }
    else
        {
        resetregister();
        }
}

void cleardisplay(void)     //clears the display and all associated variables
{
    display[0] = 0b0000000000000000;
    display[1] = 0b0000000000000000;
    display[2] = 0b0000000000000000;
    display[3] = 0b0000000000000000;
    display[4] = 0b0000000000000000;
    display[5] = 0b0000000000000000;
    display[6] = 0b0000000000000000;

    charcd = 0;
}
