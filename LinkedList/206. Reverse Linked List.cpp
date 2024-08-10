//https://leetcode.com/problems/reverse-linked-list/description/
//206. Reverse Linked List.cpp
//TC - O(n), SC - O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};
