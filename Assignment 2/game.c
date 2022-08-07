//game.c
//CPSC 359 Assignment 2
//February 16, 2022
//Mohammed Allam

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>


// Initialize functions
void initialize_game_board();
void display_game_board();
void *playGame(void *id);
int determineTheWinnerOrDraw();
void decideMove();
void setTurnToNextPlayer();
void checkIfBoardIsFull();
int checkIfWinner();



// Shared structure object between threads 
struct shared {
	char **board;
	int turn;
	bool gameBoardIsFull;
	bool gameOn;
	bool isWinner;
	int arrId1[3][3];
	int arrId2[3][3];
	int theWinnerIs;
};
// Create struct named s
struct shared s;


// Dynamically allocating memory for the game board (2d array)
void initialize_game_board(){
	//Local variable
	int i;
	s.board = malloc(sizeof(int*) * 3);
	for(i = 0; i<3; i++){
		s.board[i] = malloc((sizeof(int) * 3));
	};
}

// Displays the board
void display_game_board(){

	// Local variables
	int i, j, count = 0;

	// For loops to display a 3x3 board
	for(i = 0; i<3; i++){
		printf("\n");
		for(j = 0; j<3; j++){
			printf("[%d] = %d\t", count, s.board[i][j]);
			count++;
		}
	}

	printf("\n");
	printf("\n");
}




// The decideMove function picks a number and decides which cell to place it in
void decideMove(int* randomNumber, int* rowsRand, int* coloumnRand){
	//Using the internal clock
	srand(time(NULL));

	// Local variables
	int i,j, numberIsTaken = 1, cellIsOccupied = 1, num0, num1, randFromZeroToNine;

	// Loop until we find an unused random number
	while(numberIsTaken == 1){

		// Pick a number from 1-9
		randFromZeroToNine = rand() % 9;
		randFromZeroToNine++;
		numberIsTaken = 0; 
		// Decide if the number is already taken
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				if(randFromZeroToNine == s.board[i][j]){
					numberIsTaken = 1;
				}
			}
		}

		// Break the loop if the number is not taken
		if(numberIsTaken != 1){
			numberIsTaken = 0;
			break;
		}

	}
	// Loop until we find an unused cell
	while(cellIsOccupied == 1){

		// Randomly pick a cell location (0-8)
		num0 = rand() % 3;
		num1 = rand() % 3;

		// See if the board is empty at that cell location
		if(s.board[num0][num1] == 0){
			cellIsOccupied = 0;
		}
	}

	// Set pointers for the cell number and scrabble value
	*randomNumber = randFromZeroToNine;
	*rowsRand = num0;
	*coloumnRand = num1;
}



// Checks if there is a winner 
int checkIfWinner(){
	int i, j, k;

	// Checking the Vertical Columns for a Win
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			k = 0;
			// See if there is a winner
			if((s.board[k][j] + s.board[k+1][j] + s.board[k+2][j]) == 15){

				// Determine if Player 1 is the winner
				if(s.board[k][j] == s.arrId1[k][j] &&  s.board[k+1][j] == s.arrId1[k+1][j] && s.board[k+2][j] == s.arrId1[k+2][j]){
					s.theWinnerIs = 1;
					s.isWinner = 1;
					return 0;
				}
				// Else Player 2 is the winner
				else{
					s.theWinnerIs = 2;
					s.isWinner = 1;
					return 0;
				}
			}
		}
	}

	// Checking the Horizontal Rows for a Win
	for(i = 0; i < 3; i++){
		for(k = 0; k < 3; k++){
			j = 0;
			// See if there is a winner
			if((s.board[k][j] + s.board[k][j+1] + s.board[k][j+2]) == 15){

				// Determine if Player 1 is the winner
				if(s.board[k][j] == s.arrId1[k][j] &&  s.board[k][j+1] == s.arrId1[k][j+1] && s.board[k][j+2] == s.arrId1[k][j+2]){
					s.theWinnerIs = 1;
					s.isWinner = 1;
					return 0;
				}
				// Else Player 2 is the winner
				else{
					s.theWinnerIs = 2;
					s.isWinner = 1;
					return 0;
				}
			}
		}
	}

	// Checking the Diagonals for a Win 

	// Check Diagonal from top left to bottom right, see if there is a winner
	if((s.board[0][0] + s.board[1][1] + s.board[2][2]) == 15){

		// Determine if Player 1 is the winner
		if(s.board[0][0] == s.arrId1[0][0] &&  s.board[1][1] == s.arrId1[1][1] && s.board[2][2] == s.arrId1[2][2]){
			s.theWinnerIs = 1;
			s.isWinner = 1;
			return 0;
		}
		// Else Player 2 is the winner
		else{
			s.theWinnerIs = 2;
			s.isWinner = 1;
			return 0;
		}
	}
	// Check Diagonal from bottom left to top right, see if there is a winner
	else if((s.board[0][2] + s.board[1][1] + s.board[2][0]) == 15){

		// Determine if Player 1 is the winner
		if(s.board[0][2] == s.arrId1[0][2] &&  s.board[1][1] == s.arrId1[1][1] && s.board[2][0] == s.arrId1[2][0]){
			s.theWinnerIs = 1;
			s.isWinner = 1;
			return 0;
		}
		// Else Player 2 is the winner
		else{
			s.theWinnerIs = 2;
			s.isWinner = 1;
			return 0;
		}
	}
	return 0;
}

