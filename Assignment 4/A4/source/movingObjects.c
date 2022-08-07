#include "headerMain.h"
// ------------------------------------ Moving Objects ------------------------------------
/*
    This file handles all related functions for moving objects such as Bullets and Fire-balls.
*/

void initMovingObjectThreads(){
    long one = 1;
    long two = 2;
    long three = 3;
    long four = 4;
    long five = 5;
    long six = 6;
    int x;

    // PTHREADS
    pthread_t tid1, tid2, tid3, tid4, tid5, tid6, tid7;
    pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid1, &attr, objectConstructor, &one);
    pthread_create(&tid2, &attr, objectConstructor, &two);
    pthread_create(&tid3, &attr, objectConstructor, &three);
    pthread_create(&tid4, &attr, objectConstructor, &four);
    pthread_create(&tid5, &attr, objectConstructor, &five);
    pthread_create(&tid6, &attr, objectConstructor, &six);

    // Timer thread
    pthread_create(&tid7, &attr, timerThread, &x);
}

void *objectConstructor(void* id){
    int myId = *(int*)id;

    short int *leftRocketBad=(short int *) leftRocketBadguyImage.image_pixels;
    short int *rightRocketBad=(short int *) rightRocketBadguyImage.image_pixels;

    short int *bulletUp=(short int *) bulletUP.image_pixels;
    short int *bulletDown=(short int *) bulletDOWN.image_pixels;

    short int *bottomLeftToTopRight=(short int *) fireballBOTTOMLEFTtoTOPRIGHT.image_pixels;
    short int *topRightToBottomLeft=(short int *) fireballTOPRIGHTtoLEFTDOWNc.image_pixels;

    short int *bottomRightToTopLeft=(short int *) fireballBOTTOMRIGHTtoTOPLEFT.image_pixels;
    short int *topLeftToBottomRight=(short int *) fireballTOPLEFTtoBOTTOMRIGHT.image_pixels;
    
    checkRepeat.one = 1;
    checkRepeat.two = 1;
    checkRepeat.three = 1;
    checkRepeat.four = 1;
    checkRepeat.five = 1;
    checkRepeat.six = 1;

    Object *blackRocketBadman1;
    blackRocketBadman1 = malloc(sizeof(Object));
    while(1){

        while(myId == 1){
            if(level.level == 1 && checkRepeat.one == 1){ //horizontal 
                blackRocketBadman1->speed = 10;
                blackRocketBadman1->x = 100;
                blackRocketBadman1->y = 80;
                blackRocketBadman1->height = 47;
                blackRocketBadman1->width = 82;
                blackRocketBadman1->currentState = level.level;
                blackRocketBadman1->left_Image = leftRocketBad;
                blackRocketBadman1->right_Image= rightRocketBad;
                blackRocketBadman1->flag = 0;
                movingObjects(blackRocketBadman1, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman1);
                checkRepeat.one++;   
            }

            if(level.level == 2 && checkRepeat.one == 2){ //vertical 
                blackRocketBadman1->speed = 10;
                blackRocketBadman1->x = 160;
                blackRocketBadman1->y = 100;
                blackRocketBadman1->height = 82;
                blackRocketBadman1->width = 47;
                blackRocketBadman1->currentState = level.level;
                blackRocketBadman1->left_Image = bulletUp;
                blackRocketBadman1->right_Image= bulletDown;
                movingObjects(blackRocketBadman1, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman1); 
                checkRepeat.one++;
            }
    
            if(level.level == 3 && checkRepeat.one == 3){ // diagonal - top right to bottom left
                blackRocketBadman1->speed = 5;
                blackRocketBadman1->x = 500;
                blackRocketBadman1->y = 0;
                blackRocketBadman1->height = 72;
                blackRocketBadman1->width = 70;
                blackRocketBadman1->currentState = level.level;
                blackRocketBadman1->left_Image = topRightToBottomLeft;
                blackRocketBadman1->right_Image= bottomLeftToTopRight;
                movingObjects(blackRocketBadman1, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman1); 
                checkRepeat.one++;
            }
            
            if(level.level == 4 && checkRepeat.one == 4){ //diagonal - top left to bottom right 
                blackRocketBadman1->speed = 5;
                blackRocketBadman1->x = 0;
                blackRocketBadman1->y = 500;
                blackRocketBadman1->height = 72;
                blackRocketBadman1->width = 70;
                blackRocketBadman1->currentState = level.level;
                blackRocketBadman1->left_Image = bottomRightToTopLeft;
                blackRocketBadman1->right_Image= topLeftToBottomRight;
                movingObjects(blackRocketBadman1, myId);
                checkRepeat.one++;
            }
        }

        while(myId == 2){
            Object *blackRocketBadman2;
            blackRocketBadman2 = malloc(sizeof(Object));

            blackRocketBadman2->left_Image = leftRocketBad;
            blackRocketBadman2->right_Image= rightRocketBad;

            if(level.level == 1 && checkRepeat.two == 1){//horizontal
                blackRocketBadman2->speed = 10;
                blackRocketBadman2->x = 1000;
                blackRocketBadman2->y = 250;
                blackRocketBadman2->height = 47;
                blackRocketBadman2->width = 82;
                blackRocketBadman2->currentState = level.level;
                blackRocketBadman2->flag = 0;
                movingObjects(blackRocketBadman2, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman2);
                checkRepeat.two++;
            }
                       
            if(level.level == 2 && checkRepeat.two == 2){//vertical 
                blackRocketBadman2->speed = 10;
                blackRocketBadman2->x = 450;
                blackRocketBadman2->y = 200;
                blackRocketBadman2->height = 82;
                blackRocketBadman2->width = 47;
                blackRocketBadman2->currentState = level.level;
                blackRocketBadman2->flag = 0;
                blackRocketBadman2->left_Image = bulletUp;
                blackRocketBadman2->right_Image= bulletDown;
                movingObjects(blackRocketBadman2, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman2);
                checkRepeat.two++;
            }
                  
            if(level.level == 3 && checkRepeat.two == 3){// diagonal - top right to bottom left
                blackRocketBadman2->speed = 5;
                blackRocketBadman2->x = 900;
                blackRocketBadman2->y = 0;
                blackRocketBadman2->height = 72;
                blackRocketBadman2->width = 70;
                blackRocketBadman2->currentState = level.level;
                blackRocketBadman2->left_Image = topRightToBottomLeft;
                blackRocketBadman2->right_Image= bottomLeftToTopRight;
                movingObjects(blackRocketBadman2, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman2);
                checkRepeat.two++;
            }
                 
            if(level.level == 4 && checkRepeat.two == 4){//diagonal - top left to bottom right 
                blackRocketBadman2->speed = 5;
                blackRocketBadman2->x = 0;
                blackRocketBadman2->y = 120;
                blackRocketBadman2->height = 72;
                blackRocketBadman2->width = 70;
                blackRocketBadman2->currentState = level.level;
                blackRocketBadman2->left_Image = bottomRightToTopLeft;
                blackRocketBadman2->right_Image= topLeftToBottomRight;
                movingObjects(blackRocketBadman2, myId);
            }
            free(blackRocketBadman2);
            blackRocketBadman2 = NULL;

        }
        
        while(myId == 3){
            Object *blackRocketBadman3;
            blackRocketBadman3 = malloc(sizeof(Object));

            blackRocketBadman3->left_Image = leftRocketBad;
            blackRocketBadman3->right_Image= rightRocketBad;

            if(level.level == 1 && checkRepeat.three == 1){//horizontal
                blackRocketBadman3->speed = 10;
                blackRocketBadman3->x = 10;
                blackRocketBadman3->y = 400;
                blackRocketBadman3->height = 47;
                blackRocketBadman3->width = 82;
                blackRocketBadman3->currentState = level.level;
                blackRocketBadman3->flag = 0;
                movingObjects(blackRocketBadman3, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman3);
                checkRepeat.three++;
            }
            
            if(level.level == 2 && checkRepeat.three == 2){//vertical 
                blackRocketBadman3->speed = 10;
                blackRocketBadman3->x = 700;
                blackRocketBadman3->y = 0;
                blackRocketBadman3->height = 82;
                blackRocketBadman3->width = 47;
                blackRocketBadman3->currentState = level.level;
                blackRocketBadman3->flag = 0;
                blackRocketBadman3->left_Image = bulletUp;
                blackRocketBadman3->right_Image= bulletDown;
                movingObjects(blackRocketBadman3, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman3);
                checkRepeat.three++;
            }
            

            if(level.level == 3 && checkRepeat.three == 3){// diagonal - top right to bottom left
                blackRocketBadman3->speed = 5;
                blackRocketBadman3->x = 1300;
                blackRocketBadman3->y = 0;
                blackRocketBadman3->height = 72;
                blackRocketBadman3->width = 70;
                blackRocketBadman3->currentState = level.level;
                blackRocketBadman3->left_Image = topRightToBottomLeft;
                blackRocketBadman3->right_Image= bottomLeftToTopRight;
                movingObjects(blackRocketBadman3, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman3);
                checkRepeat.three++;
            }
            
            
            if(level.level == 4 && checkRepeat.three == 4){//diagonal - top left to bottom right 
                blackRocketBadman3->speed = 5;
                blackRocketBadman3->x = 200;
                blackRocketBadman3->y = 0;
                blackRocketBadman3->height = 72;
                blackRocketBadman3->width = 70;
                blackRocketBadman3->currentState = level.level;
                blackRocketBadman3->left_Image = bottomRightToTopLeft;
                blackRocketBadman3->right_Image= topLeftToBottomRight;
                movingObjects(blackRocketBadman3, myId);
            }
            free(blackRocketBadman3);
            blackRocketBadman3 = NULL;
        }
        

        while(myId == 4){
            Object *blackRocketBadman4;
            blackRocketBadman4 = malloc(sizeof(Object));

            blackRocketBadman4->left_Image = leftRocketBad;
            blackRocketBadman4->right_Image= rightRocketBad;

            if(level.level == 1 && checkRepeat.four == 1){//horizontal
                blackRocketBadman4->speed = 10;
                blackRocketBadman4->x = 900;
                blackRocketBadman4->y = 550;
                blackRocketBadman4->height = 47;
                blackRocketBadman4->width = 82;
                blackRocketBadman4->currentState = level.level;
                blackRocketBadman4->flag = 0;
                movingObjects(blackRocketBadman4, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman4);
                checkRepeat.four++;
            }
            
            drawPreviousBackground_RocketBadguy(blackRocketBadman4);
            if(level.level == 2 && checkRepeat.four == 2){//vertical 
                blackRocketBadman4->speed = 10;
                blackRocketBadman4->x = 950;
                blackRocketBadman4->y = 900;
                blackRocketBadman4->height = 82;
                blackRocketBadman4->width = 47;
                blackRocketBadman4->currentState = level.level;
                blackRocketBadman4->flag = 0;
                blackRocketBadman4->left_Image = bulletUp;
                blackRocketBadman4->right_Image= bulletDown;
                movingObjects(blackRocketBadman4, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman4);
                checkRepeat.four++;
            }
            
            drawPreviousBackground_RocketBadguy(blackRocketBadman4);
            if(level.level == 3 && checkRepeat.four == 3){// diagonal - top right to bottom left
                blackRocketBadman4->speed = 5;
                blackRocketBadman4->x = 1500;
                blackRocketBadman4->y = 200;
                blackRocketBadman4->height = 72;
                blackRocketBadman4->width = 70;
                blackRocketBadman4->currentState = level.level;
                blackRocketBadman4->left_Image = topRightToBottomLeft;
                blackRocketBadman4->right_Image= bottomLeftToTopRight;
                movingObjects(blackRocketBadman4, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman4);
                checkRepeat.four++;
            }
            
            if(level.level == 4 && checkRepeat.four == 4){//diagonal - top left to bottom right 
                blackRocketBadman4->speed = 5;
                blackRocketBadman4->x = 700;
                blackRocketBadman4->y = 0;
                blackRocketBadman4->height = 72;
                blackRocketBadman4->width = 70;
                blackRocketBadman4->currentState = level.level;
                blackRocketBadman4->left_Image = bottomRightToTopLeft;
                blackRocketBadman4->right_Image= topLeftToBottomRight;
                movingObjects(blackRocketBadman4, myId);
                checkRepeat.four++;
            }
            free(blackRocketBadman4);
            blackRocketBadman4 = NULL;
        }

        while(myId == 5){
            Object *blackRocketBadman5;
            blackRocketBadman5 = malloc(sizeof(Object));

            blackRocketBadman5->left_Image = leftRocketBad;
            blackRocketBadman5->right_Image= rightRocketBad;

            if(level.level == 1 && checkRepeat.five == 1){//horizontal
                blackRocketBadman5->speed = 10;
                blackRocketBadman5->x = 477;
                blackRocketBadman5->y = 700;
                blackRocketBadman5->height = 47;
                blackRocketBadman5->width = 82;
                blackRocketBadman5->currentState = level.level;
                movingObjects(blackRocketBadman5, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman5);
                checkRepeat.five++;
            }
            
            if(level.level == 2 && checkRepeat.five == 2){//vertical 
                blackRocketBadman5->speed = 20;
                blackRocketBadman5->x = 1200;
                blackRocketBadman5->y = 0;
                blackRocketBadman5->height = 82;
                blackRocketBadman5->width = 47;
                blackRocketBadman5->currentState = level.level;
                blackRocketBadman5->left_Image = bulletUp;
                blackRocketBadman5->right_Image= bulletDown;
                movingObjects(blackRocketBadman5, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman5);
                checkRepeat.five++;
            }
            
            if(level.level == 3 && checkRepeat.five == 3){// diagonal - top right to bottom left
                blackRocketBadman5->speed = 5;
                blackRocketBadman5->x = 1500;
                blackRocketBadman5->y = 500;
                blackRocketBadman5->height = 72;
                blackRocketBadman5->width = 70;
                blackRocketBadman5->currentState = level.level;
                blackRocketBadman5->left_Image = topRightToBottomLeft;
                blackRocketBadman5->right_Image= bottomLeftToTopRight;
                movingObjects(blackRocketBadman5, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman5);
                checkRepeat.five++;
            }
            
            if(level.level == 4 && checkRepeat.five == 4){//diagonal - top left to bottom right 
                blackRocketBadman5->speed = 5;
                blackRocketBadman5->x = 1100;
                blackRocketBadman5->y = 0;
                blackRocketBadman5->height = 72;
                blackRocketBadman5->width = 70;
                blackRocketBadman5->currentState = level.level;
                blackRocketBadman5->left_Image = bottomRightToTopLeft;
                blackRocketBadman5->right_Image= topLeftToBottomRight;
                movingObjects(blackRocketBadman5, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman5);
                checkRepeat.five++;
            }
            free(blackRocketBadman5);
            blackRocketBadman5 = NULL;
        }

        while(myId == 6){
            Object *blackRocketBadman6;
            blackRocketBadman6 = malloc(sizeof(Object));

            blackRocketBadman6->left_Image = leftRocketBad;
            blackRocketBadman6->right_Image= rightRocketBad;

            if(level.level == 1 && checkRepeat.six == 1){//horizontal
                blackRocketBadman6->speed = 10;
                blackRocketBadman6->x = 10;
                blackRocketBadman6->y = 870;
                blackRocketBadman6->height = 47;
                blackRocketBadman6->width = 82;
                blackRocketBadman6->currentState = level.level;
                movingObjects(blackRocketBadman6, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman6);
                checkRepeat.six++;
            }
            
            if(level.level == 2 && checkRepeat.six == 2){//vertical 
                blackRocketBadman6->speed = 10;
                blackRocketBadman6->x = 1420;
                blackRocketBadman6->y = 10;
                blackRocketBadman6->height = 82;
                blackRocketBadman6->width = 47;
                blackRocketBadman6->currentState = level.level;
                blackRocketBadman6->left_Image = bulletUp;
                blackRocketBadman6->right_Image= bulletDown;
                movingObjects(blackRocketBadman6, myId);
                drawPreviousBackground_RocketBadguy(blackRocketBadman6);
                checkRepeat.six++;
            }
            free(blackRocketBadman6);
            blackRocketBadman6 = NULL;
        }

    }
    free(blackRocketBadman1);
    blackRocketBadman1 = NULL;
}


