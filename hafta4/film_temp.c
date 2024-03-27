#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000                                        //Do not edit this macro.

typedef struct{
	int film_id;
	char title[255];
	char description[1023];
	unsigned int release_year;
	char rental_duration;
	float rental_rate;
	unsigned char length;
	float replacement_cost;
	char rating[10];
	char last_update[30];
} RECORD_t;                                    //Do not edit this struct.

/* CREATE 4 PROTOTYPES FUNCTIONS HERE */

/* FUNCTION 1: LISTS RECORDS FROM STARTING INDEX TO ENDING INDEX*/
/* FUNCTION 2: FINDS FILM RECORDS BY THEIR'S ID NUMBER*/
/* FUNCTION 3: UPDATES RECORD'S description AND release_year*/
/* FUNCTION 4: PRINTS RECORDS */

void list(RECORD_t* rec, int start, int end);
void find(RECORD_t* rec, RECORD_t res, int id);
void update(RECORD_t* rec, int id, char *descr, unsigned int ryear);
void print(RECORD_t* res);


int main(){
	// PART 1
	// Step 1: Allocate memory for the records. You will need to read the records from the file and store them in an array of RECORDs.
	// Step 2: Read the records from the binary file.
	// Step 3: Check if the file was opened successfully.
	// Step 4: Read the records from the file.
	// Step 5: Close the records file when you done reading.

	/**************************/
	/* Use your funtions here */
	/**************************/
	// PART 2

	/**************************/
	/* Use your funtions here */
	/**************************/

	// PART 3
	// Step 1: Open new binary file for writing updated records.
	// Step 2: Write the updated records to the new file.
	// Step 3: Close the file.
	// Step 4: Free the memory allocated for the records.
	// Step 5: Exit the program.
}

/* IMPLEMENT YOUR FUNCTIONS HERE */


void list(RECORD_t* rec, int start, int end){

}

void print(RECORD_t* res){

}

void find(RECORD_t* rec, RECORD_t *res, int id){

}

void update(RECORD_t* rec, int id, char *descr, unsigned int ryear){
	
}