//
//  main.cpp
//  Singleton
//
//  Created by JORGE SUAREZ RIVAYA on 7/12/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//

#include <iostream>

using namespace std;

// singleton //////////////////////////////////////////////////////////////////
// A singleton patern defines a class that can be instantiate it only once
// we need then to have a private constructor and a way to let the constructor
// know that there is an object already created of that class.
class Singleton {
private:
    Singleton() {shared = 0;};
    static Singleton * _instance;
    int shared;
    
public:
    static Singleton* Instance();
    void increaseShared () { shared++; };
    int getSharedValue () { return shared; };
};

// Global static pointer used to ensure a single instance of the class.
Singleton* Singleton::_instance = NULL;

Singleton * Singleton::Instance() {
    if (!_instance) { 
        _instance = new Singleton;
    }
    
    return _instance;
}

// myThreadCode ///////////////////////////////////////////////////////////////
void * myThreadCode (void * param) {
    
    Singleton * theInstance;
    
    theInstance = Singleton::Instance();
    
    
    sleep(1);
    theInstance->increaseShared();
    
    return NULL;
}

// main ///////////////////////////////////////////////////////////////////////
int main(int argc, const char * argv[])
{
    int i;
    pthread_t threads[1000];
    Singleton * theInstance = Singleton::Instance();
    
    Singleton * myOtherInstance = Singleton::Instance();

    for (i=0; i<1000; i++) {
        pthread_create(&threads[i], NULL, &myThreadCode, NULL);
    }
    
    for (i=0; i<1000; i++) {
        pthread_join(threads[i], NULL);
    }
    
    cout << "The shared value is: " << theInstance->getSharedValue() << endl;
    
    // since this it is a Singleton class ... the value should be the same
    cout << "The other shared value is: " << myOtherInstance->getSharedValue() << endl;
    
    return 0;
}

