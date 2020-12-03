#include <stdlib.h>
#include "CacheSize.h"

double mainT, cacheT;

void* fetchMain (void* t){      // pulls data from main memory t times
	//int N = 10; // Number of bytes to allocate
	int *ptr;   // Pointer variable to store address
	int *r;
	struct timespec ts_begin, ts_end;
	double elapsed; 
	int temp;

	r = t;
	ptr = (int *) malloc(*r * sizeof(int));  // Allocate 10 * 4 bytes in memory
	clock_gettime(CLOCK_MONOTONIC, &ts_begin);
	for(int i = 0; i < *r; i++){
		temp = ptr[i];
	}
	clock_gettime(CLOCK_MONOTONIC, &ts_end);
	temp++;
	free(ptr);
	elapsed = (ts_end.tv_sec - ts_begin.tv_sec) * 1000000000.0;
	elapsed += (ts_end.tv_nsec - ts_begin.tv_nsec);// / 1000000000.0;
	mainT = (elapsed / *r);
	return NULL;
}

void* fetchCache (void* t){	// pulls data from cached memory t times
	//int N = *t; // Number of bytes to allocate
	int *ptr;   // Pointer variable to store address
	int *r;
	struct timespec ts_begin, ts_end;
	double elapsed; 
	int temp = 7;

	r = t;
	ptr = (int *) calloc(*r, sizeof(int));  // Allocate 10 * 4 bytes in memory
	for(int i = 0; i < *r; i++){
		temp = ptr[i];
	}
	clock_gettime(CLOCK_MONOTONIC, &ts_begin);
	for(int i = 0; i < *r; i++){
		temp = ptr[i];
	}
	clock_gettime(CLOCK_MONOTONIC, &ts_end);
	free(ptr);
	temp++;
	elapsed = (ts_end.tv_sec - ts_begin.tv_sec) * 1000000000.0;
	elapsed += (ts_end.tv_nsec - ts_begin.tv_nsec);// / 1000000000.0;
	cacheT = (elapsed / *r);
	return NULL;
}


int getSize (int* t){		// loops thru to determine the size of cache
	system("echo 3 > /proc/sys/vm/drop_caches");
	int* N = t; // Number of bytes to allocate
	int *ptr;   // Pointer variable to store address
	ptr = (int *) malloc(*N * sizeof(int));  // Allocate 10 * 4 bytes in memory
	if(ptr==NULL)  return 0;
	return ((*N)* sizeof(int));
}


float getBSize (void* t) {       // 
	float size = 0.0;
	return size;
}
