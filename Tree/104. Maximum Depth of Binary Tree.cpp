//104. Maximum Depth of Binary Tree
//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
//-----Approach-I-----
class Solution {
public:
    
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//-----Approach-II-----
class Solution {
public:
    int TT(TreeNode* root)
    {
        if(root == NULL) return 0;

        int lh = TT(root->left);
        int rh = TT(root->right);

        return max(lh, rh) + 1;
    }
    int maxDepth(TreeNode* root) {
        return TT(root);
    }
};
