/*
                -> Remove Duplicates from Sorted List II <- 

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

    Example 1:
    Input: head = [1,2,3,3,4,4,5]
    Output: [1,2,5]
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        int count = 0;
        
        while (curr -> next != NULL) {
            if (curr->val == curr->next->val) {
                count++;
                curr = curr->next;
            } else {
                if (count == 0) {
                    prev->next = curr;
                    prev = prev->next;
                    count = 0;
                } else {
                    count = 0;
                }
                curr = curr -> next;
            }
        }
        
        if (count == 0) {
            prev->next = curr; 
        } else {
            prev->next = NULL;
        }
        
        return dummy->next;
    }
};