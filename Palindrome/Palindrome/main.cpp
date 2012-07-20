//
//  main.cpp
//  Palindrome
//
//  Created by JORGE SUAREZ RIVAYA on 7/16/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
// Write a function that determines if a given string is a palindrom

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int i,j;
    string inputString;
    bool palindrome = true;
    
    cout << "Is this Palindrome? > ";
    cin >> inputString;
    
    for (i=0, j=inputString.length()-1; i<j;i++,j--) {
        if (inputString[i]!=inputString[j]) {
            palindrome = false;
            break;
        }
    }
    
    // decision
    cout << inputString;
    if (palindrome)
        cout << " is Palindrome" << endl;
    else cout << " is not Palindrome" << endl;
    
    return 0;
}

