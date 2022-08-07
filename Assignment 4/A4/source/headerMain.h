#ifndef testt 
#define testt

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <sys/mman.h>
#include "framebuffer.h"
#include <pthread.h>
#include <time.h>


#include <unistd.h>
#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "initGPIO.h"

#include "RocketBadguyRight.h"
#include "leftRocketBad.h"

#include "marioLeft.h"
#include "marioRight.h"
#include "upDown_mario.h"
#include "blackWhiteStart.h"
#include "coin.h"
#include "alien.h"
#include "blackHeart.h"
#include "redHeart.h"
#include "score.h"
#include "zero.h"
#include "one.h"
#include "two.h"
#include "three.h"
#include "four.h"
#include "five.h"
#include "six.h"
#include "seven.h"
#include "eight.h"
#include "nine.h"
#include "lifes.h"
#include "timeImage.h"
#include "fireballBOTTOMLEFTtoTOPRIGHT.h"
#include "fireballBOTTOMRIGHTtoTOPLEFT.h"
#include "fireballTOPLEFTtoBOTTOMRIGHT.h"
#include "fireballTOPRIGHTtoLEFTDOWNc.h"
#include "key.h"

#include "bulletUP.h"
#include "bulletDOWN.h"

#include "gameOver.h"
#include "gameWon.h"
#include "cryingMarioLeft.h"
#include "cryingMarioRIGHT.h"

#include "mainMenuPlay.h"
#include "mainMenuQuit.h"
#include "midMenuQuit.h"
#include "midMenuResume.h"

#define LAT  9  // Latch Line
#define DAT  10 // Data Line
#define CLK  11 // Clock Line

#define GPSET0 7    // SET
#define GPCLR0 10   // CLEAR
#define GPLEV0 13   // READ

#define INP_GPIO(g) *(gpioPtr+((g)/10)) &= ~(7<<(((g)%10)*3)); // Setting pin to Input 
#define OUT_GPIO(g) *(gpioPtr+((g)/10)) |= (1<<(((g)%10)*3)); // Setting pin to Output

struct fbs framebufferstruct;
int paused;
typedef struct {
	short int color;
	int x, y;
} Pixel;

struct Flags0{
	int a, b, c, d, e, f, g, h ,i;
	int level1, level2, level3, level4;
} coinFlag;

struct Flags1{
	int a, b, c, d, e, f, g, h;
} heartFlag;

struct LEVEL{
	int level;
} level;

struct checksForNoRepeat{
	  int checker, checker1, checker2, checker3, checker4, checker5;
} checker;

struct Mario{
	int color, direction_mario;
	int x, y;
	int width, height;
	int button;
} mario;
struct check{
	int one, two, three, four, five, six;

} checkRepeat;
struct StatusBar{
	int score, lifes, time, level, gameOver, checker, gameWon;
} Status;

struct Menu{
	int flag;
	int up, down;
	int terminate;
} Menu;

struct timerControl{
	int paused;
	int time;
}Timer;

typedef struct{
	int x, y;
	int width, height;
	int xPosition, yPosition;
	int flag;
	int speed;
	int currentState;
	short int * image;
	short int * left_Image;
	short int * right_Image;

	short int * bulletUP_Image;
	short int * bulletDOWN_Image;

	short int * topRightToBottonLeft_Image;
	short int * topLeftToBottomRight_Image;

	short int * bottomRightToTopLeft_Image;
	short int * bottomLeftToTopRight_Image;

} Object;

/* Definitions */
void initializeSNES(unsigned int *gpioPtr);
void Write_Clock(unsigned int *gpioPtr, int value);
void Write_Latch(unsigned int *gpioPtr, int value);
int readSNES(unsigned int *gpioPtr);
void Button_Pressed();
void drawPixel(Pixel *pixel);

void drawMove_Mario();
void drawPreviousBackground_Mario();

void drawWhiteBackground();
void drawStatusBackground();
void drawInitialstateBlackWhite();

void movingObjects(Object *myObject, int id);
void testingMArio(short int* rocket);
void drawPreviousBackground_RocketBadguy(Object *myObject);

void checkCollision(Object *myObject);
void *objectConstructor(void* id);

void coinConstructor1();
int coinConstructor2();
int coinConstructor3();
int coinConstructor4();
void draw_coin(int x, int y);
void setCoinFlags();
void coinDrawPreviousBackground(int xPosition, int yPosition);
void checkCoinCollision();
int coinCollision(int xPosition, int yPosition);

void newSeed();
void heartConstructor1();
int heartConstructor2();
int heartConstructor3();
int heartConstructor4();
void setHeartFlags();
void draw_heart(int xPosition, int yPosition, short int *image);
int heartCollision(int xPosition, int yPosition, int color);
void heartDrawPreviousBackground(int xPosition, int yPosition);
void checkheartCollision();

void statusSCORE();
void printRightside(short int *image, int yPosition, int xPosition);
void printLeftside(short int *Image, int yPosition, int xPosition);
void drawNumbers(int number, int id);
void drawTexts(short int *image, int xPosition, int Yposition, int width, int height);
void calculateScore();

void movingObjectsVERTICAL(Object *myObject, int myId);
int checkGateCollision();
void levelsConstructor();

void initMovingObjectThreads();

void draw_key(int yPosition, int xPosition);
void draw_keyBackground(int yPosition, int xPosition);
void draw_GameOver();
void *timer(void* id);
void draw_GameWon();
void restartToInitialState();
void *timerThread(void* x);
void level1Constructor();
void level2Constructor();
void level3Constructor();
void level4Constructor();

void checkForLifes();
void drawMainMenu(short int *image);
void initializeMainMenu();
void displayMidMenu();
#endif 