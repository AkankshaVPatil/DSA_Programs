//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
//235. Lowest Common Ancestor of a Binary Search Tree
//TC - O(log n), SC - O(log n)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};
