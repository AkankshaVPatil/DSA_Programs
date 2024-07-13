//https://leetcode.com/problems/linked-list-cycle-ii/description/
//142. Linked List Cycle II
// TC - O(n), SC - O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        bool IsCycleFound = false;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
             if(slow == fast)
            {
                IsCycleFound = true;
                break;
            }
        }

        if(IsCycleFound == false)
            return NULL;

        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
