#include "headerMain.h"
// --------------------------- Button/SNES input ---------------------------
/*
    this file handles events when a button is pressed
*/


void Button_Pressed(){
    // You have pressed START
    if(mario.button == 4){
       if(Status.gameOver != 1 && Menu.flag == 0){ 
           Menu.flag = 1;
           Menu.up = 1;
           Timer.paused = 1;
           displayMidMenu();
        }        

        if(Status.gameOver || Status.gameWon == 1){
           restartToInitialState();
       }
    }

    else if(mario.button == 5){
        // You have pressed Joy-pad UP
        if(Menu.flag == 1){
            if(Menu.down == 1){
                Menu.down = 0;
            }
            Menu.up = 1;
            displayMidMenu();
        }

        if(Menu.flag != 1){
            drawPreviousBackground_Mario();
            mario.y -=80;
            if(mario.y < 1){
                mario.y = 0;
            }
            drawMove_Mario();
        }
        
    }
    else if(mario.button == 6 && Status.gameOver != 1){
        // You have pressed Joy-pad DOWN
        if(Menu.flag == 1){
            if(Menu.up == 1){
                Menu.up = 0;
            }
            Menu.down = 1;
            displayMidMenu();
        }

        if(Menu.flag != 1){
            drawPreviousBackground_Mario();
            mario.y +=80;
            if(mario.y > 930){
                mario.y = 941;
            }
            drawMove_Mario();
        }
    }
    else if(mario.button == 9){
        // You have pressed A
        if(Menu.down && Menu.flag == 1){
            Menu.flag = 0;
            Menu.terminate = 1;
        }
        if(Menu.up && Menu.flag == 1){
            Menu.up = 0;
            Timer.paused = 0;
            Menu.flag = 0;
            
            if(level.level == 1){
                level1Constructor();
            }
            if(level.level == 2){
                level2Constructor();
            }
            if(level.level == 3){
                level3Constructor();
            }
            if(level.level == 4){
                level4Constructor();
            }
        }
    }

    else if(mario.button == 7 && Status.gameOver != 1){
        // You have pressed Joy-pad LEFT
        if(Menu.flag != 1){
            drawPreviousBackground_Mario();
            mario.x -=80;
            if(mario.x < 1){
                mario.x = 0;
            }
            drawMove_Mario();
        }
    }

    else if(mario.button == 8 && Status.gameOver != 1){
        // You have pressed Joy-pad RIGHT
        if(Menu.flag != 1){
            drawPreviousBackground_Mario();
            mario.x +=80;
            if(mario.x > 1527){
                mario.x = 1527;
            }
            drawMove_Mario();
        }
    }
    
    else if(mario.button == 3){
        // You have pressed Select
        if(Status.gameOver || Status.gameWon == 1){
            Menu.terminate = 1;
        }
    }
    
    else if(mario.button == 10){
        // You have pressed X
    }
    else if(mario.button == 11){
        // You have pressed Left
    }
    else if(mario.button == 12){
        // You have pressed Right
    }
    else if(mario.button == 1){
        // You have pressed B
    }
    else if(mario.button == 2){
        // You have pressed Y
    }
}


