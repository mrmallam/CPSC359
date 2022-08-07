#include "headerMain.h"
// ------------------------------------ COLLISION ------------------------------------
/*
    handels the collision of Mario and object 
*/
void checkCollision(Object *myObject){
    if((mario.y > myObject->y && mario.y < myObject->y + myObject->height) || (mario.y + mario.height > myObject->y && mario.y + mario.height < myObject->y + myObject->height)  ||  (myObject->y > mario.y && myObject->y + myObject->height < mario.y + mario.height)){
        if((mario.x > myObject->x && mario.x < myObject->x + myObject->width) || (mario.x + mario.width > myObject->x && mario.x + mario.width < myObject->x + myObject->height)){
            drawPreviousBackground_RocketBadguy(myObject);
            drawPreviousBackground_Mario();
            Status.lifes -= 1;

            if(level.level == 1){
                mario.x = 800;
                mario.y = 941;
                drawMove_Mario();
            }
            if(level.level == 2){
                mario.x = 0;
                mario.y = 470;
                drawMove_Mario();
            }
            if(level.level == 3){
                mario.x = 1520;
                mario.y = 941;
                drawMove_Mario();
            }
            if(level.level == 4){
                mario.x = 0;
                mario.y = 941;
                drawMove_Mario();
            }

            myObject->flag = 1;
        }
    }
}

