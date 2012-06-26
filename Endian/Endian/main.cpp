//
//  main.cpp
//  Endian
//
//  Created by JORGE SUAREZ RIVAYA on 6/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
// this example tries to demostrate how to know if a machine is big-endian
// or little-endian
// 
// Endianness refers to the order in which a computer stores the bytes of a 
// multibyte value.
//
// In a Big-endian machine the Most Significan Byte has the lowest address

#include <iostream>

using namespace std;

bool myFancyEndianness(int value);

int main(int argc, const char * argv[])
{
    int value;
    char * ptr;
    
    value = 1;
    
    ptr = (char*)&value;
    
    // if answer is 1: machine is little-endian
    // if answer is 0: machine is big-endian
    printf("*** Lowest byte: %d\n",ptr[0]);
    
    // in a more fancy way :)
    if (myFancyEndianness(1)){
        printf("This is a little-endian machine \n");
    } else {
        printf("This is a big-endian machine \n");
    }
    
    return 0;
}

bool myFancyEndianness(int value) {
    // unions allow us to use the same piece of memory (endianTest) as differnt
    // types, in this case, int or char.
    // if the machine is little endian, then singleByte value will be 1
    union {
        int value;
        char singleByte;
    } endianTest;
    
    endianTest.value =  value;
    
    return endianTest.singleByte;
}