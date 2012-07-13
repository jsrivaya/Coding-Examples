//
//  main.cpp
//  Quicksort
//
//  Created by JORGE SUAREZ RIVAYA on 7/12/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//
//  As its name says, order using a quicksort algorithm an array of 1K positions
//

#include <iostream>

using namespace std;

void quicksort(int array[], int i, int j);

int main(int argc, const char * argv[])
{

    int array[10] = {9, 5 ,8, 6, 3, 1, 2, 10, 7, 11};
    int i, j;
    
    // initialization
    //for (i =0; i<10; i++) {
    //    array[i] = rand();
    //}
    
    cout << endl;
    for (i=0; i<10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    // start quicksort:
    i=0;
    j=9;
    quicksort(array, i, j);
    
    cout << endl;
    for (i=0; i<10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}


void quicksort(int array[], int left, int right) {
    int pivot;
    int tmp;
    int a, b;
    int i;
    
    if (left > right) {
        return;
    }
    
    a = left;
    b = right;
    
    pivot = array[left+(b-a)/2];
    
    cout << endl;
    for (i=0; i<10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    while (a<=b) {
        while (array[a]<pivot) a++;
        while (array[b]>pivot) b--;
        if (a<=b) {
            tmp=array[a];
            array[a] = array [b];
            array[b] = tmp;
            b--;
            a++;
        }
    }
    
    cout << endl;
    for (i=0; i<10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    if (left < b) {
        quicksort(array,left,b);
    }
    if (right > a) {
        quicksort(array,a,right);
    }
    
    
}