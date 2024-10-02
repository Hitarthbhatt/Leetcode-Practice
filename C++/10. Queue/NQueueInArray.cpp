/*
                -> N Queue In An Array <-

Design a data structure to implement ‘N’ Queue using a single array of size ‘S’. It should support the following operations:

enqueue(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.
dequeue(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.

*/

#include <iostream>
 
using namespace std;

class NQueue {
    
    int *arr;
    int *front;
    int *rear;
    int *next;
    
    int n, k;
    int freespot;
    
public:
    // Initialize your data structure.
    NQueue(int n, int k) {    
        this -> n = n;
        this -> k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }
        
        next = new int[n];
        for (int i = 0; i < n; i++) {
            next[i] = i+1;
        }
        
        next[n - 1] = -1;
        freespot = 0;
    }

    void enqueue(int data, int qn) {
        // Overflow.
        if (freespot == -1) {
            cout << "Queue is full" << endl;
            return;
        }

        // Find first free index.
        int index = freespot;

        // Update freespot.
        freespot = next[index];

        // Check whether the first element.
        if (front[qn - 1] == -1) {
            front[qn - 1] = index;
        } else {
            // Link new element to prev.
            next[rear[qn - 1]] = index;
        }

        // Update next.
        next[index] = -1;

        // Update rear.
        rear[qn - 1] = index;

        // Push element.
        arr[index] = data;
    }

    int dequeue(int qn) {
        // Check empty.
        if (front[qn - 1] == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // Find front index.
        int index = front[qn - 1];
        
        // Update front to next.
        front[qn - 1] = next[index];

        // Link empty space next to freespot. 
        next[index] = freespot;

        // Set newly add freespot.
        freespot = index;

        return arr[index];
    }

};

int main() {

    NQueue q(5, 2);

    q.enqueue(2,1);
    q.enqueue(4,2);
    q.enqueue(5,2);
    q.enqueue(6,1);
    q.enqueue(7,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;

    return -1;
}