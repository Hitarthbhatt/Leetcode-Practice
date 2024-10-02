#include <iostream>
#include <vector>

using namespace std;

class CircularQueue {

    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue() {
        size = 100001;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool enqueue(int data) {
        if ((front == 0 && rear == size - 1) || (rear == (front -1)%(size - 1))) {
            cout << "Queue is full" << endl;
            return false;
        } else if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = data;
        return true;
    }

    int dequeue() {
        if (front == -1) {
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

    bool isEmpty() {
        return front == rear;
    }

    int top() {
        if (front == rear) return -1;

        return arr[front];
    }

};

int main() {

    return 0;
}