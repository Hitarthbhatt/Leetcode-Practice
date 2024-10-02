/*
            -> Reverse Linked List II <- 

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

    Example 1:
    Input: head = [1,2,3,4,5], left = 2, right = 4
    Output: [1,4,3,2,5]
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next; // Set left node to curr (initially).

        for (int i = 0; i < right - left; i++) { // Send each upcoming element to last in row.
            ListNode* fwr = curr->next;
            curr->next = fwr->next; // Current will point to next upcoming element.
            fwr->next = prev->next; // This forward will go to the last position.
            prev->next = fwr; // Checkpoint now point to newly add last element.
        }

        return dummy->next;
    }
};
// @lc code=end

