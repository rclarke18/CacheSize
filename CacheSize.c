#include "CacheSize.h"


double fetchMain (void* t){      // pulls data from main memory t times
	int N = 10; // Number of bytes to allocate
	int *ptr;   // Pointer variable to store address
	int *r;
	struct timespec ts_begin, ts_end;
	double elapsed; 

	r = t;
	ptr = (int *) malloc(N * sizeof(int));  // Allocate 10 * 4 bytes in memory
	clock_gettime(CLOCK_MONOTONIC, &ts_begin);
	for(int i = 0, i < *r, i++){
		temp = ptr[i];
	}
	clock_gettime(CLOCK_MONOTONIC, &ts_end);
	free(ptr);
	elapsed = ts_end.tv_sec - ts_begin.tv_sec;
	elapsed += (ts_end.tv_nsec - ts_begin.tv_nsec) / 1000000000.0;
	return elapsed/&t;
}

double fetchCache (void* t){	// pulls data from cached memory t times
	int N = &t; // Number of bytes to allocate
	int *ptr;   // Pointer variable to store address
	int *r;
	struct timespec ts_begin, ts_end;
	double elapsed; 
	int temp = 7;

	r = t;
	ptr = (int *) calloc(N * sizeof(int));  // Allocate 10 * 4 bytes in memory
	for(int i = 0, i < *r, i++){
		temp = ptr[i];
	}
	clock_gettime(CLOCK_MONOTONIC, &ts_begin);
	for(int i = 0, i < *r, i++){
		temp = ptr[i];
	}
	clock_gettime(CLOCK_MONOTONIC, &ts_end);
	free(ptr);
	elapsed = ts_end.tv_sec - ts_begin.tv_sec;
	elapsed += (ts_end.tv_nsec - ts_begin.tv_nsec) / 1000000000.0;
	return elapsed/&t;
}


int getSize (int* t){		// loops thru to determine the size of cache
	int N = &t; // Number of bytes to allocate
	int *ptr;   // Pointer variable to store address

	ptr = (int *) malloc(N * sizeof(int));  // Allocate 10 * 4 bytes in memory
	if(ptr==NULL)  return 0;
	return ((N)* sizeof(int));
}


float getBSize (void* t) {       // 

}
