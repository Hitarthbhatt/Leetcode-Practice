/*
                -> Doubly Ended Queue <-
*/

#include <iostream>
#include <vector>

using namespace std;

class DQueue {

    int *arr;
    int front;
    int rear;
    int size;

    DQueue() {
        size = 100001;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool push_front(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return false;
        } else if (front == -1) {
            front = rear = 0;
        } else if (front == 0 && rear != size - 1) {
            front = size - 1;
        } else {
            front--;
        }

        arr[front] = val;
        return true;
    }

    bool push_rear(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return false;
        } else if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = val;
        return true;
    }

    int pop_front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }

        return ans;
    }

    int pop_rear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear-- ;
        }

        return ans;
    }

    bool isEmpty() {
        if (front == -1) {
            return false;
        } 
        return true;
    }

    int top() {
        if (front == rear) return -1;

        return arr[front];
    }

    bool isFull() {
        if ((front == 0 && rear == size - 1) || (front != -1 && rear == (front -1)%(size - 1))) {
            return true;
        } 
        return false;
    }

};

int main() {

    return 0;
}