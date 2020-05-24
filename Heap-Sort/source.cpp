#include <iostream>
#include "HeapSort.h"
#include <vector>

using namespace std;
   
int main()
{
    vector<int> arr = {1,44,55,3,3,98,45,25,45,35,23,7,22,9,22,3,0,6,3,7,55,33,36,75};

    int n = arr.size();


    AscHeapSort(arr, n);

    return 0;
    
}