// Determine whether the board is full
void checkIfBoardIsFull(){
	int i, j;

	// For loop if every cell in the 3x3 is full or empty
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(s.board[i][j] == 0){
				s.gameBoardIsFull = 0;
			}
			else{
				s.gameBoardIsFull = 1;
			}
		}
	}
}

//	Determine if there is a winner or a draw
int determineTheWinnerOrDraw(){

	// True if there exists a winner
	if(s.isWinner == 1){
		printf("The winner is player %d\n", s.theWinnerIs);
	}

	// True if the board is full and no one is a winner
	else if(s.gameBoardIsFull == 1 && s.isWinner == 0){
		printf("Its a draw!!\n");
		return 0;
	}
	return 0;
}

// // Pthread main function 
void *playGame(void* id){
	//	Local variables
	int randomNumber, rowsRand, coloumnRand;

	//	Using the pointer to find myID
	int myid = *(int*)id;

	// Infinite loop until break
	while(1){
		// Wait for Player's turn
		while(s.turn != myid){

			// Call decideMove for move information
			decideMove(&randomNumber, &rowsRand, &coloumnRand);

			// Assign move to Player 1 or 2
			if(myid == 1){
				s.arrId1[rowsRand][coloumnRand] = randomNumber;
			}
			else if(myid == 2){
				s.arrId2[rowsRand][coloumnRand] = randomNumber;
			}
			// Enter Player's move to the shared board
			s.board[rowsRand][coloumnRand] = randomNumber;
			
			// Set turn to 0
			s.turn = 0;
		}
	}
	return 0;
}


// MAIN()
int main(int argc, char *argv[]){

	// Initializing memory for a dynamically allocated 2d-array 
	initialize_game_board();

	// Local variables 
	long one = 1;
	long two = 2; 
	s.gameOn = 1;

	// Set turn to 0 (main thread's turn)
	s.turn = 0;	

	// Creating two player threads with IDs 1 and 2
	pthread_t tid1, tid2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid1, &attr, playGame, &one);
	pthread_create(&tid2, &attr, playGame, &two);


	usleep(1000);
	// Play until game is over
	while(s.gameOn == 1){
		while(s.turn == 0){ 
			// Call game specific functions
			display_game_board();
			checkIfWinner();
			checkIfBoardIsFull();

			// Cancel the pthreads, stop the game when the game is over
			if(s.isWinner == 1 || s.gameBoardIsFull == 1){
				pthread_cancel(tid1);
				pthread_cancel(tid2);
				determineTheWinnerOrDraw();
				s.gameOn = 0;
				break;
			}
			// Continue the game if it is not yet over, switch to next player
			else{
				if(s.turn == 1){
					s.turn = 2;
				}
				else if(s.turn == 2){
					s.turn = 1;
				}
			}
		}
	}

	printf("\n");

	// Freeing up Board's memory
	for(int i = 0; i < 3; i++){
		free(s.board[i]);
		s.board[i] = NULL;
	}
	free(s.board);
	s.board = NULL;

	return 0;
}



