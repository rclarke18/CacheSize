// This is the main file for running our code
#include <stdlib.h>    // for exit()
#include <sys/types.h>
#include <sys/wait.h>  // for waitpid()
#include <time.h>
#include <pthread.h>	// for pthread_create()
#include <stdio.h>     // for printf()
#include "CacheSize.h"

int main(int argc, char** argv){
	int runs = 100000;
	pthread_t th_cacheSpeed, th_mainSpeed; 

	pthread_create(&th_cacheSpeed, NULL, fetchCache, (void*)&runs);
	pthread_create(&th_mainSpeed, NULL, fetchMain, (void*)&runs);

	pthread_join(th_cacheSpeed, NULL);
	pthread_join(th_mainSpeed, NULL);

	printf("Cached Memory Fetch Average Speed : %f  ns\n  Main Memory Fetch Average Speed : %f  ns\n", cacheT,mainT);

	return 1;
}