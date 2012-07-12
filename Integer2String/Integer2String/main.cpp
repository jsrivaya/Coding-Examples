//
//  main.cpp
//  Integer2String
//
//  Created by JORGE SUAREZ RIVAYA on 7/5/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//


// From Integer to String


#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{

    int number;
    char temp[10];
    int i = 0;
    string numberstring;
    bool neg = false;
    
    memset(&temp, 0, 10);
    
    cout << "Input a number: ";
    cin >> number;
    
    if (number < 0) {
        number*=-1;
        neg=true;
    }
    
    while (number != 0) {
        temp[i++]= (char)((number%10)+'0');
        number/=10;
    }
    
    if (neg) {
        numberstring.append("-");
    }
    
    // now we have to reverse it
    while (i>0) {
        numberstring.append(&temp[--i],1);
    }
    
    cout << "Number as a string: " << numberstring <<endl; 
    
    return 0;
}

