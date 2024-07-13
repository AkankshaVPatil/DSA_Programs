//https://leetcode.com/problems/linked-list-random-node/description/
//382. Linked List Random Node
//-----------Approach - I----------
// TC - O(n), SC - O(n)
class Solution {
public:
    vector<int>vec;
    Solution(ListNode* head) {
        ListNode* curr = head;
        while(curr != NULL)
        {
            vec.push_back(curr->val);
            curr = curr->next;
        }
    }
    
    int getRandom() {
        int rnd = rand();
        int n = vec.size();
        return vec[rnd % n];
    }
};

//-----------Approach - II----------
//using reservoir sampling
// TC - O(n), SC - O(1)
class Solution {
public:
    ListNode *hd;
    Solution(ListNode* head) {
        hd = head;
    }
    
    int getRandom() {
        int count = 1;
        int result = 0;
        ListNode* temp = hd;

        while(temp != NULL)
        {
            if(rand() % count < 1.0/ count)
                result = temp->val;
            count++;
            temp = temp->next;
        }        
        return result;
    }
};