void movingObjects(Object *myObject, int myId){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

    int movingObject = 0;
    
    myObject->flag = 0;
   
    while(1){
        if(myObject->flag == 1 || myObject->currentState != level.level || Status.gameOver == 1 || Menu.flag == 1){
            myObject->flag = 0;
            break;
        }
        // one direction 
        while(movingObject == 0){  
            drawPreviousBackground_RocketBadguy(myObject);

            if(level.level == 1){ // for horizontal
                myObject->x += myObject->speed;
            }
            if(level.level == 2){ // for vertical
                myObject->y += myObject->speed;
            }
            if(level.level == 3){ // diagonal - top left - bottom right 
                myObject->y -= myObject->speed;
                myObject->x += myObject->speed;
            }
            if(level.level == 4){ // diagonal - top right to bottom left 
                myObject->y += myObject->speed;
                myObject->x += myObject->speed;
            }

            int i = 0;
            for (int y = myObject->y; y < myObject->y + myObject->height; y++){
                for (int x = myObject->x; x < myObject->x + myObject->width; x++){	
                    pixel->color = myObject->right_Image[i]; 
                    pixel->x = x;
                    pixel->y = y;
                    drawPixel(pixel);
                    i++;           
                }
            }
            checkCollision(myObject);
            if(myObject->flag == 1 || myObject->currentState != level.level || Status.gameOver == 1 || Menu.flag == 1){
                break;
            }
            usleep(10000);

            if(level.level == 1){ // for horizontal
                if( myObject->x >= (1510)){
                    movingObject = 1;
                    break;
                }

            }
            if(level.level == 2){ // for vertical
                if( myObject->y >= (970)){
                    movingObject = 1;
                    break;
                }
            }
            if(level.level == 3){ // for diagonal - left to right 
                if( myObject->y < (0) || myObject->x > (1500)){
                    movingObject = 1;
                    break;
                }
            }
            if(level.level == 4){ // for diagonal - right to left 
                if( myObject->y > (950) || myObject->x > (1500)){
                    movingObject = 1;
                    break;
                }
            }
            while(Menu.flag == 1){}
            
        }

        // opposite direction
        while(movingObject == 1){ 
            drawPreviousBackground_RocketBadguy(myObject);
            if(level.level == 1){ // for horizontal
                myObject->x -= myObject->speed;
            }
            if(level.level == 2){ // for vertical
                myObject->y -= myObject->speed;
            }
            if(level.level == 3){ // diagonal - top left - bottom right
                myObject->y += myObject->speed;
                myObject->x -= myObject->speed;
            }
            if(level.level == 4){ // diagonal - top right to bottom left  
                myObject->y -= myObject->speed;
                myObject->x -= myObject->speed;
            }

            int i = 0;
            for (int y = myObject->y; y < myObject->y + myObject->height; y++){
                for (int x = myObject->x; x < myObject->x + myObject->width; x++){	
                    pixel->color = myObject->left_Image[i]; 
                    pixel->x = x;
                    pixel->y = y;
                    drawPixel(pixel);
                    i++;           
                }
            }

            checkCollision(myObject);
            if(myObject->flag == 1 || myObject->currentState != level.level || Status.gameOver == 1 || Menu.flag == 1){
                break;
            }

            usleep(10000);

            if(level.level == 1){ // for horizontal
                if(myObject->x < 15){
                    movingObject = 0;
                    break;
                }
            }
            if(level.level == 2){ // for vertical
                if( myObject->y <= (0)){
                    movingObject = 0;
                    break;
                }
            }
            if(level.level == 3){ // for diagonal - left to right 
                if( myObject->y > (970) || myObject->x <= (15)){
                    movingObject = 0;
                    break;
                }
            }
            if(level.level == 4){ // for diagonal - right to left 
                if( myObject->y < (0) || myObject->x <= (15)){
                    movingObject = 0;
                    break;
                }
            }
            while(Menu.flag == 1){}
        }
    }  

    free(pixel);
	pixel = NULL;
}


