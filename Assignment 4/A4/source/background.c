#include "headerMain.h"

// --------------------------- BACKGROUND ---------------------------
/*
    handles background related functions
*/
void drawPixel(Pixel *pixel){
	long int location = (pixel->x +framebufferstruct.xOff) * (framebufferstruct.bits/8) +
                       (pixel->y+framebufferstruct.yOff) * framebufferstruct.lineLength;
	*((unsigned short int*)(framebufferstruct.fptr + location)) = pixel->color;
}

void drawWhiteBackground(){
    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));

    int i = 0;
    for (int y = 0; y < 1080; y++)//30 is the image height
	{
		for (int x = 0; x < 1920; x++) // 30 is image width
		{	
            pixel->color = 0xFFFF;
            pixel->x = x;
            pixel->y = y;

            drawPixel(pixel);
            i++;
		}
	}
    free(pixel);
    pixel = NULL;
}

void drawStatusBackground(){
    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));
    int i = 0;
    for (int y = 0; y < 1080; y++){
        for (int x = 1600; x <  1920; x++){	
            pixel->color = 0xF800; 
            pixel->x = x;
            pixel->y = y;
            drawPixel(pixel);
            i++;           
        }
    }
    free(pixel);
    pixel = NULL;
}
void drawInitialstateBlackWhite(){
    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));
    short int *blackWhite=(short int *) BW.image_pixels;
    int i = 0;
    for (int y = 1020; y <1020 + 60; y++){
        for (int x = 0; x <  1600; x++){	
            pixel->color = blackWhite[i]; 
            pixel->x = x;
            pixel->y = y;
            drawPixel(pixel);
            i++;           
        }
    }
    free(pixel);
    pixel = NULL;
}

void drawPreviousBackground_RocketBadguy(Object *myObject){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

    int i = 0;
    for (int y = myObject->y; y < myObject->y + myObject->height; y++){
        for (int x = myObject->x; x < myObject->x+ myObject-> width; x++){	
            pixel->color = 0xFFFF; 
            pixel->x = x;
            pixel->y = y;
            drawPixel(pixel);
            i++;           
        }
    }
    free(pixel);
	pixel = NULL;
}



// redraws mario's previous location to match the background 
void drawPreviousBackground_Mario(){
    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));

    int i = 0;
    for (int y = mario.y; y < mario.y + mario.height; y++){
        for (int x = mario.x; x < mario.x + mario.width; x++){	
            pixel->color = 0xFFFF; 
            pixel->x = x;
            pixel->y = y;
            drawPixel(pixel);
            i++;           
        }
    }

    free(pixel);
    pixel = NULL;
}



void draw_GameOver(){
    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));
    short int *gameOver=(short int *) gameOver_image.image_pixels;
    short int *cryingMarioLeft=(short int *) cryingMario_image.image_pixels;
    short int *cryingMarioRight=(short int *) cryingMarioRight_image.image_pixels;
    int i = 0;
    for (int y = 270; y <270 + 540; y++){
        for (int x = 400; x < 400+ 800; x++){	
            pixel->color = gameOver[i]; 
            pixel->x = x;
            pixel->y = y;
            drawPixel(pixel);
            i++;           
        }
    }
    i = 0;
    for (int y = 270; y <270 + 540; y++){
        for (int x = 0; x <  311; x++){	
            pixel->color = cryingMarioLeft[i]; 
            pixel->x = x;
            pixel->y = y;
            drawPixel(pixel);
            i++;           
        }
    }
    i = 0;
    for (int y = 270; y <270 + 540; y++){
        for (int x = 1250; x <  1250 +311; x++){	
            pixel->color = cryingMarioRight[i]; 
            pixel->x = x;
            pixel->y = y;
            drawPixel(pixel);
            i++;           
        }
    }
    free(pixel);
    pixel = NULL;
}

void draw_GameWon(){
    Pixel *pixel;
    pixel = malloc(sizeof(Pixel));
    short int *gameWon=(short int *) gameWon_image.image_pixels;
    int i = 0;
    for (int y = 0; y < 1020; y++){
        for (int x = 0; x < 1600; x++){	
            pixel->color = gameWon[i]; 
            pixel->x = x;
            pixel->y = y;
            drawPixel(pixel);
            i++;           
        }
    }
    free(pixel);
    pixel = NULL;
}

