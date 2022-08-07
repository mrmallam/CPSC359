//auction.c
//CPSC 359 Assignment 2
//February 16, 2022
//Mohammed Allam 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Initialize functions
void displayBidingProcess();
void *placeBid(void* id);
int upperBoundBid = 30;
void sortInDecendingOrder(int *numberOfThreads, int *arr);
clock_t begin;



// Shared structure object 
struct shared{
	int* bid; //bid[i] == j when bidder i has j as a bid
	bool* committed; // committed[i] is true when its a final bid
	bool auctionFinished; // when all commit[i] is true
	double* bidTime; // time taken to bid
	int* arrowcounter;

}shared;


// this function randomly chooses an empty cell, and a random number from 1 - 50
// and records the time each thread takes to place a bid
void* placeBid(void* id){
	// void to int
	int myid = *(int*)id;

	int bidsCount = 0;
	shared.committed[myid] = 0;
	shared.arrowcounter[myid] = 0;

	srand(time(NULL));
	while(bidsCount<upperBoundBid-1 && shared.committed[myid] != 1){

		// entering a temporary bid
		int tempBid = rand() % 51;
		shared.bid[myid] = tempBid + 1;

		// randomly deciding whether to commit a bid, or not 
		int randNumber1 = rand() % 5;
		int randNumber2 = rand() % 5;

		//sleep for random seconds
		int seconds = rand() % 4;
		sleep(seconds);

		if(randNumber1 != randNumber2 && bidsCount == upperBoundBid ){
			shared.committed[myid] = 1;
			break;
		}else if(randNumber1 == randNumber2){
			shared.committed[myid] = 1;
			break;
		}

		shared.arrowcounter[myid]++;
		bidsCount++;
	}

	// recording time
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	shared.bidTime[myid] = time_spent;

	return 0;
};

// this function sorts an array in decending order 
void sortInDecendingOrder(int *numberOfThreads, int *arr){
	int i, j, a;
	for (i = 0; i < *numberOfThreads; ++i) {
      for (j = i + 1; j < *numberOfThreads; ++j) {
          if (arr[i] < arr[j]) {
              a = arr[i];
              arr[i] = arr[j];
              arr[j] = a;
            }
        }
    }
}

// printing the bids to standard output 
void printValues(int *numberOfThreads, int *sortedArray, int *arrayCopy){

	int counter = 0;
	int i, j;
	char points[50] = ""; // stores the arrow process for each pthread

	for(i = 0; i < *numberOfThreads; ++i) {
    for(j = 0; j < *numberOfThreads; ++j) {

      if(sortedArray[i] == arrayCopy[j] ){
      	if(counter <= *numberOfThreads){ // to avoid duplication of outputs

	      	for(int k = 0; k < shared.arrowcounter[i]; k++){
	      		strcpy(&points[k], "-");
	      	}

	        if(shared.committed[i] == 0){
	        	printf("Bidder%d: %s> %d \n", j, points, sortedArray[i]);
	        	arrayCopy[j] = 0;
	        }

	        if(shared.committed[i] == 1){
	        	printf("Bidder%d: %s* %d\n", j, points, sortedArray[i]);
	        }
	        counter++;
	      }
      }
    }
	}
}

// this function organizes the bid display process 
void displayBiddingProcess(int *numberOfThreads){

	int sortedArray[*numberOfThreads], arrayCopy[*numberOfThreads], a, i, j;

	// making copies of the main array
	for(i = 0; i < *numberOfThreads; i++){
		sortedArray[i] = 0;
		arrayCopy[i] = 0;
		sortedArray[i] = shared.bid[i];
		arrayCopy[i] = shared.bid[i];
	}

	system("clear");
	sortInDecendingOrder(numberOfThreads, sortedArray); //sort the array 
	printValues(numberOfThreads, sortedArray, arrayCopy);
	printf("\n");
};

// checks if all bidders committed their bids
bool checkIfCommittedIsAllOnes(int *numberOfThreads){
	  for (int i = 0; i < *numberOfThreads; i++){
      if(shared.committed[i] != 1){
        return false;
      }
  }
  return true;
};

// main
int main(int argc, char *argv[]){
	int numberOfThreads;
	printf("Enter a number of desired threads (0 < n < 100): ");
	scanf("%d", &numberOfThreads);

	// checking for a valid input from user  
	while ( numberOfThreads > 100 || numberOfThreads < 0){
		printf("Please enter an integer greater than 0 and less than 100: ");
		scanf("%d", &numberOfThreads);
	}
	
	// declaring memory for each array 
	shared.bid = malloc(sizeof(int) * numberOfThreads);
	shared.committed = malloc(sizeof(bool) * numberOfThreads);
	shared.bidTime = malloc(sizeof(double) * numberOfThreads);
	shared.arrowcounter = malloc(sizeof(int) * numberOfThreads);


	// creating bidder threads based on user input 
	pthread_t bidder[numberOfThreads];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	long i = 0;
	for(i = 0; i < numberOfThreads; i++){
		pthread_create(&bidder[i], &attr, placeBid, &i);
		usleep(1000);
		printf("Pthread %ld has STARTED.\n", i);
		begin = clock();
	};


	shared.auctionFinished = 0;
	while(shared.auctionFinished == 0){

		displayBiddingProcess(&numberOfThreads);
		
		if(checkIfCommittedIsAllOnes(&numberOfThreads) == true){
			shared.auctionFinished = 1;	
		}
	};

	int sortedCopy[numberOfThreads], arr[numberOfThreads], winner;

	// making copies of the board for printing in a correct order.
	// this ensures each bid value gets printed with it's bidder index 
	for(i = 0; i < numberOfThreads; i++){
		sortedCopy[i] = shared.bid[i];
		arr[i] = shared.bid[i];
	}

	sortInDecendingOrder(&numberOfThreads, sortedCopy);

	printf("\nFinal Bids:\n");
	for (i = 0; i < numberOfThreads; ++i) {
	    for (int j = 0; j < numberOfThreads; ++j) {
	    	
	        if(sortedCopy[i] == arr[j]){
	        	if(winner == 0){
	        		printf("------------------------------------------\n");
	        		printf("The winner is Bidder%d with the bid of: %d\n", j, sortedCopy[i]);
	        		printf("------------------------------------------\n");
	        		winner = 1;

	        	}
	        	printf("Bidder[%d] = %d time = %.2f\n", j, sortedCopy[i], shared.bidTime[i]);
	        	arr[j] = 0;
	        }
	    }
	}
	printf("\n");

	// free up used memory 
	free(shared.bid);
	free(shared.committed);
	free(shared.bidTime);
	free(shared.arrowcounter);
	return 0;
};
