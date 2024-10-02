/*
                -> Doubly Linked List Practice. <-
*/

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        if (next != NULL) {
            delete next;
            next = NULL;
        }

        cout << "Destructor Called & free -> " << value << endl;
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
    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        tail = temp;
    } else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
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
    temp->next->prev = node;
    temp->next = node;
    node->prev = temp;
}

void deleteNode(Node* &head, Node* &tail, int position) {

    if (position == 1) {
        Node* curr = head;
        curr->next->prev = NULL;
        head = head -> next;
        curr->next = NULL;
        delete curr;
    } else {
        int count = 1;
        Node* temp = head;
        
        while (count < position && temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        
        if (temp->next == NULL) {
            cout << tail->data << endl;
            tail = temp->prev;
            tail->next = NULL;
            temp->prev = NULL;
        } else {
            Node* node = temp->prev;
            temp->prev = NULL;
        
            temp->next->prev = node;
            node->next = temp->next;

            temp->next = NULL;
        }

        delete temp;
    }
}

int main() {

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head, 11);
    insertAtHead(head, 12);
    print(head);

    insertAtTail(tail, 5);
    print(head);

    insertAtPosition(head, tail, 6, 100);
    print(head);

    deleteNode(head, tail, 1);
    print(head);

    cout << "head is -> " << head->data << endl;
    cout << "tail is -> " << tail->data << endl;

    return 0;
}
