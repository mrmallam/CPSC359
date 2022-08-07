//  Name: Mohamed Allam
//  UCID: 30106564

//  Name: Nayera Zaghloul
//  UCID: 30123228

#include "headerMain.h"

int main()
{
    unsigned int *gpioPtr = getGPIOPtr(); // GPIO base address 
    int previousButton = -1; // Used to keep track of the previous button to avoid printing the same output  


    initializeSNES(gpioPtr);   
    Write_Clock(gpioPtr, 1);
    Write_Latch(gpioPtr, 0);

    /* initialize + get FBS */
	framebufferstruct = initFbInfo();

    /* initialize a pixel */
	Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

    initializeMainMenu();

    drawWhiteBackground();
    drawStatusBackground();
    restartToInitialState();

    initMovingObjectThreads();

    
    drawMove_Mario();
    checker.checker = 0;

    while(Menu.terminate != 1){
        while(1){ 
            drawInitialstateBlackWhite();
            checkGateCollision();
            checkCoinCollision();
            checkheartCollision();
            calculateScore();

            mario.button = readSNES(gpioPtr);
            usleep(5000);
            if(mario.button > -1){ //Button has been pressed
                break;

            } else { //Button has been released
                previousButton = -1;
            }
            
            if(level.level == 2 && checker.checker != 1){
                checker.checker = coinConstructor2();
            }
            if(level.level == 3 && checker.checker1 != 1){
                checker.checker1 = coinConstructor3();
            }
            if(level.level == 4 && checker.checker2 != 1){
                checker.checker2 = coinConstructor4();
            }
            if(level.level == 2 && checker.checker3 != 1){
                checker.checker3 = heartConstructor2();
            }
            if(level.level == 3 && checker.checker4 != 1){
                checker.checker4 = heartConstructor3();
            }
            if(level.level == 4 && checker.checker5 != 1){
                checker.checker5 = heartConstructor4();
            }

            // Check if won
            if(Status.gameWon == 1){
                draw_GameWon();
                Timer.paused = 1;
            }

            // Check if lost
            if(Status.gameOver == 1){
                draw_GameOver();
                Timer.paused = 1;
            }

            if(Timer.time == 0){
                Status.gameOver = 1;
            }
        }

        if(Menu.terminate == 1){
            printf("\nProgram is terminated. \n");
            break;
        }
        
        if(previousButton != mario.button){
            Button_Pressed();
            checkForLifes();
        }     


        previousButton = mario.button;   
    }

    /* free pixel's allocated memory */
	free(pixel);
	pixel = NULL;
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
    return 0;
}




