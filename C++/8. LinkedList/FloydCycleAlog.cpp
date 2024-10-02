/*
                -> Floyd's Cycle detection alogrithm <-
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* floydCycleDetection(ListNode* head) {
        if (head == NULL || head -> next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (slow != NULL && fast != NULL) {
            fast = fast->next;
            if (fast != NULL) fast = fast->next;
            slow = slow->next;
            
            if (slow == fast) return slow;
        }
        
        return NULL;
    }
    
    ListNode* getStartingPoint(ListNode* head) {
        ListNode* intersection = floydCycleDetection(head);
        ListNode* slow = head;
        
        if (intersection == NULL) return NULL;
        
        while (slow != intersection) {
            slow = slow -> next;
            intersection = intersection -> next;
        }
        
        return slow;
    }
    
    ListNode *detectCycle(ListNode *head) {
        return getStartingPoint(head);
    }
};