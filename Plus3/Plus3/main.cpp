//
//  main.cpp
//  Plus3
//
//  Created by JORGE SUAREZ RIVAYA on 7/25/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//
//  Giving an array of integers (+/-) Implement a function that returns
//  true: if the add of 3 numbers = 0
//  false: if there are not those 3 numbers to plus
//
// O(n^2 log n )
// 
#include <iostream>

using namespace std;

bool plus3(int *, int);
void quicksort (int * , int, int);
void printArray (int *, int );

class test {
public:
    test() { cout << "hello" << endl; };
};

test myTest;

int main(int argc, const char * argv[])
{
    int i;
    int len;
    int * array;
    bool found = false;

    cout << "Input the size of the array: ";
    cin >> len;
    
    if (len>=3) {
        array = new int[len]; 
    } else {
        cerr << "ERROR: incorrect array size" << endl;
        return -1;
    }
    
    
    for (i=0; i<len; i++) {
        cout << "array[" << i << "] = ";
        cin >> array[i];
    }
    
    
    // print the array
    printArray (array, len);
    
    found = plus3(array, len-1);
    
    // print the array
    printArray (array, len);
    
    if (found) {
        cout << "there are 3 numbers plusing 0" << endl;
    } else {
        cout << "There are no 3 numbers plusing 0" << endl;
    }
    
    
done:
    free(array);
    
    return 0;
}

bool plus3 (int * array, int len) {
    
    int itr1, itr2;
    int i;
    int tmp;
    
    // order the array
    quicksort (array,0,len);
    
    itr1 = 0;
    itr2 = len;
    
    for (itr1=0, i=0; i<len; i++) {
        itr1 = i+1;
        itr2 = len;
        
        while (itr1<itr2) {
            tmp = array[i] + array[itr1] + array[itr2];
            if (tmp > 0) {
                itr2--;
            } else if (tmp < 0) {
                itr1++;
            } else {
                return true;
            }
        }
    }
    
    
    return false;
}

void quicksort (int * array,int low, int high) {
    
    int pivot;
    int temp;
    int a, b;
    
    a = low;
    b = high;
    
    pivot = array[(low+high)/2];
    
    while (low <= high) {
    
        while (array[low] < pivot) low++;
        while (array[high] > pivot) high--;
    
        if (low <= high) {
            temp = array[low];
            array[low] = array[high];
            array[high] = temp;
            high--;
            low++;
        }
    }
    
    if (a < high) {
        quicksort(array, a, high);
    }
    if (b > low) {
        quicksort(array, low, b);
    }
    
    
}

void printArray (int * array, int len) {
    int i;
    
    // print the array
    cout << "array: ";
    for (i=0; i<len; i++) {
        cout << " " << array[i];
    }
    cout << endl;
    
}

