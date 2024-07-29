https://leetcode.com/problems/path-sum/description/
//112. Path Sum.cpp
//---------------Approach-I----------
//TC - O(n), sc - O(h)
class Solution {
public:
    bool hasPath = false;
    void helper(TreeNode* root, int &targetSum, int sum)
    {
        if(root == NULL) return;
        sum += root->val;
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == targetSum)
                hasPath = true;
        }

        helper(root->left, targetSum, sum);//5 9 20
        helper(root->right, targetSum, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        helper(root, targetSum, 0);
        return hasPath;
    }
};

//---------------Approach-II----------
//TC - O(n), sc - O(h)
class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;

        if(targetSum - root->val == 0 && root->left == NULL && root->right == NULL)
            return true;

        if(true == hasPathSum(root->left, targetSum - root->val))
            return true;

        if(true == hasPathSum(root->right, targetSum - root->val))
            return true;

        return false;
    }
};
