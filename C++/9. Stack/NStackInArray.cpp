/*
                -> N Stacks In An Array <-

Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:

push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.
pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.

*/

#include <iostream>
#include <stack>
 
using namespace std;

class NStack {
    
    int *arr;
    int *top;
    int *next;
    
    int s = 0, n = 0;
    int freespot = 0;
    
public:
    // Initialize your data structure.
    NStack(int N, int S) {    
        s = S;
        n = N;
        arr = new int[s];
        next = new int[s];
        top = new int[n];
        
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }
        
        for (int i = 0; i < s; i++) {
            next[i] = i+1;
        }
        
        next[s - 1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        if (freespot == -1) {
            return false;
        }
        
        int index = freespot;
        
        freespot = next[index];
        
        arr[index] = x;
        
        next[index] = top[m - 1];
        
        top[m - 1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        if (top[m - 1] == -1) {
            return -1;
        }
        
        int index = top[m - 1];
        
        top[m - 1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
    }
};