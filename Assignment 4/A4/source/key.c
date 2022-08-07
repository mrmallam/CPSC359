#include "headerMain.h"
// --------------------------- KEY ---------------------------

void draw_key(int yPosition, int xPosition){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));
    short int *key=(short int *) key_image.image_pixels;
    
    int i = 0;
    for (int y = yPosition; y < yPosition + 79; y++){
        for (int x = xPosition; x < xPosition + 73; x++){	
            pixel->color = key[i]; 
            pixel->x = x;
            pixel->y = y;
            drawPixel(pixel);
            i++;           
        }
    }
    free(pixel);
	pixel = NULL;
}


void draw_keyBackground(int yPosition, int xPosition){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));
    
    int i = 0;
    for (int y = yPosition; y < yPosition + 79; y++){
        for (int x = xPosition; x < xPosition + 73; x++){	
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
