#include "headerMain.h"

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
