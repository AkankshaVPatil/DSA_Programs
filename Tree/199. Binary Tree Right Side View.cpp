//https://leetcode.com/problems/binary-tree-right-side-view/
//199. Binary Tree Right Side View

//-------Approach-I-----
// TC - O(N) {N : number of tree Nodes}
// SC = O(H) {H : height of tree}
class Solution {
public:
    int maxLevel = -1;
    void TreeTraversal(TreeNode* root, vector<int> &vec, int level)
    {
        if(root == NULL) return;
        if(maxLevel < level)
        {
            vec.push_back(root->val);
            maxLevel = level;
        }
        level++;
        TreeTraversal(root->right, vec, level);
        TreeTraversal(root->left, vec, level);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        TreeTraversal(root, vec, 0);
        return vec;
    }
};


//-------Approach-II-----
// TC - O(N) {N : number of tree Nodes}
// SC = O(N) {N : max width of tree}
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};

        queue<TreeNode*>q;
        q.push(root);

        vector<int> ans;

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = sz - 1; i >= 0; i--)
            {
                TreeNode* node = q.front();
                q.pop();

                if(i == sz-1)
                    ans.push_back(node->val);
                
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
            }
        }
        return ans;
    }
};
