//https://leetcode.com/problems/middle-of-the-linked-list/description/
//876. Middle of the Linked List
//---------Approach-I------
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

//---------Approach-II------
// TC - O(n), SC - O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        int cntr = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            cntr++;
            curr = curr->next;
        }

        int mid = cntr/2 + 1;
        cntr = 0;
        curr = head;
        while(curr != NULL)
        {
            cntr++;
            if(cntr == mid)
                return curr;
            curr = curr->next;
        }
        return NULL;
    }
};
