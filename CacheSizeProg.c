// This is the main file for running our code
#include <stdlib.h>    // for exit()
#include <sys/types.h>
#include <sys/wait.h>  // for waitpid()
#include <time.h>
#include <pthread.h>	// for pthread_create()
#include <stdio.h>     // for printf()
#include "CacheSize.h"

#define KB 1024
#define MB 1024 * 1024

int main(int argc, char** argv){
	int runs = 100000;
	pthread_t th_cacheSpeed, th_mainSpeed; 
	int sizes[] = { 
        1 * KB, 4 * KB, 8 * KB, 16 * KB, 32 * KB, 64 * KB, 128 * KB, 256 * KB,
        512 * KB, 1 * MB, 1.5 * MB, 2 * MB, 2.5 * MB, 3 * MB, 3.5 * MB, 4 * MB, 5.0 * MB
    };
  //  int largest = 0;

	pthread_create(&th_cacheSpeed, NULL, fetchCache, (void*)&runs);
	pthread_create(&th_mainSpeed, NULL, fetchMain, (void*)&runs);

	pthread_join(th_cacheSpeed, NULL);
	pthread_join(th_mainSpeed, NULL);

	printf("\nCached Memory Fetch Average Speed : %f  ns\nMain Memory Fetch Average Speed : %f  ns\n", cacheT,mainT);

	for (int i = 0; i < sizeof(sizes)/sizeof(int);i++){
		double timeTaken = getSize(&sizes[i]);
		if (timeTaken > cacheT)
			printf("Cache Memory Size : %d Bytes\n", sizes[i-1]);
		break;
	}
	

	return 1;
}