//https://leetcode.com/problems/check-completeness-of-a-binary-tree/
//958. Check Completeness of a Binary Tree

//--------Approach-I---------
// TC - O(N)
//  SC - O(N)

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root);

        bool isNullNodeFound = false;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL)
            {
                isNullNodeFound = true;
            }
            else
            {
                if(isNullNodeFound == true)
                    return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};

//--------Approach-I---------
// TC - O(N)
//  SC - O(H)
class Solution {
public:
    int countNode(TreeNode* root)
    {
        if(root == NULL) return 0;

        return 1 + countNode(root->left) + countNode(root->right);
    }
    bool isCompleteTree(TreeNode* root, int i, int totalNode)
    {
        if(root == NULL) return true;

        if(i > totalNode)
            return false;
        
        return isCompleteTree(root->left, 2*i, totalNode) && isCompleteTree(root->right, 2*i + 1, totalNode);
    }
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;

        int totalNode = countNode(root);
        return isCompleteTree(root, 1, totalNode);
    }
};
