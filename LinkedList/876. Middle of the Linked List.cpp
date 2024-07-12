//https://leetcode.com/problems/middle-of-the-linked-list/description/
//876. Middle of the Linked List
// TC - O(n), SC - O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
