/* Selman Tabet (@selmantabet - https://selman.io/) - UIN 724009859
Assignment 1 - Question 1

This function transmits a message to a host PC via a USB connection
upon pressing a button on an LPC4088 board.

Tested on an EA LPC4088 QuickStart Board and a PC
running Windows 10 Pro x64 19042.746 (20H2). COM Serial driver required.
*/
#include "mbed.h"

Serial pc(USBTX, USBRX); // USB tx (Transmit), rx (Receive)
DigitalIn Button(p23); //Initialize pushbutton
int main() {
    
    Button.mode(PullUp); //Enable the pullup resistor on input
    while(1) {
        //Check if the pushbutton is pressed
        if (Button == 0) {
            pc.printf("Hello World!\n"); /*Print message to stdout for the
            host to read from the serial buffer*/
            while (!Button); //Wait until the button is released
            wait_ms(10); //Add a short delay to handle contact bounce
        }
    }
}