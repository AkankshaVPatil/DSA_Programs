//https://leetcode.com/problems/binary-tree-inorder-traversal/description/
//94. Binary Tree Inorder Traversal
//Approach-I
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;//4

        while(root != NULL || !st.empty()) // 1 2 
        {
            while(root != NULL)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};

//---------Approach-II----------
class Solution {
public:
    void TT(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL) return;

        TT(root->left, ans);
        ans.push_back(root->val);
        TT(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        vector<int> ans;
        TT(root, ans);
        return ans;
    }
};
