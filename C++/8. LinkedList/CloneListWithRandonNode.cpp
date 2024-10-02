/*
                -> Copy List with Random Pointer <-

There wi;; be a given linked list who has an extra pointer variable which point at random node.
We need to create 'Deep Copy' of that list.

    Example 1:
    Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]] -> original
    Output: [[7,null],[13,0],[11,4],[10,2],[1,0]] -> copy
 */

#include <iostream>
#include <map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    Node* firstApproach(Node* head) {
        
        Node* copyHead = NULL;
        Node* copyTail = NULL;
        
        Node* temp = head;
        
        // Step 1: Create copy.
        while (temp != NULL) {
            insertAtTail(copyHead, copyTail, temp->val);
            temp = temp->next;
        }
        
        
        // Step 2: Create a map.
        Node* originalNode = head;
        Node* copyNode = copyHead;
        
        map<Node*, Node*> oldToNewNode;
        
        while(originalNode != NULL) {
            oldToNewNode[originalNode] = copyNode;
            originalNode = originalNode->next;
            copyNode = copyNode->next;
        }
        
        // Step 3: Assign random point to copy.
        originalNode = head;
        copyNode = copyHead;
        while (originalNode != NULL) {
            copyNode->random = oldToNewNode[originalNode->random];
            copyNode = copyNode->next;
            originalNode = originalNode->next;
        }
        
        return copyHead;
    }
    
    Node* secondApproach(Node* head) {
        
        Node* copyHead = NULL;
        Node* copyTail = NULL;
        
        Node* temp = head;
        
        // Step 1: Create copy.
        while (temp != NULL) {
            insertAtTail(copyHead, copyTail, temp->val);
            temp = temp->next;
        }
        
        
        // Step 2: cloneNodes add in between originalNodes.
        Node* originalNode = head;
        Node* copyNode = copyHead;

        while (originalNode != NULL && copyNode != NULL) {

            Node* next = originalNode->next;
            originalNode->next = copyNode;
            originalNode = next;

            next = copyNode->next;
            copyNode->next = originalNode;
            copyNode = next;
        }

        // Step 3: Copy random pointer.
        temp = head;
        
        while (temp != NULL) {
                temp->next->random = temp->random != NULL ? temp->random->next : temp->random; 
            temp = temp->next->next;
        }

        // Step 4: Revers back step 2.
        originalNode = head;
        copyNode = copyHead;

        while (originalNode != NULL && copyNode != NULL) {
            originalNode->next = copyNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL) {
                copyNode->next = originalNode->next;
            }
            copyNode = copyNode->next;
        }
        

        return copyHead;
    }

    Node* copyRandomList(Node* head) {
        return secondApproach(head);
    }
};
