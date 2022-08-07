#include "headerMain.h"

// Timer function 
void *timerThread(void* x){

    while(Timer.time != -1){

        while (Timer.paused == 1){
            drawNumbers(Timer.time, 2);
        }
         
        if(Timer.paused != 1){
            Timer.time--;

            drawNumbers(Timer.time, 2);
            
            sleep(1);
        }
    }
}
