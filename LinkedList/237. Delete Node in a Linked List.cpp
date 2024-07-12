//https://leetcode.com/problems/delete-node-in-a-linked-list/description/
//237. Delete Node in a Linked List
// TC = O(1), SC - O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* toDel = node->next;
        node->next = node->next->next;
        delete toDel;
    }
};
