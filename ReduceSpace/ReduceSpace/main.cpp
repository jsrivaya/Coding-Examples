//
//  main.cpp
//  ReduceSpace
//
//  Created by JORGE SUAREZ RIVAYA on 7/16/12.
//  Copyright (c) 2012 Tragu. All rights reserved.
//
// Given a string “aaabbbcc”, compress it, = “a3b3c2″ . Given that output 
// string’s length is always smaller than input string, you have do it inplace.
// No extra space


#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    string inputString;
    int len = 0;
    int i;
    int count = 1;
    int firstPos = 0;
    
    cout << "Input a string (example: aaabbcccc)> ";
    cin >> inputString;
    
    len = inputString.size();
    
    if (len == 1) {
        return 0;
    }
    
    for (count=1, i=1; i<len; i++) {
        if (inputString[i]==inputString[i-1]) {
            count++;
        } else {
            inputString[firstPos] = inputString[i-1];
            if (count>1) {
                inputString[firstPos+1] = '0'+ count;
                firstPos+=2;
            } else {
                firstPos++;
            }
            count = 1;
        }
    }

    // for the last case
    inputString[firstPos] = inputString[i-1];
    if (count>1) {
        inputString[firstPos+1] = '0'+ count;
        firstPos+=2;
    } else {
        firstPos++;
    }
    
    cout << "The String is: ";
    for (i=0; i<firstPos; i++) {
        cout << inputString[i];
    }
    
    cout << endl;
    
    return 0;
}

