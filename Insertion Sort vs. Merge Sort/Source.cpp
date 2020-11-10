#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <vector> 
#include <random>
using namespace std;

// global variables to calculate the steps needed for each sort algorithm
long long countStepsMerge = 0; 
long long countStepsInsertion = 0;

void alreadySorted(int*); // Calculating the time taken to sort the already sorted array.
                            // takes the array of n's as a parameter and calculates the time for each n

void reverselySorted(int*); // Calculating the time taken to sort the reversely sorted array.
                             // takes the array of n's as a parameter and calculates the time for each n.

void  randomPermutation(int* ns); //Calculating the time taken to sort the array containing 
                                  //random permutation of numbers in the array.
                                    // takes the array of n's as a parameter and calculates the time for each n.

void  fiftyRandomInstances(int* ns); // creating 50 instances of the n element in the array and 
                                    //calculating the sortin time

void menu();  // a driver menu to allow the user which case of sorting to choose from
void insertionSort(vector<int>&, int); // insertion sort
void mergeSort(vector<int>& arr, int l, int r); // dividing the vector into smaller vectors that can be sorted
void merge(vector<int>& arr, int l, int m, int r); // mergin together the smaller arrays produced from mergeSort function


int main()
{
    menu();
    return 0;
}


void menu() {

    int ns[8] = {100,200,300,400,500,1000,4000,10000}; // array that holds the different values of n
    int choice; // the user choice from the 4 options of the assignment 
    do {
        cout << "Welcome to the sort algorithms time calculator:\n";
        cout << "Please choose one option from the following\n";
        cout << "1. Already sorted Array\n2. Reversely sorted\n3. Random permutation\n4. 50 instances of n random numbers\n";
        cin >> choice;
        switch (choice)
        {
        case 1: alreadySorted(ns);
            break;
        case 2: reverselySorted(ns);
            break;
        case 3: randomPermutation(ns);
            break;
        case 4: fiftyRandomInstances(ns);
            break;
        default: cout << "ERROR!" << endl;
        }
    } while (choice != 0);
}

void  alreadySorted(int* ns) {

    vector<int> arr;
    //int x = capacity;
    clock_t time_req_insertion, time_req_merge;
   
    for (int k = 0; k < 8; k++)
    {
        cout << "---------------------------------------------------";
        cout << "\nn = " << ns[k] << endl;

        int capacity = ns[k];

        for (int i = 0; i < capacity; i++) {  // ascending order

            arr.push_back(i);
        }

        //calculating the time for the insertion sort algorithm
        countStepsInsertion = 0;
        time_req_insertion = clock();
        insertionSort(arr, capacity);
        time_req_insertion = clock() - time_req_insertion;
        cout << endl << "Number of steps for insertion sort is: --> " << countStepsInsertion ;
        
        //calculating the time for the merge sort algorithm
        countStepsMerge = 0;
        time_req_merge = clock();
        mergeSort(arr, 0,arr.size()-1);
        time_req_merge = clock() - time_req_merge;
        cout << endl << "Number of steps for merge sort is: --> " << countStepsMerge << endl << endl;


        cout << "Using insertion sort for n= " << ns[k] << ", it took --->" << (float)time_req_insertion / CLOCKS_PER_SEC << " seconds" << endl;
        cout << "Using merge sort for n= " << ns[k] << ", it took --->" << (float)time_req_merge / CLOCKS_PER_SEC << " seconds" << endl << endl;

        arr.clear();
    }

    cout << "---------------------------------------------------\n";
}

void  reverselySorted(int* ns) {

    vector<int> arr;
    clock_t time_req_insertion; // time taken by the insertion sort function
    clock_t time_req_merge;

    for (int k = 0; k < 8; k++)
    {
        int capacity = ns[k]; // capacity holds the n amount that is about to be tested
        int x = capacity; // setting the variable x = capacity to use in filling the array

       for (int i = 0; i < capacity; i++){  // descending order
            arr.push_back(x--);
       }
        
        countStepsInsertion = 0;
        time_req_insertion = clock();
        insertionSort(arr, capacity);
        time_req_insertion = clock() - time_req_insertion;
        cout << "---------------------------------------------------";
        cout << "\nn = " << ns[k] << endl;
        cout << endl << "Number of steps for insertion sort is: --> " << countStepsInsertion;

        arr.clear(); // clearing the vector in order to fill it again in the reversed sorted order
        x = capacity; // setting x back to the original amount of capacity


        for (int i = 0; i < capacity; i++)  // refilling the vector in the reversed order
        {
            arr.push_back(x--);
        }

        countStepsMerge = 0;
        time_req_merge = clock(); 
        mergeSort(arr, 0, arr.size() - 1);
        time_req_merge = clock() - time_req_merge;
        cout << endl << "Number of steps for merge sort is: --> " << countStepsMerge << endl<< endl;

        
        cout << "Using insertion sort for n= " << ns[k] << ", it took --->" << (float)time_req_insertion / CLOCKS_PER_SEC << " seconds" << endl;
        cout << "Using merge sort for n= " << ns[k] << ", it took --->" << (float)time_req_merge / CLOCKS_PER_SEC << " seconds" << endl<< endl;
        arr.clear();
    }
    cout << "---------------------------------------------------\n";
}


