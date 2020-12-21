
// swap two elements
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

//create a max heap using the heapify method
void Maxheapify(vector<int>& arr, int n, int i) // O(Logn)
{
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest])     // 1
        largest = l;

    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest])    // 1
        largest = r;

    // If largest is not root 
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively Maxheapify the affected sub-tree 
        Maxheapify(arr, n, largest);//log(n)
    }
}

// Function that call heapify Max to build the Max-heap out of the givern array
void buildMaxHeap(vector<int>& arr, int n)   // O(nLogn)
{
    // Index of last non-leaf node 
    int startIdx = (n / 2) - 1;
    if (startIdx < 0)
        startIdx = 0;

    // Perform reverse level order traversal 
    // from last non-leaf node and heapify 
    // each node 
    for (int i = startIdx; i >= 0; i--) { // n
        Maxheapify(arr, n, i);            // logn
    }
}

//swaps the last element in the arr with the first one, and then shrinks
// the array by one element, then rearranges the array into MaxHeap
void deleteMax(vector<int>& arr, int& n)    // O(nLogn)
{
    swap(arr[0], arr[n - 1]);
    n--;
    buildMaxHeap(arr, n);                   // nLogn

}

//Print function of heap in an array format
void printHeap(vector<int> arr, int n)
{
    cout << "\nArray representation of Heap is:\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";

}

void AscHeapSort(vector<int> &arr, int n) {     //O(nLogn)

    cout << "The MaxHeap before sorting is: ";
    printHeap(arr, n);

    buildMaxHeap(arr, n);       //nLogn

    // Swap each element and then heapify th rest of the MaxHeap
    for (int i = n - 1; i > 0; i--)             //n
    {
        // Move current root to end 
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap 
        Maxheapify(arr, i, 0);                  //Logn
    }                                           //nLogn


    cout << "The array after sorting: \n";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n"; 

/////////////////////////////////////////////////////////////////////////////////////////////

   // ANOTHER (WORSE) SOLUTION DUE TO BIGGER TIME COMPLEXITY  O(n^2Logn)

   //buildMaxHeap(arr, n);      // nLogn

   // cout << "The MaxHeap before sorting is: ";
   // printHeap(arr, n);

   // while (n>0) {           //n
   //     deleteMax(arr, n);          // nLogn
   // }

   // cout << "The array after sorting: \n";
   // for (int i = 0; i < arr.size(); ++i)
   //     cout << arr[i] << " ";
   // cout << "\n";

}
