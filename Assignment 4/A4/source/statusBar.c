#include "headerMain.h"
// --------------------------- Status Bar ---------------------------
/*
    this file handles functions related to the status bar on the right side of the screen
        - Score 
        - Lifes
        - Timer
*/

void calculateScore(){
    
    // SCORE-ID = 0
    // LIFE-ID = 1 
    drawNumbers(Status.score, 0);
    drawNumbers(Status.lifes, 1);
}

void drawNumbers(int number, int id){

    int yPosition_LEFT, xPosition_LEFT, yPosition_RIGHT, xPosition_RIGHT ;
    int firstDigit, secondDigit;

    short int *zeroImage = (short int *) zero_image.image_pixels;
    short int *oneImage = (short int *) one_image.image_pixels;
    short int *twoImage = (short int *) two_image.image_pixels;
    short int *threeImage = (short int *) three_image.image_pixels;
    short int *fourImage = (short int *) four_image.image_pixels;
    short int *fiveImage = (short int *) five_image.image_pixels;
    short int *sixImage = (short int *) six_image.image_pixels;
    short int *sevenImage = (short int *) seven_image.image_pixels;
    short int *eightImage = (short int *) eight_image.image_pixels;
    short int *nineImage = (short int *) nine_image.image_pixels;
    short int *lifesImage = (short int *) lifes_image.image_pixels;
    short int *timeImage = (short int *) time_image.image_pixels;
    short int *scoreImage = (short int *) score_image.image_pixels;

    //image, xPosition, Yposition, width, height
    drawTexts(scoreImage, 1620, 120, 280, 68);
    drawTexts(lifesImage, 1610, 426, 280, 68);
    drawTexts(timeImage, 1620, 706, 280, 68);

    
    if(id == 0){
        yPosition_LEFT = 210;
        xPosition_LEFT = 1640;

        yPosition_RIGHT = 210;
        xPosition_RIGHT = 1778;
    }
    if(id == 1){
        yPosition_LEFT = 506;
        xPosition_LEFT = 1640;

        yPosition_RIGHT = 506;
        xPosition_RIGHT = 1778;
    }
    if(id == 2){
        yPosition_LEFT = 786;
        xPosition_LEFT = 1640;

        yPosition_RIGHT = 786;
        xPosition_RIGHT = 1778;
    }

    // separating first and second digit
    firstDigit = number / pow(10,1);
    secondDigit = number / pow(10,0);
    firstDigit = firstDigit % 10;
    secondDigit = secondDigit % 10;

    if(firstDigit == 0){
        printLeftside(zeroImage, yPosition_LEFT, xPosition_LEFT);        
    }else if(firstDigit == 1){
        printLeftside(oneImage, yPosition_LEFT, xPosition_LEFT);
    }else if(firstDigit == 2){
        printLeftside(twoImage, yPosition_LEFT, xPosition_LEFT);
    }else if(firstDigit == 3){
        printLeftside(threeImage, yPosition_LEFT, xPosition_LEFT);
    }else if(firstDigit == 4){
        printLeftside(fourImage, yPosition_LEFT, xPosition_LEFT);
    }else if(firstDigit == 5){
        printLeftside(fiveImage, yPosition_LEFT, xPosition_LEFT);
    }else if(firstDigit == 6){
        printLeftside(sixImage, yPosition_LEFT, xPosition_LEFT);
    }else if(firstDigit == 7){
        printLeftside(sevenImage, yPosition_LEFT, xPosition_LEFT);
    }else if(firstDigit == 8){
        printLeftside(eightImage, yPosition_LEFT, xPosition_LEFT);
    }else if(firstDigit == 9){
        printLeftside(nineImage, yPosition_LEFT, xPosition_LEFT);
    }
    if(secondDigit == 0){
        printRightside(zeroImage, yPosition_RIGHT, xPosition_RIGHT);
    }else if(secondDigit == 1){
        printRightside(oneImage, yPosition_RIGHT, xPosition_RIGHT);
    }else if(secondDigit == 2){
        printRightside(twoImage, yPosition_RIGHT, xPosition_RIGHT);
    }else if(secondDigit == 3){
        printRightside(threeImage, yPosition_RIGHT, xPosition_RIGHT);
    }else if(secondDigit == 4){
        printRightside(fourImage, yPosition_RIGHT, xPosition_RIGHT);
    }else if(secondDigit == 5){
        printRightside(fiveImage, yPosition_RIGHT, xPosition_RIGHT);
    }else if(secondDigit == 6){
        printRightside(sixImage, yPosition_RIGHT, xPosition_RIGHT);
    }else if(secondDigit == 7){
        printRightside(sevenImage, yPosition_RIGHT, xPosition_RIGHT);
    }else if(secondDigit == 8){
        printRightside(eightImage, yPosition_RIGHT, xPosition_RIGHT);
    }else if(secondDigit == 9){
        printRightside(nineImage, yPosition_RIGHT, xPosition_RIGHT);
    }
}


void printLeftside(short int *image, int yPosition, int xPosition){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

    int i = 0;
    for (int y = yPosition; y < yPosition + 118; y++){
        for (int x = xPosition ; x < xPosition + 100; x++){	
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

void printRightside(short int *image, int yPosition, int xPosition){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

    int i = 0;
    for (int y = yPosition; y < yPosition + 118; y++){
        for (int x = xPosition ; x < xPosition + 100; x++){	
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


void drawTexts(short int *image, int xPosition, int Yposition, int width, int height){
    Pixel *pixel;
	pixel = malloc(sizeof(Pixel));

    int i = 0;
    for (int y = Yposition; y < Yposition + height; y++){
        for (int x = xPosition ; x < xPosition + width; x++){	
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