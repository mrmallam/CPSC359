#include "headerMain.h"
// --------------------------- COIN ---------------------------
/*
    This file is a collection of Coin related functions, such as:
        - coin initialization/construction
        - coin collision
        - draw coin
        - draw coin previous background 

*/

void setCoinFlags(){
    coinFlag.a= 0; 
    coinFlag.b= 0;
    coinFlag.c= 0;
    coinFlag.d= 0;
    coinFlag.e= 0;
    coinFlag.f= 0;
    coinFlag.g= 0;
    coinFlag.h= 0;
    coinFlag.i= 0; 
    checker.checker = 0;
    checker.checker1 = 0;
    checker.checker2 = 0;
    checker.checker3 = 0;
    checker.checker4 =  0;
    checker.checker5 = 0;
}
void coinConstructor1(){
    setCoinFlags();

//     (xPosition,  yPosition)
    if(level.level == 1){
        draw_coin(1350, 140);
        draw_coin(200, 151);
        draw_coin(1400, 312);
        draw_coin(350, 312);
        draw_coin(800, 470);
        draw_coin(1000, 620);
        draw_coin(100, 780);
        draw_coin(1540, 780);
        draw_coin(400, 950);
    }
}
int coinConstructor2(){
    coinDrawPreviousBackground(1350, 140);
    coinDrawPreviousBackground(200, 151);
    coinDrawPreviousBackground(1400, 312);
    coinDrawPreviousBackground(350, 312);
    coinDrawPreviousBackground(800, 470);
    coinDrawPreviousBackground(1000, 620);
    coinDrawPreviousBackground(100, 780);
    coinDrawPreviousBackground(1540, 780);
    coinDrawPreviousBackground(400, 950);

    draw_coin(300, 140);
    draw_coin(350, 500);
    draw_coin(600, 312);
    draw_coin(850, 700);
    draw_coin(1350, 900);
    draw_coin(1090, 200);
    draw_coin(600, 900);
    draw_coin(1350, 200);
    draw_coin(1350, 500);

    return 1;
}

int coinConstructor3(){
    coinDrawPreviousBackground(300, 140);
    coinDrawPreviousBackground(350, 500);
    coinDrawPreviousBackground(600, 312);
    coinDrawPreviousBackground(850, 700);
    coinDrawPreviousBackground(1350, 900);
    coinDrawPreviousBackground(1090, 200);
    coinDrawPreviousBackground(600, 900);
    coinDrawPreviousBackground(1350, 140);
    coinDrawPreviousBackground(1350, 500);

    draw_coin(200, 140);
    draw_coin(220, 500);
    draw_coin(600, 200);
    draw_coin(850, 700);
    draw_coin(1350, 900);
    draw_coin(1220, 200);
    draw_coin(600, 900);
    draw_coin(500, 540);
    draw_coin(1350, 500);

    return 1;
}

int coinConstructor4(){
    coinDrawPreviousBackground(200, 140);
    coinDrawPreviousBackground(220, 500);
    coinDrawPreviousBackground(600, 200);
    coinDrawPreviousBackground(850, 700);
    coinDrawPreviousBackground(1350, 900);
    coinDrawPreviousBackground(1220, 200);
    coinDrawPreviousBackground(600, 900);
    coinDrawPreviousBackground(500, 540);
    coinDrawPreviousBackground(1350, 500);

    draw_coin(200, 140);
    draw_coin(220, 500);
    draw_coin(600, 200);
    draw_coin(800, 700);
    draw_coin(1350, 900);
    draw_coin(1220, 300);
    draw_coin(600, 900);
    draw_coin(600, 540);
    draw_coin(1350, 500);
    
    return 1;
}


