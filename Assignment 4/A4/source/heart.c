#include "headerMain.h"
// --------------------------- Heart ---------------------------
/*
    This file is a collection of red and black Heart related functions, such as:
        - Heart initialization/construction
        - Heart collision
        - draw Heart
        - draw Heart previous background 

    Red heart: Life++
    Black heart: Life--
*/

void setHeartFlags(){
    heartFlag.a= 0; 
    heartFlag.b= 0;
    heartFlag.c= 0;
    heartFlag.d= 0;
    heartFlag.e= 0;
    heartFlag.f= 0;
    heartFlag.g= 0;
    heartFlag.h= 0;
}

void checkForLifes(){
    if(Status.lifes == 0){
        draw_GameOver();
        Status.gameOver = 1;
        Status.checker = 1;
        Timer.paused = 1;
    }
}

void heartConstructor1(){
    setHeartFlags();
    short int *redHeart_Image = (short int *) redHeart.image_pixels;
    short int *blackHeart_Image = (short int *) blackHeart.image_pixels;
    

    // (xPosition, yPosition)

    // RED
    draw_heart(900, 153, redHeart_Image);
    draw_heart(10, 311, redHeart_Image);
    draw_heart(1450, 625, redHeart_Image);
    draw_heart(700, 790, redHeart_Image);
    // BLACK
    draw_heart(400, 154, blackHeart_Image);
    draw_heart(1200, 140, blackHeart_Image);
    draw_heart(300, 470, blackHeart_Image);
    draw_heart(1350, 790, blackHeart_Image);
}

int heartConstructor2(){
    short int *redHeart_Image = (short int *) redHeart.image_pixels;
    short int *blackHeart_Image = (short int *) blackHeart.image_pixels;

    heartDrawPreviousBackground(900, 153);
    heartDrawPreviousBackground(10, 311);
    heartDrawPreviousBackground(1450, 625);
    heartDrawPreviousBackground(700, 790);
    heartDrawPreviousBackground(400, 154);
    heartDrawPreviousBackground(1200, 140);
    heartDrawPreviousBackground(300, 470);
    heartDrawPreviousBackground(1350, 790);

    // RED
    draw_heart(860, 153, redHeart_Image);
    draw_heart(340, 311, redHeart_Image);
    draw_heart(570, 625, redHeart_Image);
    draw_heart(1070, 790, redHeart_Image);
    draw_heart(1350, 800, redHeart_Image);
    // BLACK
    draw_heart(1100, 340, blackHeart_Image);
    draw_heart(300, 600, blackHeart_Image);
    draw_heart(870, 900, blackHeart_Image);
    return 1;
}

int heartConstructor3(){
    short int *redHeart_Image = (short int *) redHeart.image_pixels;
    short int *blackHeart_Image = (short int *) blackHeart.image_pixels;
    // xPosition yPosition

    heartDrawPreviousBackground(860, 153);
    heartDrawPreviousBackground(340, 311);
    heartDrawPreviousBackground(570, 625);
    heartDrawPreviousBackground(1070, 790);
    heartDrawPreviousBackground(1350, 800);
    heartDrawPreviousBackground(1100, 340);
    heartDrawPreviousBackground(300, 600);
    heartDrawPreviousBackground(870, 900);

    // // RED
    draw_heart(900, 153, redHeart_Image);
    draw_heart(100, 611, redHeart_Image);
    draw_heart(1250, 625, redHeart_Image);
    draw_heart(700, 790, redHeart_Image);
    draw_heart(500, 154, redHeart_Image);
    // BLACK
    draw_heart(1200, 340, blackHeart_Image);
    draw_heart(300, 470, blackHeart_Image);
    draw_heart(300, 800, blackHeart_Image);
    return 1;
}

int heartConstructor4(){
    short int *redHeart_Image = (short int *) redHeart.image_pixels;
    short int *blackHeart_Image = (short int *) blackHeart.image_pixels;

    heartDrawPreviousBackground(900, 153);
    heartDrawPreviousBackground(100, 611);
    heartDrawPreviousBackground(1250, 625);
    heartDrawPreviousBackground(700, 790);
    heartDrawPreviousBackground(500, 154);
    heartDrawPreviousBackground(1200, 340);
    heartDrawPreviousBackground(300, 470);
    heartDrawPreviousBackground(300, 800);
    
    // RED
    draw_heart(700, 153, redHeart_Image);
    draw_heart(10, 311, redHeart_Image);
    draw_heart(1450, 625, redHeart_Image);
    draw_heart(820, 480, redHeart_Image);
    draw_heart(1100, 204, redHeart_Image);
    // BLACK
    draw_heart(1200, 750, blackHeart_Image);
    draw_heart(280, 270, blackHeart_Image);
    draw_heart(500, 477, blackHeart_Image);
    return 1;
}


