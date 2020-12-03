#ifndef CacheSize_impl_h
#define CacheSize_impl_h

#include <pthread.h>
#include <time.h>
#include <stdio.h>     // for printf()
#include <stdlib.h>    // for exit()
#include <sys/types.h>
#include <sys/wait.h>  // for waitpid()

double fetchMain (void* t);      // pulls data from main memory
double fetchCache (void* t);	// pulls data from cached memory
float getSize (void* t);		// loops thru to determine the size of cache 
float getBSize (void* t);

#endif // CacheSize_impl_h
