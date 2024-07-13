//https://leetcode.com/problems/odd-even-linked-list/description/
//328. Odd Even Linked List
// TC - O(n), SC - O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* oddList = head;
        ListNode* evenList = head->next;
        ListNode* odd = oddList, *even = evenList;

        while(even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenList;
        return head;
    }
};
