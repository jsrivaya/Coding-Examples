//
//  main.cpp
//  Assign
//
//  Created by JORGE SUAREZ RIVAYA on 7/13/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//

#include <iostream>

using namespace std;

class A {
public:
    A();
    A(A&);
    A& operator=(const A&);
public:
    int a;
};

A::A() {
    a = -1;
}

A::A(A& element) {
    a = element.a;
}

A& A::operator=(const A& element) {
    a = element.a;
    return *this;
}

int main(int argc, const char * argv[])
{
    A a1; // default constructor
    A a2(a1); // copy constructor
    a1.a = 3;
    a2.a = 5;
    A a3 = a2 = a1; // (a2=a1) operator=(A&) ; (a3=a2) copy constructor; 
    
    cout << "a3: " << a3.a << endl;
    
    return 0;
}

