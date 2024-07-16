//https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
//2096. Step-By-Step Directions From a Binary Tree Node to Another

//--------------Approach-I------
//using BFS graph
//Memory Limit Exceed
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<int, vector<pair<int, char>>>adj;
        queue<TreeNode*>q;
        q.push(root);
        int n = 0;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            n++;
            if(node->left)
            {
                q.push(node->left);
                adj[node->val].push_back({node->left->val, 'L'});
                adj[node->left->val].push_back({node->val, 'U'});
            }
            if(node->right)
            {
                q.push(node->right);
                adj[node->val].push_back({node->right->val, 'R'});
                adj[node->right->val].push_back({node->val, 'U'});
            }
        }

        queue<pair<int, string>>qu;
        vector<bool>visited(n+1, false);
        qu.push({startValue, ""});
        visited[startValue] = true;
        
        while(!qu.empty())
        {
            int u = qu.front().first;
            string path = qu.front().second;
            qu.pop();

            if(u == destValue)
                return path;

            for(auto node:adj[u])
            {
                int v = node.first;
                char dir = node.second;

                if(visited[v] == false)
                {
                    visited[v] = true;
                    qu.push({v, path + dir });
                }
            }
        }
        return "";
    }
};

//------------Approach-II-----
//using LCA
//TC - O(n), SC - O(n)
class Solution {
public:
    TreeNode* getLCA(TreeNode* root, int startValue, int destValue)
    {
        if(root == NULL) return NULL;

        if(root->val == startValue || root->val == destValue)
            return root;

        TreeNode* LeftLCA = getLCA(root->left, startValue, destValue);
        TreeNode* RightLCA = getLCA(root->right, startValue, destValue);

        if(LeftLCA && RightLCA)
            return root;
        else if(LeftLCA)
            return LeftLCA;
        else
            return RightLCA;
    }

    bool findPath(TreeNode* root, int value, string &path)
    {
        if(root == NULL) return false;

        if(root->val == value)
            return true;
        
        path.push_back('L');
        if(findPath(root->left, value, path) == true)
            return true;
        path.pop_back();

        path.push_back('R');
        if(findPath(root->right, value, path) == true)
            return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = getLCA(root, startValue, destValue);
        string leftPath = "", rightPath = "";

        findPath(LCA, startValue, leftPath);
        findPath(LCA, destValue, rightPath);
        string result = "";
        for(auto i:leftPath)
            result += "U";
        
        result += rightPath;
        return result;
    }
};

//------------Approach-III-----
//using LCA
//TC - O(n), SC - O(n)
class Solution {
public:
    bool findPath(TreeNode* root, int value, string &path)
    {
        if(root == NULL) return false;

        if(root->val == value)
            return true;
        
        path.push_back('L');
        if(findPath(root->left, value, path) == true)
            return true;
        path.pop_back();

        path.push_back('R');
        if(findPath(root->right, value, path) == true)
            return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string leftPath = "", rightPath = "";
        findPath(root, startValue, leftPath);
        findPath(root, destValue, rightPath);
        
        int l = 0;
        while(l < leftPath.size() && l < rightPath.size() && leftPath[l] == rightPath[l])
        {
            l++;
        }
        cout << "l " << l << endl;

        string result = "";
        for(int i = l; i < leftPath.size(); i++)
            result += "U";
        
        for(int i = l; i < rightPath.size(); i++)
            result += rightPath[i];
        return result;
    }
};
