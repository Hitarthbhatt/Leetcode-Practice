/*
                -> Reverse Linked List <-

Given the head of a singly linked list, reverse the list, and return the reversed list.

    Example 1:
    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        // First
        // return iterativeApproach(head, curr, prev);
        
        // Second
        // recursiveApproach(head, curr, prev);
        // return head;
        
        // Third
        return recursive1(head);
        
    }
    
    // First Approach.
    ListNode* iterativeApproach(ListNode* head, ListNode* curr, ListNode* prev) {
        
        while(curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
    
    // Second Approach.
    void recursiveApproach(ListNode* &head, ListNode* curr, ListNode* prev) {
        
        if (curr == NULL) {
            head = prev;
            return;
        }
        
        ListNode* forward = curr->next;
        recursiveApproach(head, forward, curr);
        curr->next = prev;
    }
    
    // Third Approach.
    ListNode* recursive1(ListNode* head) {
        
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* chotaNode = recursive1(head->next); // Reach to the last node.
        
        head->next->next = head; // Link head next node to previous node.
        head->next = NULL; // remove head next node link.
        
        return chotaNode;
    }
    
};