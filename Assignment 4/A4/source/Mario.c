#include "headerMain.h"

// --------------------------- MARIO ---------------------------

void drawMove_Mario(){
    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));

    short int *right_mario=(short int *) MarioRight.image_pixels;
    short int *left_mario=(short int *) MarioLeft.image_pixels;
    short int *upDown_mario=(short int *) MarioUpDown.image_pixels;

    if(mario.button == -1){
        int i = 0;
        for (int y = mario.y; y < mario.y + mario.height; y++){
            for (int x = mario.x; x < mario.x + mario.width; x++){	
                pixel->color = upDown_mario[i]; 
                pixel->x = x;
                pixel->y = y;
                drawPixel(pixel);
                i++;           
            }
        }
    }

    if(mario.button == 8){ // RIGHT

        int i = 0;
        for (int y = mario.y; y < mario.y + mario.height; y++){
            for (int x = mario.x; x < mario.x + mario.width; x++){	
                pixel->color = right_mario[i]; 
                pixel->x = x;
                pixel->y = y;
                drawPixel(pixel);
                i++;           
            }
        }
        
    }else if(mario.button == 7){ // LEFT
        int i = 0;
        for (int y = mario.y; y < mario.y + mario.height; y++){
            for (int x = mario.x; x < mario.x + mario.width; x++){	
                pixel->color = left_mario[i]; 
                pixel->x = x;
                pixel->y = y;
                drawPixel(pixel);
                i++;           
            }
        }
    }else if(mario.button == 5 || mario.button == 6){ // UP or DOWN
        int i = 0;
        for (int y = mario.y; y < mario.y + mario.height; y++){
            for (int x = mario.x; x < mario.x + mario.width; x++){	
                pixel->color = upDown_mario[i]; 
                pixel->x = x;
                pixel->y = y;
                drawPixel(pixel);
                i++;           
            }
        }
    }

    free(pixel);
    pixel = NULL;
}




