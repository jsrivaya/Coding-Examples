//
//  main.cpp
//  CycledList
//
//  Created by JORGE SUAREZ RIVAYA on 7/16/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//
// Write a function which determines if there is a cycle in a linked-list.

#include <iostream>

using namespace std;

typedef struct Node {
    Node * next;
    char value;
} Node;

int main(int argc, const char * argv[])
{
    Node * list = NULL;
    Node * tmp;
    string inputList;
    int i;
    bool loop = false;
    Node * itr1;
    Node * itr2;

    // read the list
    cout << "Input the list to be created: ";
    cin >> inputList;
    
    // create the list
    for (i=0; i<inputList.length(); i++) {
        tmp = new Node;
        tmp->next = NULL;
        tmp->value = inputList[i];
        if (i==0) {
            list = tmp;
            itr1 = list;
        } else {
            itr1->next = tmp;
        }
        itr1 = tmp;
        tmp = tmp->next;
    }
    
    // lets print the list to be sure that is what we want
    //for (i=0,itr1=list; itr1!=NULL; itr1=itr1->next) {
    //    cout << itr1->value << " ";
    //}
    
    //cout << endl;

    
    // uncomment this to add a loop
    //itr1->next = list; // this is a loop from the last to the first
    
    itr1 = list;
    itr2 = list->next;
    
    // check if there is a loop
    while (itr2 != NULL) {
        if (itr1==itr2) {
            loop = true;
            break;
        }
        itr1 = itr1->next;
        if (itr2->next != NULL) 
            itr2 = itr2->next->next;
    }
    
    if (loop) {
        cout << "This list has a loop" << endl;
    } else {
        cout << "This list is clean of loops" << endl;
    }
    
    // free the memory allocate
    for (i=0; i<inputList.length(); i++) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    return 0;
}

