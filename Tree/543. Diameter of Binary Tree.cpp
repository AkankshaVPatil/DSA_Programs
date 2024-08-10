//https://leetcode.com/problems/diameter-of-binary-tree/description/
//543. Diameter of Binary Tree
//TC - o(n), SC - o(1)
class Solution {
public:
    int dim = 0;
    int TT(TreeNode* root)
    {
        if(root == NULL) return 0;

        int lh = TT(root->left);
        int rh = TT(root->right);

        dim = max(dim, lh + rh + 1);
        return max(lh, rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        TT(root);
        return dim - 1;
    }
};
