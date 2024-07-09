//https://leetcode.com/problems/check-completeness-of-a-binary-tree/
//958. Check Completeness of a Binary Tree
// TC - O(N)
//  SC - O(N)

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root);

        bool isNullNodeFound = false;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL)
            {
                isNullNodeFound = true;
            }
            else
            {
                if(isNullNodeFound == true)
                    return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};
