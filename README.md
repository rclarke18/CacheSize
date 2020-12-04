# CacheSize  
Tool to determine Cache Size and Execution Speed  

### Cached Speed Test Function
Allocates memory for an array of size chosen by the user (we used 10,000). It then cycles through pulling the array into cached memory. We then time our loop back through the cached array and average the time each read took.  

### Main Memory Speed Test Function
Follows the same theory as the cached speed test, but instead of caching the array, we simply record the time it takes on the first read from main memory.  

### Cache Size Funcion
Attempts to allocate larger and larger blocks of static memory to see the largest cache size allowed.  
 - the largest cache size is determined by comparing the time required to read/write to cache memory. If the write takes longer than average we assume the memory forced into slower main memory  
 - we tried to first clear the cache via a shell script, but the necesarry command requires elevated privaleges.  
 - To run with clearing cache, uncomment out the line " //system("echo 3 > /proc/sys/vm/drop_caches");"  
 - Next ensure you are running as a super user  
 - finally type the command "make && ./CacheSize"  

### Cache Block Size Function 
 Returns the size of block stored on the L1 cached memory by checking the size peremiter  
