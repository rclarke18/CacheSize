# CacheSize  
Tool to determine Cache Size and Execution Speed  

### Cached Speed Test Function
Calls a cached data value in a comparator  
We call this function a set amount of times in order to get a more accurate average time of pulling from the cache.  

### Main Memory Speed Test Function
Calls a new data value from main memory to use in a comparator  
We call this function a set amount of times in order to get a more accurate average time of pulling from main.  

### Cache Size Funcion
Attempts to allocate larger and larger blocks of static memory to see the largest cache size allowed.  
 - we tried to first clear the cache via a shell script, but the necesarry command requires elevated privaleges.  
 - To run with clearing cache, uncomment out the line " //system("echo 3 > /proc/sys/vm/drop_caches");"  
 - Next ensure you are running as a super user  
 - finally type the command "make && ./CacheSize"  

### Cache Block Size Function 
Explanation  
