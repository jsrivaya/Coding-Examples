//
//  main.cpp
//  FirstChar
//
//  Created by JORGE SUAREZ RIVAYA on 7/5/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//

// Find the First non repeated character

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int ascii[128];
    char * phrase;
    int itr;
    int plen;
    
    if (argc < 2) {
        cerr << "ERROR: missing parameters ..." << endl;
        return -1;
    }
    
    phrase = (char*) malloc(strlen(argv[1])+1);
    strcpy(phrase, argv[1]);
    memset(&ascii, 0, 128);
    
    printf("*** Phrase: %s \n",phrase);
    
    plen = strlen(phrase);
    
    for (itr=0; itr < plen; itr++) {
        ascii[phrase[itr]-'a']++;
    }
    
    for (itr=0; itr < plen; itr++) {
        if(ascii[phrase[itr]-'a']==1) {
            printf("First non repeated character is: %c \n",phrase[itr]);
            break;
        }
    }
    
    free(phrase);
    
    return 0;
}

