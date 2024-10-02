/*
                -> Reverse Nodes in k-Group <- (IMP)

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

    Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]
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
    ListNode* reverseGroup(ListNode* head, int length, int total, int k) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        int count = 0;
        
        cout << total << " " << length << endl;
        if (total + k  > length) return head;
        
        // step1: reverse first k nodes.
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // step2: recursive call
        if (next != NULL) {
           head -> next = reverseGroup(next, length, total+k, k);
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int length = 0;
        
        while (temp != NULL) {
            temp = temp->next;
            length++;
        }
        
        return reverseGroup(head, length, 0, k);
    }
};
