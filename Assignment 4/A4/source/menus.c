#include "headerMain.h"
// --------------------------- Menus ---------------------------
/*
    this file handles Main menu and Mid-game menu functions
*/

void displayMidMenu(){

    short int *midMenuResume =(short int *) midMenuResume_image.image_pixels;
    short int *midMenuQuit =(short int *) midMenuExit.image_pixels;

    if(Menu.up == 1){
        Pixel *pixel;
        pixel = malloc(sizeof(Pixel));

        int i = 0;
        for (int y = 239; y < 239 + 591; y++)//30 is the image height
        {
            for (int x = 492; x < 492 + 787; x++) // 30 is image width
            {	
                pixel->color = midMenuResume[i];
                pixel->x = x;
                pixel->y = y;

                drawPixel(pixel);
                i++;
            }
        }
        free(pixel);
        pixel = NULL;
    }

    if(Menu.down == 1){
        Pixel *pixel;
        pixel = malloc(sizeof(Pixel));

        int i = 0;
        for (int y = 239; y < 239 + 591; y++)//30 is the image height
        {
            for (int x = 492; x < 492 + 787; x++) // 30 is image width
            {	
                pixel->color = midMenuQuit[i];
                pixel->x = x;
                pixel->y = y;

                drawPixel(pixel);
                i++;
            }
        }
        free(pixel);
        pixel = NULL;
    }
}


void initializeMainMenu(){
    int previousButton = -1;
    int button = -1;
    unsigned int *gpioPtr = getGPIOPtr();

    short int *mainMenuResume =(short int *) mainMenuPlay.image_pixels;
    short int *mainMenuQuit =(short int *) mainMenuExit_image.image_pixels;
    drawMainMenu(mainMenuResume);
    Menu.up = 1;
    while(1){
        while(1){
            button = readSNES(gpioPtr);
            if(button > -1){ //Button has been pressed
                break;

            } else { //Button has been released
                previousButton = -1;
            }
        }

        if(previousButton != button){
            // UP
            if(button == 5){
                drawMainMenu(mainMenuResume);
                if(Menu.down == 1){
                    Menu.down = 0;
                }
                Menu.up = 1;
                
            }
            // DOWN
            else if(button == 6){
                drawMainMenu(mainMenuQuit);
                if(Menu.up == 1){
                    Menu.up = 0;
                }
                Menu.down = 1;
                
            }
            // A
            else if(button == 9){
                if(Menu.down == 1){
                    Menu.terminate = 1;
                    break;
                }
                if(Menu.up == 1){
                    break;
                }
            }
        }     

        previousButton = button;
    }
}

void drawMainMenu(short int *image){
    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));

    int i = 0;
    for (int y = 0; y < 1080; y++)//30 is the image height
    {
        for (int x = 0; x < 1920; x++) // 30 is image width
        {	
            pixel->color = image[i];
            pixel->x = x;
            pixel->y = y;

            drawPixel(pixel);
            i++;
        }
    }
    free(pixel);
    pixel = NULL;
}