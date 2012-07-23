//
//  main.cpp
//  RomanNumbers
//
//  Created by JORGE SUAREZ RIVAYA on 7/19/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//
// given a formatted Roman String and convert them into numbers
//

#include <iostream>

using namespace std;

int getArabicNumber (string);

int main(int argc, const char * argv[])
{

    string romanString;
    
    cout << "Input a roman string: ";
    cin >> romanString;
    
    cout << "Arabic string: " << getArabicNumber (romanString) << endl;
    
    return 0;
}

int getArabicNumber (string romanString) {
    int myArabicNumber = 0;
    int len;
    int i;
    int prev = 0;
    
    len = romanString.length();
    
    for (i=0; i<len; i++) {
        
        switch (romanString[i]) {
            case 'I':
                myArabicNumber+=1;
                prev=1;
                break;
            case 'V':
                if (prev<5) {
                    myArabicNumber-=(2*prev);
                }
                myArabicNumber+=5;
                prev=5;
                break;
            case 'X':
                if (prev<10) {
                    myArabicNumber-=(2*prev);
                }
                myArabicNumber+=10;
                prev=10;
                break;
            case 'L':
                if (prev<50) {
                    myArabicNumber-=(2*prev);
                }
                myArabicNumber+=50;
                prev=50;
                break;
            case 'C':
                if (prev<100) {
                    myArabicNumber-=(2*prev);
                }
                myArabicNumber+=100;
                prev=100;
                break;
            case 'D':
                if (prev<500) {
                    myArabicNumber-=(2*prev);
                }
                myArabicNumber+=500;
                prev=500;
                break;
            case 'M':
                if (prev<1000) {
                    myArabicNumber-=(2*prev);
                }
                myArabicNumber+=1000;
                prev=1000;
                break;
        }
    }
    
    return myArabicNumber;
}