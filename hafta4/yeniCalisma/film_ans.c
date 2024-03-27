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

/* DECLARE YOUR FUNCTION PROTOTYPES HERE */

void list(RECORD_t* rec, int start, int end);
void find(RECORD_t* rec, RECORD_t* res, int id);
void update(RECORD_t* rec, int id, char *descr, unsigned int ryear);
void print(RECORD_t* res);

int main(){
	RECORD_t* rec = (RECORD_t *)malloc(sizeof(RECORD_t)*MAX);  //Do not edit this line.
	FILE *file = fopen("./data.txt", "rb");             //Do not edit this line.
	if (file == NULL) {                                 //Do not edit this line.
		perror("Error");                                //Do not edit this line.
		exit(0);                                        //Do not edit this line.
	}                                                   //Do not edit this line.
	fread(rec, sizeof(RECORD_t)*MAX, 1, file);          //Do not edit this line.
	fclose(file);                                       //Do not edit this line.

	/**************************/
	/* Your code starts here. */
	/**************************/

	RECORD_t* result;
	result = malloc(sizeof(RECORD_t));

	list(rec, 0, 1000);
	find(rec, result, 5);
	update(rec, 1, "berkan movie's", 2020);
	list(rec, 0, 1000);

	//...

	/**************************/
	/* Your code ends here.   */
	/**************************/

	file = fopen("data-out.txt", "wb");                 //Do not edit this line.
	fwrite(rec, sizeof(RECORD_t)*MAX, 1, file);         //Do not edit this line.
	fclose(file);                                       //Do not edit this line.
	free(rec);                                          //Do not edit this line.
	return 1;                                           //Do not edit this line.
}

/* IMPLEMENT YOUR FUNCTIONS HERE */

void list(RECORD_t* rec, int start, int end){
	int i;
	for (i = start; i < end; i++) {
		printf("%d %s\n", rec[i].film_id, rec[i].title);
	}
}

void print(RECORD_t* res){
	printf("ID: %d\n", res[0].film_id);
	printf("TITLE: %s\n", res[0].title);
	printf("DESCRIPTION: %s\n", res[0].description);
	printf("RELEASE YEAR: %d\n", res[0].release_year);
	printf("RENTAL DURATION: %d\n", res[0].rental_duration);
	printf("RENTAL RATE: %f\n", res[0].rental_rate);
	printf("REPLACEMENT COST: %f\n", res[0].replacement_cost);
	printf("RATING: %s\n", res[0].rating);
	printf("LAST UPDATE: %s\n", res[0].last_update);
}

void find(RECORD_t* rec, RECORD_t* res, int id){
	int i;
	for (i = 0; i < MAX; ++i) {
		if (rec[i].film_id == id) {
			*res = rec[i];
			i = MAX;
		}
	}
}

// updates the description and release year of the film with the given id
void update(RECORD_t* rec, int id, char *descr, unsigned int ryear){
	int realIndx = id - 1;
	strcpy(rec[realIndx].description, descr);
	rec[realIndx].release_year= ryear;
	/*
	 *
	 *
	 */
}

