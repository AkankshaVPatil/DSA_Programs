//https://leetcode.com/problems/balanced-binary-tree/description/
//110. Balanced Binary Tree
//TC - O(n), SC - O(1)
class Solution {
public:
    int GetHeight(TreeNode* root, bool& isBlnc)
    {
        if(root == NULL) return 0;

        if(isBlnc == true)
        {
            int leftHeight = GetHeight(root->left, isBlnc);
            int rightHeight = GetHeight(root->right, isBlnc);

            if(abs(leftHeight - rightHeight) > 1)
                isBlnc = false;
        
            return max(leftHeight, rightHeight) + 1;
        }
        return 0;
    } 
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        bool isBlnc = true;
        GetHeight(root, isBlnc);
        return isBlnc;
    }
};
