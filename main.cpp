/*  Binary Counter Template
*  
*   Operate multiple LED outputs. Use code to implement a 4-bit binary counter 
*
*   Board: NUCLEO L476RG
*   Author: Dr James H. Chandler, University of Leeds 2021  
*/

#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     1000ms

//define output pins
DigitalOut led1(PC_0);      // Create DigitalOut Object called led1 and assign pin PC_0
DigitalOut led2(PC_1);

int val = 0;                // Create variable for use in the for loop

void init_leds();           // Declare led initialisation function 
int led1_check(int val);    // Declare led1 check function 
int led2_check(int val);    // Declare led2 check function


int main()
{
init_leds();

    while (true) {
        
        for(val=0; val<=15; val++){

            led1.write(led1_check(val));            // Call led1 check logic function
            led2.write(led2_check(val));            // Call led2 check logic function
            
            ThisThread::sleep_for(BLINKING_RATE);   // Sleep for specified duration
        }
                
    }
}

void init_leds(){
    led1 = 0;
    led2 = 0;
}


int led1_check(int i){
    if((i+1)%2 == 0){return 1;}
    else {return 0;}
};

int led2_check(int i){
    if(i == 2 || i == 3 || i == 6 || i == 7 || i == 10 || i == 11 ||i >= 14){return 1;}
    else {return 0;}
};