void  randomPermutation(int* ns) {

    vector<int> arr;
    clock_t time_req_insertion;
    clock_t time_req_merge;

    for (int k = 0; k < 8; k++)
    {
        int capacity = ns[k];

        for (int i = 0; i < capacity; i++) { 

            arr.push_back(i);
        }
      
        random_shuffle(arr.begin(), arr.end()); // random shuffling of the sorted array(produces no duplication)
        

        countStepsInsertion = 0;
        time_req_insertion = clock();
        insertionSort(arr, capacity);
        time_req_insertion = clock() - time_req_insertion;
        cout << "---------------------------------------------------";
        cout << "\nn = " << ns[k] << endl;
        cout << endl << "Number of steps for insertion sort is: --> " << countStepsInsertion;


        random_shuffle(arr.begin(), arr.end()); // random shuffling of the sorted array again to use it in
                                                // the merge sort function

        countStepsMerge = 0;
        time_req_merge = clock();
        mergeSort(arr, 0, arr.size() - 1);
        time_req_merge = clock() - time_req_merge;
        cout << endl << "Number of steps for merge sort is: --> " << countStepsMerge << endl << endl;

        cout << "Using insertion sort for n= " << ns[k] << ", it took --->" << (float)time_req_insertion / CLOCKS_PER_SEC << " seconds" << endl;
        cout << "Using merge sort for n= " << ns[k] << ", it took --->" << (float)time_req_merge / CLOCKS_PER_SEC << " seconds" << endl << endl;
        arr.clear();
    }
    cout << "---------------------------------------------------\n";
}

/**
this function creates a vector, and iterates through the array for the amount of n's
and for every n in the array, it creates a sorted array. Then it loops for 50 times through the sorted vector,
random shuffles the array and then insertion-sorts it while calculating the total time it is taking.
and then repeats the same process for the merge sort algorithm.
*/
void  fiftyRandomInstances(int* ns) {

    vector<int> arr;
    clock_t time_req_insertion;
    clock_t time_req_merge;
    float totalTimeInsertion = 0;
    float totalTimeMerge = 0;

    for (int k = 0; k < 8; k++)
    {
        cout << "---------------------------------------------------";
        cout << "\nn = " << ns[k] << endl;
        int capacity = ns[k];
        for (int i = 0; i < capacity; i++) {  // sorted array

               arr.push_back(i);
         }

        countStepsInsertion = 0;
        for (int j = 0; j < 50; j++) {

            random_shuffle(arr.begin(), arr.end()); // random permutation
            
            time_req_insertion = clock();
            insertionSort(arr, capacity);
            time_req_insertion = clock() - time_req_insertion;
            totalTimeInsertion += (float)time_req_insertion / CLOCKS_PER_SEC;
        } cout << endl << "Number of steps for insertion sort is: --> " << countStepsInsertion / 50 << endl << endl;


        

        countStepsMerge = 0;
        for (int j = 0; j < 50; j++) {

            random_shuffle(arr.begin(), arr.end()); // random permutation

            time_req_merge = clock();
            mergeSort(arr, 0,arr.size()-1);
            time_req_merge = clock() - time_req_merge;
            totalTimeMerge += (float)time_req_merge / CLOCKS_PER_SEC;
        } cout << endl << "Number of steps for merge sort is: --> " << countStepsMerge/50 << endl << endl;


        cout << "Using insertion sort for n= " << ns[k] << ", it took ---> " << totalTimeInsertion/50  << " seconds" << endl;
        cout << "Using merge sort for n= " << ns[k] << ", it took --->" << totalTimeMerge/50 << " seconds" << endl<<endl;
        arr.clear();
    }
    cout << "---------------------------------------------------\n";

}

void insertionSort(vector<int> &arr, int n)
{
    
    int key, j;  
    countStepsInsertion += 3;// counting the two declarations above(key,j) and the one declaration below(int i=1) 
    for (int i = 1; i < n; i++) // n-1
    {
        countStepsInsertion += 2;// counting the (i<n, i++) steps
        key = arr[i]; //n-1
        j = i - 1; //n-1
        countStepsInsertion += 2;// counting (key = arr[i], j = i - 1)

        while (j >= 0 && arr[j] > key) {  //n-1
            
            countStepsInsertion += 2;// counting (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j];
            j = j - 1;
          
            countStepsInsertion += 2;// counting (arr[j + 1] = arr[j], j = j - 1;)

        }countStepsInsertion++;

        arr[j + 1] = key; //n-1
        countStepsInsertion++; //  counting arr[j + 1] = key;
    }countStepsInsertion++;

}

void mergeSort(vector<int>& arr, int l, int r) {
   

    countStepsMerge++;
    if (l < r) {

        int m = l + (r - l) / 2;
        countStepsMerge++;
        mergeSort(arr, l, m);
        countStepsMerge++;
        mergeSort(arr, (m + 1), r);
        countStepsMerge++;
    
         merge(arr, l, m, r);
        countStepsMerge++;
    }countStepsMerge++;
    
}

void merge(vector<int>& arr, int l, int m, int r)
{

    int i, j, k;
    countStepsMerge += 3;
    int n1 = m - l + 1;
    int n2 = r - m;
    countStepsMerge += 2;

    vector<int> L;
    vector<int> R;
    countStepsMerge += 2;

    countStepsMerge++;
    for (i = 0; i < n1; i++) {
        countStepsMerge += 2;
        L.push_back(arr[l + i]);
        countStepsMerge++;

    }countStepsMerge++;
        
    countStepsMerge++;
    for (j = 0; j < n2; j++) {
        countStepsMerge += 2;
        R.push_back(arr[m + 1 + j]);
        countStepsMerge++;
    }countStepsMerge++;

    i = 0;
    j = 0;
    k = l;
    countStepsMerge += 3;


    while (i < n1 && j < n2) {
        countStepsMerge += 2;

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            countStepsMerge += 3;
        }
        else {
            arr[k] = R[j];
            j++;
            countStepsMerge += 2;
        }countStepsMerge++;
        k++;
        countStepsMerge++;
    }
    countStepsMerge++;

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        countStepsMerge += 4;
    }countStepsMerge++;

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        countStepsMerge += 4;
    }
    countStepsMerge++;
}
