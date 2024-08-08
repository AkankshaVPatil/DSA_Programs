// https://leetcode.com/problems/invert-binary-tree/description/
// 226. Invert Binary Tree
// TC - O(n), SC - O(1)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
