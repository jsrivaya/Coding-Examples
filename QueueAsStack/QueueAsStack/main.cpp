//
//  main.cpp
//  QueueAsStack
//
//  Created by JORGE SUAREZ RIVAYA on 7/19/12.
//  Copyright (c) 2012 Trasgu. All rights reserved.
//
// Implementing a queue with stack as the internal datastructure
//
// Necessary methods for a queue:
// *) Constructor: Construct queue (public member function)
// *) empty: Test whether container is empty (public member function)
// *) size:  Return size (public member function)
// *) front: Access next element (public member function)
// *) back:  Access last element (public member function)
// *) push:  Insert element (public member function)
// *) pop:   Delete next element (public member function)
//

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> data;
public:
    MyQueue() {};
    bool Empty() { return data.empty(); };
    size_t Size() { return data.size(); };
    int Front();
    const int Back() { return data.top(); };
    void Push(int value) { return data.push(value); };
    void Pop(); // pop all elements, push them back and return bottom of d stack
};

// Front implementation
int MyQueue::Front() {
    int tmp;
    stack<int> tmpStack;
    
    while (!data.empty()) {
        tmpStack.push(data.top());
        data.pop();
    }
    
    tmp = tmpStack.top();
    
    while (!tmpStack.empty()) {
        data.push(tmpStack.top());
        tmpStack.pop();
    }
    
    return tmp;
}

// Pop implementation
void MyQueue::Pop () {
    stack<int> tmpStack;
    
    // revert the stack
    while (!data.empty()) {
        tmpStack.push(data.top());
        data.pop();
    }
    
    // save the top element and delete it from the stack
    tmpStack.pop();
    
    // rebuild the original stack
    while (!tmpStack.empty()) {
        data.push(tmpStack.top());
        tmpStack.pop();
    }

}

int main(int argc, const char * argv[])
{
    MyQueue myQueue;
    int i;

    for (i=0; i<1000; i++) {
        // load the queue
        myQueue.Push(i);
    }
    
    // print the Front
    cout << "Front: " << myQueue.Front() << endl;
    
    // pop an element and print the front again
    myQueue.Pop();
    cout << "New Front: " << myQueue.Front() << endl;
    
    
    return 0;
}

