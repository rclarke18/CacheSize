#include <stdlib.h>
#include "CacheSize.h"

#define KB 1024
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


double getSize (int* t){		// loops thru to determine the size of cache
	//system("echo 3 > /proc/sys/vm/drop_caches");
	//int* N = t; // Number of bytes to allocate
	//int *ptr;   // Pointer variable to store address
	unsigned int steps = 512 * 1024 * 1024;
	double elapsed;
	struct timespec ts_begin, ts_end;
	static int arr[4 * 1024 * 1024];
    int lengthMod;
    unsigned int i;
	

    lengthMod = *t -1;
	clock_gettime(CLOCK_MONOTONIC, &ts_begin);
	for (i = 0; i < steps; i++) {
       arr[(i * 16) & lengthMod] *= 10;
       arr[(i * 16) & lengthMod] /= 10;
    }
	clock_gettime(CLOCK_MONOTONIC, &ts_end);
	elapsed = (ts_end.tv_sec - ts_begin.tv_sec) * 1000000000.0;
	elapsed += (ts_end.tv_nsec - ts_begin.tv_nsec);// / 1000000000.0;
	return (elapsed);
}


float getBSize() {       
	float size = 0.0;
	size = system("blockdev --getbsz /dev/sda1");
	return size;
}
