void writetobuffer(char text)       //takes the inputed char and writes into the global displaybuffer to be plotted as scrolling text
{
    switch (text) {
            case 'a':
                    displaybuffer[0] = 0b0000000000000100;
                    displaybuffer[1] = 0b0000000000001010;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000010001;
                    displaybuffer[4] = 0b0000000000011111;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000010001;
                    break;
            case 'b':
                    displaybuffer[0] = 0b0000000000011110;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000011110;
                    displaybuffer[4] = 0b0000000000010001;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000011110;
                    break;
            case 'c':
                    displaybuffer[0] = 0b0000000000001110;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010000;
                    displaybuffer[3] = 0b0000000000010000;
                    displaybuffer[4] = 0b0000000000010000;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000001110;
                    break;
            case 'd':
                    displaybuffer[0] = 0b0000000000011110;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000010001;
                    displaybuffer[4] = 0b0000000000010001;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000011110;
                    break;
            case 'e':
                    displaybuffer[0] = 0b0000000000011111;
                    displaybuffer[1] = 0b0000000000010000;
                    displaybuffer[2] = 0b0000000000010000;
                    displaybuffer[3] = 0b0000000000011110;
                    displaybuffer[4] = 0b0000000000010000;
                    displaybuffer[5] = 0b0000000000010000;
                    displaybuffer[6] = 0b0000000000011111;
                    break;
            case 'f':
                    displaybuffer[0] = 0b0000000000011111;
                    displaybuffer[1] = 0b0000000000010000;
                    displaybuffer[2] = 0b0000000000010000;
                    displaybuffer[3] = 0b0000000000011110;
                    displaybuffer[4] = 0b0000000000010000;
                    displaybuffer[5] = 0b0000000000010000;
                    displaybuffer[6] = 0b0000000000010000;
                    break;
            case 'g':
                    displaybuffer[0] = 0b0000000000001111;
                    displaybuffer[1] = 0b0000000000010000;
                    displaybuffer[2] = 0b0000000000010000;
                    displaybuffer[3] = 0b0000000000010000;
                    displaybuffer[4] = 0b0000000000010011;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000001111;
                    break;
            case 'h':
                    displaybuffer[0] = 0b0000000000010001;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000011111;
                    displaybuffer[4] = 0b0000000000010001;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000010001;
                    break;
            case 'i':
                    displaybuffer[0] = 0b0000000000001110;
                    displaybuffer[1] = 0b0000000000000100;
                    displaybuffer[2] = 0b0000000000000100;
                    displaybuffer[3] = 0b0000000000000100;
                    displaybuffer[4] = 0b0000000000000100;
                    displaybuffer[5] = 0b0000000000000100;
                    displaybuffer[6] = 0b0000000000001110;
                    break;
            case 'j':
                    displaybuffer[0] = 0b0000000000000001;
                    displaybuffer[1] = 0b0000000000000001;
                    displaybuffer[2] = 0b0000000000000001;
                    displaybuffer[3] = 0b0000000000000001;
                    displaybuffer[4] = 0b0000000000000001;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000001110;
                    break;
            case 'k':
                    displaybuffer[0] = 0b0000000000010001;
                    displaybuffer[1] = 0b0000000000010010;
                    displaybuffer[2] = 0b0000000000010100;
                    displaybuffer[3] = 0b0000000000011000;
                    displaybuffer[4] = 0b0000000000010100;
                    displaybuffer[5] = 0b0000000000010010;
                    displaybuffer[6] = 0b0000000000010001;
                    break;
            case 'l':
                    displaybuffer[0] = 0b0000000000010000;
                    displaybuffer[1] = 0b0000000000010000;
                    displaybuffer[2] = 0b0000000000010000;
                    displaybuffer[3] = 0b0000000000010000;
                    displaybuffer[4] = 0b0000000000010000;
                    displaybuffer[5] = 0b0000000000010000;
                    displaybuffer[6] = 0b0000000000011111;
                    break;
            case 'm':
                    displaybuffer[0] = 0b0000000000010001;
                    displaybuffer[1] = 0b0000000000011011;
                    displaybuffer[2] = 0b0000000000010101;
                    displaybuffer[3] = 0b0000000000010101;
                    displaybuffer[4] = 0b0000000000010001;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000010001;
                    break;
            case 'n':
                    displaybuffer[0] = 0b0000000000010001;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000011001;
                    displaybuffer[3] = 0b0000000000010101;
                    displaybuffer[4] = 0b0000000000010011;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000010001;
                    break;
            case 'o':
                    displaybuffer[0] = 0b0000000000001110;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000010001;
                    displaybuffer[4] = 0b0000000000010001;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000001110;
                    break;
            case 'p':
                    displaybuffer[0] = 0b0000000000011110;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000010001;
                    displaybuffer[4] = 0b0000000000011110;
                    displaybuffer[5] = 0b0000000000010000;
                    displaybuffer[6] = 0b0000000000010000;
                    break;
            case 'q':
                    displaybuffer[0] = 0b0000000000001110;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000010001;
                    displaybuffer[4] = 0b0000000000010101;
                    displaybuffer[5] = 0b0000000000010010;
                    displaybuffer[6] = 0b0000000000001101;
                    break;
            case 'r':
                    displaybuffer[0] = 0b0000000000011110;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000011110;
                    displaybuffer[4] = 0b0000000000010100;
                    displaybuffer[5] = 0b0000000000010010;
                    displaybuffer[6] = 0b0000000000010001;
                    break;
            case 's':
                    displaybuffer[0] = 0b0000000000001110;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010000;
                    displaybuffer[3] = 0b0000000000001110;
                    displaybuffer[4] = 0b0000000000000001;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000001110;
                    break;
            case 't':
                    displaybuffer[0] = 0b0000000000011111;
                    displaybuffer[1] = 0b0000000000000100;
                    displaybuffer[2] = 0b0000000000000100;
                    displaybuffer[3] = 0b0000000000000100;
                    displaybuffer[4] = 0b0000000000000100;
                    displaybuffer[5] = 0b0000000000000100;
                    displaybuffer[6] = 0b0000000000000100;
                    break;
            case 'u':
                    displaybuffer[0] = 0b0000000000010001;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000010001;
                    displaybuffer[4] = 0b0000000000010001;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000001110;
                    break;
            case 'v':
                    displaybuffer[0] = 0b0000000000010001;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000010001;
                    displaybuffer[4] = 0b0000000000010001;
                    displaybuffer[5] = 0b0000000000001010;
                    displaybuffer[6] = 0b0000000000000100;
                    break;
            case 'w':
                    displaybuffer[0] = 0b0000000000010001;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000010001;
                    displaybuffer[3] = 0b0000000000010001;
                    displaybuffer[4] = 0b0000000000010101;
                    displaybuffer[5] = 0b0000000000011011;
                    displaybuffer[6] = 0b0000000000010001;
                    break;
            case 'x':
                    displaybuffer[0] = 0b0000000000010001;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000001010;
                    displaybuffer[3] = 0b0000000000000100;
                    displaybuffer[4] = 0b0000000000001010;
                    displaybuffer[5] = 0b0000000000010001;
                    displaybuffer[6] = 0b0000000000010001;
                    break;
            case 'y':
                    displaybuffer[0] = 0b0000000000010001;
                    displaybuffer[1] = 0b0000000000010001;
                    displaybuffer[2] = 0b0000000000001110;
                    displaybuffer[3] = 0b0000000000000100;
                    displaybuffer[4] = 0b0000000000000100;
                    displaybuffer[5] = 0b0000000000000100;
                    displaybuffer[6] = 0b0000000000000100;
                    break;
            case 'z':
                    displaybuffer[0] = 0b0000000000011111;
                    displaybuffer[1] = 0b0000000000000001;
                    displaybuffer[2] = 0b0000000000000010;
                    displaybuffer[3] = 0b0000000000000100;
                    displaybuffer[4] = 0b0000000000001000;
                    displaybuffer[5] = 0b0000000000010000;
                    displaybuffer[6] = 0b0000000000011111;
                    break;
            case '1':
                    displaybuffer[0] = 0b0000000000011111;
                    displaybuffer[1] = 0b0000000000011111;
                    displaybuffer[2] = 0b0000000000011111;
                    displaybuffer[3] = 0b0000000000011111;
                    displaybuffer[4] = 0b0000000000011111;
                    displaybuffer[5] = 0b0000000000011111;
                    displaybuffer[6] = 0b0000000000011111;
                    break;
            default:
                    displaybuffer[0] = 0b0000000000000000;
                    displaybuffer[1] = 0b0000000000000000;
                    displaybuffer[2] = 0b0000000000000000;
                    displaybuffer[3] = 0b0000000000000000;
                    displaybuffer[4] = 0b0000000000000000;
                    displaybuffer[5] = 0b0000000000000000;
                    displaybuffer[6] = 0b0000000000000000;
                    break;
        }
}