void checkCoinCollision(){
    // coin flags are for preventing the execution of the same function.
    if(level.level == 1){
        if(coinFlag.a != 1){
        coinFlag.a = coinCollision(1350, 140);

        }if(coinFlag.b != 1){
            coinFlag.b = coinCollision(200, 151);

        }if(coinFlag.c != 1){
            coinFlag.c = coinCollision(1400, 312);

        }if(coinFlag.d != 1){
            coinFlag.d = coinCollision(350, 312);
            
        }if(coinFlag.e != 1){
            coinFlag.e =coinCollision(800, 470);
            
        }if(coinFlag.f != 1){
            coinFlag.f = coinCollision(1000, 620);
            
        }if(coinFlag.g != 1){
            coinFlag.g = coinCollision(100, 780);

        }if(coinFlag.h != 1){
            coinFlag.h = coinCollision(1540, 780);
            
        }if(coinFlag.i != 1){
            coinFlag.i = coinCollision(400, 950);
        }
    }
    
    if(level.level == 2){
        if(coinFlag.a != 1){
        coinFlag.a = coinCollision(300, 140);

        }if(coinFlag.b != 1){
            coinFlag.b = coinCollision(350, 500);

        }if(coinFlag.c != 1){
            coinFlag.c = coinCollision(600, 312);

        }if(coinFlag.d != 1){
            coinFlag.d = coinCollision(850, 700);
            
        }if(coinFlag.e != 1){
            coinFlag.e =coinCollision(1350, 900);
            
        }if(coinFlag.f != 1){
            coinFlag.f = coinCollision(1090, 200);
            
        }if(coinFlag.g != 1){
            coinFlag.g = coinCollision(600, 900);

        }if(coinFlag.h != 1){
            coinFlag.h = coinCollision(1350, 200);
            
        }if(coinFlag.i != 1){
            coinFlag.i = coinCollision(1350, 500);
        }
    }

    
    if(level.level == 3){
        if(coinFlag.a != 1){
        coinFlag.a = coinCollision(200, 140);

        }if(coinFlag.b != 1){
            coinFlag.b = coinCollision(220, 500);

        }if(coinFlag.c != 1){
            coinFlag.c = coinCollision(600, 200);

        }if(coinFlag.d != 1){
            coinFlag.d = coinCollision(850, 700);
            
        }if(coinFlag.e != 1){
            coinFlag.e =coinCollision(1350, 900);
            
        }if(coinFlag.f != 1){
            coinFlag.f = coinCollision(1220, 200);
            
        }if(coinFlag.g != 1){
            coinFlag.g = coinCollision(600, 900);

        }if(coinFlag.h != 1){
            coinFlag.h = coinCollision(500, 540);
            
        }if(coinFlag.i != 1){
            coinFlag.i = coinCollision(1350, 500);
        }
    }

    if(level.level == 4){
        if(coinFlag.a != 1){
        coinFlag.a = coinCollision(200, 140);

        }if(coinFlag.b != 1){
            coinFlag.b = coinCollision(220, 500);

        }if(coinFlag.c != 1){
            coinFlag.c = coinCollision(600, 200);

        }if(coinFlag.d != 1){
            coinFlag.d = coinCollision(800, 700);
            
        }if(coinFlag.e != 1){
            coinFlag.e =coinCollision(1350, 900);
            
        }if(coinFlag.f != 1){
            coinFlag.f = coinCollision(1220, 200);
            
        }if(coinFlag.g != 1){
            coinFlag.g = coinCollision(600, 900);

        }if(coinFlag.h != 1){
            coinFlag.h = coinCollision(600, 540);
            
        }if(coinFlag.i != 1){
            coinFlag.i = coinCollision(1350, 500);
        }
    }
}


int coinCollision(int xPosition, int yPosition){

    if((mario.y > yPosition && mario.y < yPosition + 63) || (mario.y + mario.height > yPosition && mario.y + mario.height < yPosition + 63)  ||  (yPosition > mario.y && yPosition + 63 < mario.y + mario.height) || (mario.y < yPosition && mario.y + mario.height >= yPosition + 63)){
        if((mario.x > xPosition && mario.x < xPosition + 50) || (mario.x + mario.width > xPosition && mario.x + mario.width < xPosition + 50) || (mario.x <= xPosition && mario.x + mario.width >= xPosition + 50)){
            coinDrawPreviousBackground(xPosition, yPosition);
            Status.score += 5;
            drawMove_Mario();
            return 1;
        }
    }
}

void draw_coin(int xPosition, int yPosition){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));
    short int *coinImage = (short int *) coin_Image.image_pixels;
    int i = 0;
    for (int y = yPosition; y < yPosition + 63; y++){
        for (int x = xPosition; x < xPosition + 50; x++){	
            pixel->color = coinImage[i]; 
            pixel->x = x;
            pixel->y = y;
            drawPixel(pixel);
            i++;           
        }
    }
}


void coinDrawPreviousBackground(int xPosition, int yPosition){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

    int i = 0;
    for (int y = yPosition; y < yPosition + 63; y++){
        for (int x = xPosition; x < xPosition + 50; x++){	
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
