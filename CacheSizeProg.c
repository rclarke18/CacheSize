// This is the main file for running our code
#include "CacheSize.h"

int main(int argc, char** argv){
	int runs = 10000;
	pthread_t th_cacheSpeed, th_mainSpeed; 

	pthread_create(&th_cacheSpeed, NULL, fetchCache, &runs);
	pthread_create(&th_mainSpeed, NULL, fetchMain, &runs);

	pthread_join(th_cacheSpeed, NULL);
	pthread_join(th_mainSpeed, NULL);

	return 1;
}