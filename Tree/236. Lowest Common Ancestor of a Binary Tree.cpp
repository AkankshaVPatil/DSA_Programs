//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
//236. Lowest Common Ancestor of a Binary Tree
// TC - O(N)
// SC - O(H) - height of tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root->val == p->val || root->val == q->val)
            return root;

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA != NULL && rightLCA != NULL)
            return root;
        else if(rightLCA == NULL)
            return leftLCA;
        else
            return rightLCA;
    }
};