void checkheartCollision(){
    int color;

    if(level.level == 1){
        // RED
        if(heartFlag.a != 1){
            color = 0;
            heartFlag.a = heartCollision(900, 153, color);
        }
        if(heartFlag.b != 1){
            color = 0;
            heartFlag.b = heartCollision(10, 311, color);
            
        }if(heartFlag.c != 1){
            color = 0;
            heartFlag.c = heartCollision(1450, 625, color);
            
        }if(heartFlag.d != 1){
            color = 0;
            heartFlag.d = heartCollision(700, 790, color);
            
        }
        // BLACK
        if(heartFlag.e != 1){
            color = 1;
            heartFlag.e =heartCollision(400, 154, color);
            
        }if(heartFlag.f != 1){
            color = 1;
            heartFlag.f = heartCollision(1200, 140, color);
            
        }if(heartFlag.g != 1){
            color = 1;
            heartFlag.g = heartCollision(300, 470, color);
            
        }if(heartFlag.h != 1){
            color = 1;
            heartFlag.h = heartCollision(1350, 790, color);
        }
    }

    if(level.level == 2){
        // RED
        if(heartFlag.a != 1){
            color = 0;
            heartFlag.a = heartCollision(860, 153, color);
        }
        if(heartFlag.b != 1){
            color = 0;
            heartFlag.b = heartCollision(340, 311, color);
            
        }if(heartFlag.c != 1){
            color = 0;
            heartFlag.c = heartCollision(570, 625, color);
            
        }if(heartFlag.d != 1){
            color = 0;
            heartFlag.d = heartCollision(1070, 790, color);
            
        }
        // BLACK
        if(heartFlag.e != 1){
            color = 1;
            heartFlag.e =heartCollision(1350, 800, color);
            
        }if(heartFlag.f != 1){
            color = 1;
            heartFlag.f = heartCollision(1100, 340, color);
            
        }if(heartFlag.g != 1){
            color = 1;
            heartFlag.g = heartCollision(300, 600, color);
            
        }if(heartFlag.h != 1){
            color = 1;
            heartFlag.h = heartCollision(870, 900, color);
        }
    }

    if(level.level == 3){
        // RED
        if(heartFlag.a != 1){
            color = 0;
            heartFlag.a = heartCollision(900, 153, color);
        }
        if(heartFlag.b != 1){
            color = 0;
            heartFlag.b = heartCollision(100, 611, color);
            
        }if(heartFlag.c != 1){
            color = 0;
            heartFlag.c = heartCollision(1250, 625, color);
            
        }if(heartFlag.d != 1){
            color = 0;
            heartFlag.d = heartCollision(700, 790, color);
            
        }
        // BLACK
        if(heartFlag.e != 1){
            color = 1;
            heartFlag.e =heartCollision(500, 154, color);
            
        }if(heartFlag.f != 1){
            color = 1;
            heartFlag.f = heartCollision(1200, 340, color);
            
        }if(heartFlag.g != 1){
            color = 1;
            heartFlag.g = heartCollision(300, 470, color);
            
        }if(heartFlag.h != 1){
            color = 1;
            heartFlag.h = heartCollision(300, 800, color);
        }
    }

    if(level.level == 4){
        // RED
        if(heartFlag.a != 1){
            color = 0;
            heartFlag.a = heartCollision(700, 153, color);
        }
        if(heartFlag.b != 1){
            color = 0;
            heartFlag.b = heartCollision(10, 311, color);
            
        }if(heartFlag.c != 1){
            color = 0;
            heartFlag.c = heartCollision(1450, 625, color);
            
        }if(heartFlag.d != 1){
            color = 0;
            heartFlag.d = heartCollision(820, 480, color);
            
        }
        // BLACK
        if(heartFlag.e != 1){
            color = 1;
            heartFlag.e =heartCollision(1100, 204, color);
            
        }if(heartFlag.f != 1){
            color = 1;
            heartFlag.f = heartCollision(1200, 750, color);
            
        }if(heartFlag.g != 1){
            color = 1;
            heartFlag.g = heartCollision(280, 270, color);
            
        }if(heartFlag.h != 1){
            color = 1;
            heartFlag.h = heartCollision(500, 477, color);
        }
    }
}


int heartCollision(int xPosition, int yPosition, int color){
    if((mario.y > yPosition && mario.y < yPosition + 50) || (mario.y + mario.height > yPosition && mario.y + mario.height < yPosition + 50)  ||  (yPosition > mario.y && yPosition + 50 < mario.y + mario.height) || (mario.y < yPosition && mario.y + mario.height >= yPosition + 50)){
        if((mario.x > xPosition && mario.x < xPosition + 51) || (mario.x + mario.width > xPosition && mario.x + mario.width < xPosition + 51) || (mario.x <= xPosition && mario.x + mario.width >= xPosition + 51)){
            
            heartDrawPreviousBackground(xPosition, yPosition);
            drawMove_Mario();
            if(color == 0){
                Status.lifes += 1;
            }
            if(color == 1){
                Status.lifes -= 1;
            }

            return 1;
        }
    }
}
 

void draw_heart(int xPosition, int yPosition, short int *image){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));
    
    int i = 0;
    for (int y = yPosition; y < yPosition + 50; y++){
        for (int x = xPosition; x < xPosition + 51; x++){	
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

void heartDrawPreviousBackground(int xPosition, int yPosition){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

    int i = 0;
    for (int y = yPosition; y < yPosition + 50; y++){
        for (int x = xPosition; x < xPosition+51; x++){	
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