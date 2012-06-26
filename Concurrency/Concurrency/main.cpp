//
//  main.cpp
//  Concurrency
//
//  Created by JORGE SUAREZ RIVAYA on 6/25/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//

// this program pretends to be an example on how to use posix threads
// mutex and shared memory to manipulate a shared resource
// the experient is the next:
// We will create 100 threads, each of them will increase by 1 the value of a
// shared variable (mySharedData)
// At the end the value of mySharedData variable should be equal to the number
// of threads.

#include <iostream>

using namespace std;

int mySharedData = 0;
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;

void * MyThread (void *) {
    
    pthread_mutex_lock(&myMutex); // ,,,,,,,,,,,,,,,,,,,,,,,,,
    printf("I am thread [%u] \n",pthread_self());

    printf("Updating sharedData to %d\n",++mySharedData);
    pthread_mutex_unlock(&myMutex);// """""""""""""""""""""""
    
    return NULL;
}

int main(int argc, const char * argv[])
{
    int i;
    int retCode = -1;
    int numThreads = 100;
    pthread_t threads[numThreads];
    
    // we will create 100 threads to do a +1 on a common re
    pthread_mutex_lock(&myMutex); // ,,,,,,,,,,,,,,,,,,,,,,,,,
    
    for (i=0; i<numThreads; i++) {
        retCode = pthread_create(&threads[i], NULL, MyThread, NULL);
    }
     
    pthread_mutex_unlock(&myMutex); // """""""""""""""""""""""
    
    printf("*** Main Thread waiting for my little ones to finish their work\n");
    for (i=0; i<numThreads; i++) {
        // synchronizing all the threads end at this point
        retCode = pthread_join(threads[i], NULL);
    }
    
end:  
    printf("*** Main Thread Cleanning up\n");
    retCode = pthread_mutex_destroy(&myMutex);
    printf("*** Main Thread completed\n");
    return 0;
}

