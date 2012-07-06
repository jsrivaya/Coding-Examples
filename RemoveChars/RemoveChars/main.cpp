//
//  main.cpp
//  RemoveChars
//
//  Created by JORGE SUAREZ RIVAYA on 7/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

// This solutions is O(n+m)

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    char * phrase;
    char * remove;
    char * newstring;
    bool ascii[128];
    int rlen = -1;
    int plen = -1;
    int i;
    int dst,src;
    
    if (argc < 3) {
        cerr << "ERROR: no arguments" << endl;
        return -1;
    }

    phrase = (char*) malloc(strlen(argv[1])+1);
    remove = (char*) malloc(strlen(argv[2])+1);
    
    memset(&ascii, 0, 128);
    strcpy(phrase, argv[1]);
    strcpy(remove, argv[2]);
    rlen = strlen(remove);
    
    printf ("*** Phrase: %s\n", phrase);
    printf ("*** Remove: %s\n", remove);
    
    
    for (i=0; i<rlen; i++) {
        ascii[remove[i]] = true;
    }
    

    src = 0;
    dst = 0;
    plen = strlen(phrase);
    
    while (src<plen) {
        
        if (ascii[phrase[src]])  // we have to remove that letter
            src++;
        else {
            // in this case we advance both pointers
            phrase[dst]=phrase[src];
            src++;
            dst++;
        }
        
    }
    
    newstring = (char*) malloc(dst+1);
    memcpy(newstring, phrase, dst+1);
    
    printf ("*** Phrase: %s\n", newstring);
    
    free(phrase);
    free(remove);
    free(newstring);
    
    return 0;
}

