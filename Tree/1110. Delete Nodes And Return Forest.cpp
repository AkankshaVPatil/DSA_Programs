//https://leetcode.com/problems/delete-nodes-and-return-forest/description/
//1110. Delete Nodes And Return Forest
// TC - O(N+D) -- D is number nodes to delete
// SC - O(N+D) -- D is number nodes to delete

class Solution {
public:
    TreeNode* helper(TreeNode* root, unordered_set<int>&st, vector<TreeNode*>&ans)
    {
        if(root == NULL) return NULL;

        root->left = helper(root->left, st, ans);
        root->right = helper(root->right, st, ans);
        
        if(st.find(root->val) != st.end()))
        {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        unordered_set<int>st(to_delete.begin(), to_delete.end());

        vector<TreeNode*> ans;
        helper(root, st, ans);
        if(!st.contains(root->val))
            ans.push_back(root);
        return ans;
    }
};
