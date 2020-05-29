void writeBuffer(void)      //plots the next column of pixels from the displaybuffer onto the display
{
    int i = 0;

    while (i<7)
    {
        display[i] |= (displaybuffer[i]<<6) & 0b0000010000000000;
        displaybuffer[i] = (displaybuffer[i]<<1);
        i++;
    }
}

void advanceDisplay(void)   //scrolls the display to the left by one pixel
{
    int i = 0;

    while (i<7)
    {
        display[i] = (display[i]>>1);
        i++;
    }

}

void scrollingText(void)    //periodically shifts the text left and plots the characters from the displaytext array
{
    if (postscale<POSTSCALEMAX)
        {
            postscale++;
        }

    if (postscale>=POSTSCALEMAX)
    {
        if ((!(charcd%6))|charcd==0) writetobuffer(displaytext[charcd/6]);

        writeBuffer();
        advanceDisplay();

        charcd++;

        if (displaytext[charcd/6]=='0') charcd = -7;

        postscale = 0;
    }
}

void inputText(void)  //reads text from the uart0 connection either until there is a space or the max string length is written
{
    int i = 0;

    while (i<MAX_STRING_LEN)
    {
        displaytext[i] = UARTCharGet(UART0_BASE);
        if (displaytext[i]=='0')    i = MAX_STRING_LEN;
        i++;
    }
}

void inputBrightness(void)  //reads text from the uart0 connection for each of the 7 rows
{
    int i = 0;
    int j = 0;
    char buffer[MAX_STRING_LEN];
    char *ptr;
    long returnbuffer = 0;

    while (i<7)
    {
        j=0;
        while (j<MAX_STRING_LEN)
        {
            buffer[j] = UARTCharGet(UART0_BASE);
            if (buffer[j]==',')
                {
                    j = MAX_STRING_LEN;
                    returnbuffer = strtol(buffer,&ptr, 10);
                    if (returnbuffer<=BRIGHTNESS_SCALE_MAX) brightness[i] = returnbuffer;
                    else brightness[i] = BRIGHTNESS_SCALE_MAX;
                }
            j++;
        }
        i++;
    }

}
