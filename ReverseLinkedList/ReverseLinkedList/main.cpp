//
//  main.cpp
//  ReverseLinkedList
//
//  Created by JORGE SUAREZ RIVAYA on 7/12/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct Node{
    int value;
    Node * next;
}Node;

Node * reverseList (Node * list, Node * prev);
Node * reverseListNonRec (Node * list);

int main(int argc, const char * argv[])
{
    Node * tmp;
    Node * itr;
    Node * list;
    int i;
    
    
    // allocate memory
    for (i=0; i<100; i++) {
        tmp = new Node();
        tmp->value = i;
        
        if (i==0) {
            list = tmp;
        } else {
            itr->next = tmp;
        }
        itr = tmp;
    }
    
    cout << endl << "Old list: ";
    // print list
    tmp = list;
    while (tmp != NULL) {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    
    list = reverseList(list, NULL);
    
    cout << endl << "New list: ";
    // print the reverse list
    tmp = list;
    while (tmp != NULL) {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    
    cout << endl;
    
    list = reverseListNonRec(list);
    
    cout << endl << "New list Non recursive: ";
    // print the reverse list
    tmp = list;
    while (tmp != NULL) {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    
    cout << endl;
    
    // free the memory
    while (list!=NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
    
    return 0;
}

Node * reverseList (Node * list, Node * prev) {
    Node * tmp;
    
    if (list->next == NULL) {
        list->next = prev;
        return list;
    } else {
        tmp = reverseList(list->next, list);
        list->next = prev;
        return tmp;
    }
}


// in a non recursive way
Node * reverseListNonRec (Node * list) {
    
    Node * tmp;
    Node * prev = NULL;

    while (list->next!=NULL) {
        tmp = list->next;
        list->next = prev;
        prev = list;
        list = tmp;
    }
    
    list->next = prev;
    return list;
    
    
}


