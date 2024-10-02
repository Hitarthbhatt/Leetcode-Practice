#include <iostream>
#include <vector>

using namespace std;

class Queue {

    int *arr;
    int front;
    int rear;
    int size;

    Queue() {
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (front == rear) {
            return -1;
        } else {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear) {
                front = rear = 0;
            }

            return ans;
        }
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