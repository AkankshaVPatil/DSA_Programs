//https://leetcode.com/problems/linked-list-cycle/description/
//141. Linked List Cycle
//TC - O(N), TC - O(1)
class Solution {
public:
    bool hasCycle(ListNode *A) {
        if(A == NULL || A->next == NULL) return NULL;
    
        ListNode *slow = A, *fast = A;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                return slow;
            }
        }
        return NULL;
    }
};
