//  Name: Nayera Zaghloul
//  UCID: 30123228

//  Name: Mohamed Allam
//  UCID: 30106564

// CPSC 359 - Assignment 3


#include <unistd.h>
#include <stdio.h>
#include <wiringPi.h>
#include "initGPIO.h"


#define LAT  9  // Latch Line
#define DAT  10 // Data Line
#define CLK  11 // Clock Line

#define GPSET0 7    // SET
#define GPCLR0 10   // CLEAR
#define GPLEV0 13   // READ

#define INP_GPIO(g) *(gpioPtr+((g)/10)) &= ~(7<<(((g)%10)*3)); // Setting pin to Input 
#define OUT_GPIO(g) *(gpioPtr+((g)/10)) |= (1<<(((g)%10)*3)); // Setting pin to Output


// Initializing functions
void initializeSNES(unsigned int *gpioPtr);
void Write_Clock(unsigned int *gpioPtr, int value);
void Write_Latch(unsigned int *gpioPtr, int value);
int readSNES(unsigned int *gpioPtr);
void display_Button_Pressed(int button);

// Initializing SNES lines
void initializeSNES(unsigned int *gpioPtr){
    INP_GPIO( CLK );
    OUT_GPIO( CLK );
    INP_GPIO( LAT );
    OUT_GPIO( LAT );
    INP_GPIO( DAT );
}

// Writing to clock
void Write_Clock(unsigned int *gpioPtr, int value){
    if(value == 0){
        gpioPtr[GPCLR0] = 1<<CLK;

    }else if(value == 1){
        gpioPtr[GPSET0] = 1<<CLK;
    }
}

// Writing to latch
void Write_Latch(unsigned int *gpioPtr, int value){
    if(value == 0){
        gpioPtr[GPCLR0] = 1<<LAT;

    }else if(value == 1){
        gpioPtr[GPSET0] = 1<<LAT;
    }
}

// Reading SNES input
int readSNES(unsigned int *gpioPtr){
    int pinValue;

    Write_Clock(gpioPtr, 1);
    Write_Latch(gpioPtr, 1);
    delayMicroseconds(12);
    Write_Latch(gpioPtr, 0);

    for(int i = 1; i<=16; i++){
        delayMicroseconds(6);
        Write_Clock(gpioPtr, 0);
        delayMicroseconds(6);

        pinValue = (gpioPtr[GPLEV0] >> DAT) & 1; // Reading from pin

        if(pinValue == 0){
            Write_Clock(gpioPtr, 1);
            return i;
        }

        Write_Clock(gpioPtr, 1);
    }

    return -1;
}

// Displaying the button pressed
void display_Button_Pressed(int button){
    if(button == 1){
        printf("\nYou have pressed B\n\nPlease press a button...\n");
    }
    else if(button == 2){
        printf("\nYou have pressed Y\n\nPlease press a button...\n");
    }
    else if(button == 3){
        printf("\nYou have pressed Select\n\nPlease press a button...\n");
    }
    else if(button == 4){
        printf("\nYou have pressed Start\n");
    }
    else if(button == 5){
        printf("\nYou have pressed Joy-pad UP\n\nPlease press a button...\n");
    }
    else if(button == 6){
        printf("\nYou have pressed Joy-pad DOWN\n\nPlease press a button...\n");
    }
    else if(button == 7){
        printf("\nYou have pressed Joy-pad LEFT\n\nPlease press a button...\n");
    }
    else if(button == 8){
        printf("\nYou have pressed Joy-pad RIGHT\n\nPlease press a button...\n");
    }
    else if(button == 9){
        printf("\nYou have pressed A\n\nPlease press a button...\n");
    }
    else if(button == 10){
        printf("\nYou have pressed X\n\nPlease press a button...\n");
    }
    else if(button == 11){
        printf("\nYou have pressed Left\n\nPlease press a button...\n");
    }
    else if(button == 12){
        printf("\nYou have pressed Right\n\nPlease press a button...\n");
    }
}


int main()
{
    unsigned int *gpioPtr = getGPIOPtr(); // GPIO base address 
    int button = -1;
    int previousButton = -1; // Used to keep track of the previous button to avoid printing the same output  
    
    initializeSNES(gpioPtr);   

    Write_Clock(gpioPtr, 1);
    Write_Latch(gpioPtr, 0);

    printf("Created by: Mohamed Allam and Nayera Zaghloul\n\nPlease press a button...\n");

    while(1){
        while(1){ 
            button = readSNES(gpioPtr);

            if(button > -1){ //Button has been pressed
                break;

            } else { //Button has been released
                previousButton = -1;
            }
        }

        if(button == 4){
            printf("\nProgram is terminating...\n");
            break;
        }

        if(previousButton != button){
            display_Button_Pressed(button);
        }     

        previousButton = button;
    }
    return 0;
}
