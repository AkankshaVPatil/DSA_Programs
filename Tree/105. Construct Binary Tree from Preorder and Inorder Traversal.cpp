//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
//105. Construct Binary Tree from Preorder and Inorder Traversal
// TC - O(N)
// SC - O(N)
class Solution {
public:
    TreeNode* constructTree(vector<int>& preorder, int &idx, unordered_map<int, int> &umap, int lo, int hi) 
    {
        if(lo > hi) return NULL;

        TreeNode *root = new TreeNode(preorder[idx]);

        int mid = umap[preorder[idx]];
        idx++;

        root->left = constructTree(preorder, idx, umap, lo, mid-1);
        root->right = constructTree(preorder, idx, umap, mid+1, hi);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> umap;
        for(int i = 0; i < inorder.size(); i++)
        {
            umap[inorder[i]] = i;
        }

        int idx = 0;
        return constructTree(preorder, idx, umap, 0, inorder.size()-1);
    }
};
