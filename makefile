CC = gcc
CFLAGS =-pthread -Wall -lrt
LASTNAME=Clarke

all: CacheSize 

CacheSize: CacheSize.h CacheSize.c CacheSizeProg.c 
	$(CC) $(CFLAGS) -o CacheSize CacheSize.h CacheSize.c CacheSizeProg.c