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

//-------Approach-III-------
class Solution {
public:
    void TT(TreeNode* root, int level, int &maxlevel)
    {
        if(root == NULL) return;
        maxlevel = max(level, maxlevel);

        TT(root->left, level+1, maxlevel);
        TT(root->right, level+1, maxlevel);
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int maxlevel = 0;
        TT(root, 1, maxlevel);
        return maxlevel;
    }
};
