//
//  main.cpp
//  String2Integer
//
//  Created by JORGE SUAREZ RIVAYA on 7/6/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    string number;
    int integerNumber;
    int i, len;
    bool neg = false;
    
    cout << "Input a number: ";
    cin >> number;
    
    len = number.length();
    
    if (number[0] == '-') {
        i=1;
        neg = true;
    }
    
    for (integerNumber=0; i<len; i++) {
        integerNumber = integerNumber * 10 + number[i] - '0';
    }
    
    if (neg) {
        integerNumber*=-1;
    }
    
    cout << "Number as an Integer: " << integerNumber << endl;
    
    return 0;
}

