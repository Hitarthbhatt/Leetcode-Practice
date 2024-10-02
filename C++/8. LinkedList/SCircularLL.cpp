/*
                -> Circular Singly Linked List Practice. <-
*/

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is free for data - " << value << endl;
    }
};

void insertNode(Node* &tail, int ele, int d) {
    Node* temp = new Node(d);

    if (tail == NULL) { // Empty List
        temp->next = temp;
        tail = temp;
    } else { // Non-Empty List
        Node * curr = tail;

        while(curr->data != ele) {
            curr = curr->next;
        }

        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail) {
    Node* temp = tail;
    if (tail == NULL) { 
        cout << "Kuch nahi hai bhai list me";
        return;
    } 
    do {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int ele) {
    if (tail == NULL) {
        cout << "Kuch nahi hai bhai list me";
    } else {
        Node* prev = tail;
        Node* curr = prev->next;

        while (curr->data != ele) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;

        // 1 Node Link List.
        if (curr == prev) tail = NULL;
        // >=2 Node Link List.
        else if (tail == curr) tail = prev->next;

        delete curr;
    }
}

int main() {

    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    // insertNode(tail, 4, 6);
    // print(tail);

    // insertNode(tail, 4, 5);
    // print(tail);

    deleteNode(tail, 3);
    print(tail);

    return 0;
}