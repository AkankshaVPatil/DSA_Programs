//https://leetcode.com/problems/merge-two-sorted-lists/description/
//21. Merge Two Sorted Lists
// TC - O(n), SC - O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val <= list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
                curr = curr->next;
            }
        }

        if(list1 == NULL)
            curr->next = list2;
        else
            curr->next = list1;

        return dummy->next;
    }
};
