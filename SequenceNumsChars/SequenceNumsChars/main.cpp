//
//  main.cpp
//  SequenceNumsChars
//
//  Created by JORGE SUAREZ RIVAYA on 7/25/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//
// Given a sequence consisting of letters and numbers, re-arrange the sequence 
// so that the numbers come together first, while maintaining their initial 
// order in the sequence (not allowed to use additional memory)
//
// e.g. Input : 12gh45fd3, Output : 12453ghfd
//
#include <iostream>

using namespace std;

string orderString (string);

int main(int argc, const char * argv[])
{
    string inputString;

    cout << "Input String: ";
    cin >> inputString;

    cout << "New String: " << orderString (inputString) << endl;
    
    return 0;
}

string orderString (string inputString) {
    
    int i, len;
    int itrChar = 0;
    int itrSwap = 0;
    char temp, temp2;
    
    len = inputString.length();
    
    // first we have to initialize itrChar
    while ((itrChar < len) && 
           !(inputString[itrChar]>='a' && inputString[itrChar]<='z')) {
        itrChar++;
    }
    
    // now we do the parse
    for (i=0; i<len; i++) {
        
        if (!(inputString[i]>='a' && inputString[i]<='z') && 
            (itrChar<i)) { // if number && itrChar < i -> we have to swap
            temp = inputString[itrChar];
            inputString[itrChar++] = inputString[i]; 
            
            for (itrSwap=itrChar; itrSwap<=i; itrSwap++) { // move all one to the right
                temp2=inputString[itrSwap];
                inputString[itrSwap] = temp;
                temp = temp2;
            }
            
            // itrChar is already updated and we do not have to modify 'i'
            
        }
    }
    
    return inputString;
}