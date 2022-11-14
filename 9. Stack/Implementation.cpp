#include<iostream>
 
using namespace std;
 

class Stack {

    public:
    int *arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val) {
        if (size - top > 1) {
            top++;
            arr[top] = val;
        } else {
            cout << "Stack is overflow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack is under flow" << endl;
        }
    }

    int top() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

}; 

int main() {
 
    return 0;
}