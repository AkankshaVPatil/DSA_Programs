//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
//2095. Delete the Middle Node of a Linked List

//-------Approach- I
// TC - O(n), SC - O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }
        if(n == 1)
        {
            delete head;
            return NULL;
        }
        int mid = n / 2, k = 0;
        curr = head;
        while(k < mid - 1)
        {
            curr = curr->next;
            k++;
        }
        
        ListNode* toDel = curr->next;
        curr->next = curr->next->next;
        toDel->next = NULL;
        delete toDel;

        return head;
    }
};
