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
 - won't work: could hit another cached value and throw smaller array size than actually possible    

### Cache Block Size Function 
Explanation  
