#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000
#define FILE_PATH_RECORDS ???
#define FILE_PATH_FILTERED_RECORDS ???

typedef struct {
	int film_id;
	char title[255];
	char description[1023];
	unsigned int release_year;
	int rental_duration;
	float rental_rate;
	unsigned char length;
	float replacement_cost;
	char rating[10];
	char last_update[30];
} RECORD_t;

// utility functions
RECORD_t* read_records(const char* file_path);

RECORD_t* filter_by_rental_rate(RECORD_t* rec, size_t* size, float min_rate, float max_rate);
RECORD_t* filter_by_rental_duration(RECORD_t* rec, size_t* size, int min_duration, int max_duration);
RECORD_t* filter_by_length(RECORD_t* rec, size_t* size, unsigned char min_length, unsigned char max_length);

RECORD_t* sort_by_rental_rate(RECORD_t* rec, size_t* size);
RECORD_t* sort_by_rental_duration(RECORD_t* rec, size_t* size);
RECORD_t* sort_by_length(RECORD_t* rec, size_t* size);


void print_record(RECORD_t* rec, size_t size);
void write_records(const char* file_path, RECORD_t* rec, size_t size);

// Find records by title no match case matching find by sub string

int main(void) {
	// Read records from file
    size_t filtered_rec_size = MAX;
    RECORD_t* rec_filtered = read_records("FILE_PATH_RECORDS");



    //Filter records by rental rate and rental duration
    rec_filtered = filter_by_rental_duration(rec_filtered, &filtered_rec_size, 3, 4);
    rec_filtered = filter_by_length(rec_filtered, &filtered_rec_size, 90, 110);

    // Sort rec_filtered by length
    rec_filtered = sort_by_length(rec_filtered, &filtered_rec_size);
    //rec_filtered = sort_by_rental_duration(rec_filtered, &size);


    // Print filtered records
    print_record(rec_filtered, filtered_rec_size);
    write_records("FILE_PATH_FILTERED_RECORDS", rec_filtered, filtered_rec_size);

    // Free memory
	free(rec_filtered);

	// Wait for key press
	printf("Press any key to continue...");
	getchar();

	return EXIT_SUCCESS;
}

// Print all records
void print_record(RECORD_t* rec, size_t size) {

}

// Filter records by release year
RECORD_t* filter_by_rental_rate(RECORD_t* rec, size_t *size, float min_rate, float max_rate) {

}

// Filter records by rental duration
RECORD_t* filter_by_rental_duration(RECORD_t* rec, size_t* size, int min_duration, int max_duration) {

}

// Filter records by length
RECORD_t* filter_by_length(RECORD_t* rec, size_t* size, unsigned char min_length, unsigned char max_length) {
    
}

// Sort records by rental rate
RECORD_t* sort_by_rental_rate(RECORD_t* rec, size_t* size) {
    
}

// Sort records by rental duration
RECORD_t* sort_by_rental_duration(RECORD_t* rec, size_t* size) {
    
}

// Sort records by length
RECORD_t* sort_by_length(RECORD_t* rec, size_t* size) {
   
}

// Read records from file in binary mode
RECORD_t* read_records(const char* file_path) {
    
}

// Write records to file in text mode
void write_records(const char* file_path, RECORD_t* rec, size_t size) {
    
}