/*
                -> Singly Linked List Practice. <-
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

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    Node* node = new Node(d);
    Node* temp = head;
    int count = 1;

    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    while (count < position - 1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    node->next = temp->next;
    temp->next = node;
}

void deleteNode(Node* &head, int position) {

    if (position == 1) {
        Node* curr = head;
        head = head -> next;
        curr->next = NULL;
        delete curr;
    } else {
        int count = 1;
        Node* temp = head;
        
        while (count < position - 1) {
            temp = temp->next;
            count++;
        }
    
        Node* node = temp;
        temp = temp->next;
        node->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(node1);

    insertAtTail(tail, 20);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    insertAtPosition(head, tail, 5, 15);
    print(head);

    cout << "head - " << head->data << endl;
    cout << "tail - " << tail->data << endl;

    deleteNode(head, 5);
    print(head);

    return 0;
}