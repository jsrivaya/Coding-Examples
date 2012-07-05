//
//  main.cpp
//  ReverseWords
//
//  Created by JORGE SUAREZ RIVAYA on 7/5/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//

#include <iostream>

using namespace std;

void reverseWords(char []);

int main(int argc, const char * argv[])
{
    char * phrase;
    
    if (argc < 2) {
        cerr << "ERROR: No phrase was input \n";
        return -1;
    }
    
    phrase = (char*) malloc (strlen(argv[1]));
    
    strcpy(phrase, argv[1]);
    
    printf("*** Phrase: %s\n", phrase);
    
    
    reverseWords(phrase);
    
    printf ("*** Reversed: %s\n", phrase);
    
    return 0;
}

void reverseString (char str[], int start, int end) {
    
    char tmp;
    
    while (start < end) {
        tmp = str[start];
        str[start]=str[end];
        str[end]=tmp;
        start++;
        end--;
    }
}

void reverseWords (char * phrase) {

    int start, end, length;
    
    length = strlen(phrase);
    start = 0;
    end = 0;
    
    /* ie: "This is my house." */
    
    // we first reverse the whole phrase
    reverseString(phrase, start, length-1);
    /* ie: ".esuoh ym si sihT" */
    
    
    // now we have to reverse word by word
    while (end < length) {
        while (end < length && phrase[end]!=' ') 
            end++;
        
        // advance end until the next space ' '
        reverseString(phrase, start, end-1);
        end++;
        start = end;
    }
    
}