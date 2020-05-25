# Algorithms
## Sorting
1. [Heap-sort](https://github.com/abdel-elsayed/Algorithms/tree/master/Heap-Sort)
   - Comparing mechanism based on a binary heap structure
   - Typically takes O(nlogn) time complexity 
      - This is because it consists of two steps:  
        1)inserting into a heap O(nLogn) + 2) Deleting each item from the heap O(nLogn)   
   - __Pros__:  
   Has 𝑂(𝑛log𝑛) worst-case run time.  
   Can sort in-place so uses 𝑂(1) additional space.
   - __Cons__:  
   Unstable!  
   Still much slower than Quick Sort on average.  
   You still need to perform a swap on every element in the array, even if it’s already in the right place.
