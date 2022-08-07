#include "headerMain.h"
// --------------------------- Status Bar ---------------------------
/*
    this file handles the states of the game, constructing each state as needed. 
*/

// checking if Mario went from one state to another 
int checkGateCollision(){
    if(level.level == 1){
        if((mario.y < 79) && (mario.x + mario.width > 1527)){
            // set for level 2
            level.level += 1;
            setCoinFlags();
            setHeartFlags();
            drawPreviousBackground_Mario();
            mario.x = 0;
            mario.y = 470;
            drawMove_Mario();
            draw_keyBackground(0, 1520);
            draw_key(941, 1520);
        }
    }

    if(level.level == 2){
        if((mario.y + mario.height > 941) && (mario.x + mario.width > 1520)){
            // set for level 3
            level.level += 1;
            setCoinFlags();
            setHeartFlags();
            drawPreviousBackground_Mario();
            mario.x = 1520;
            mario.y = 941;
            drawMove_Mario();
            draw_keyBackground(941, 1520);
            draw_key(1, 1);
        }
    }

    if(level.level == 3){
        if((mario.y < 79) && (mario.x < 73)){
            // set for level 4
            level.level += 1;
            setCoinFlags();
            setHeartFlags();
            drawPreviousBackground_Mario();
            mario.x = 0;
            mario.y = 941;
            drawMove_Mario();
            draw_keyBackground(0, 0);
            draw_key(0, 1520);
        }
    }

    if(level.level == 4){
        if((mario.y < 79) && (mario.x + mario.width > 1527)){
            // end game
            level.level += 1; // on purpose 
            Status.gameWon = 1;
            Menu.flag = 1;
            drawPreviousBackground_Mario();
        }
    }
    
    return 0;
}

void restartToInitialState(){
    level.level = 1;
    Status.gameOver = 0;
    Status.gameWon = 0;
    Timer.time = 90;
    Timer.paused = 0;
    Menu.flag = 0;
    Status.lifes = 4;
    Status.score = 0;
    mario.button = -1;
    mario.x = 800;
    mario.y = 941;
    mario.height = 79;
    mario.width = 73;
    Status.checker = 0;
    checkRepeat.one = 1;
    checkRepeat.two = 1;
    checkRepeat.three = 1;
    checkRepeat.four = 1;
    checkRepeat.five = 1;
    checkRepeat.six = 1;
    drawWhiteBackground();
    drawStatusBackground();
    drawMove_Mario();
    coinConstructor1();
    heartConstructor1();
    draw_key(0, 1520);
}

void level1Constructor(){
    drawWhiteBackground();
    drawStatusBackground();
    drawMove_Mario();
    setCoinFlags();
    setHeartFlags();
    coinConstructor1();
    heartConstructor1();
    draw_key(0, 1520);
    mario.x = 800;
    mario.y = 941;
    drawMove_Mario();
}

void level2Constructor(){
    drawWhiteBackground();
    drawStatusBackground();
    setCoinFlags();
    setHeartFlags();
    coinConstructor2();
    heartConstructor2();
    draw_key(941, 1520);
    mario.x = 0;
    mario.y = 470;
    drawMove_Mario();
}

void level3Constructor(){
    drawWhiteBackground();
    drawStatusBackground();
    setCoinFlags();
    setHeartFlags();
    coinConstructor3();
    heartConstructor3();
    draw_key(1, 1);
    mario.x = 1520;
    mario.y = 941;
    drawMove_Mario();
}


void level4Constructor(){
    drawWhiteBackground();
    drawStatusBackground();
    setCoinFlags();
    setHeartFlags();
    coinConstructor4();
    heartConstructor4();
    mario.x = 0;
    mario.y = 941;
    drawMove_Mario();
    draw_key(0, 1520);
}


