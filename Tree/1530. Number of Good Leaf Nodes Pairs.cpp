//https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description
//1530. Number of Good Leaf Nodes Pairs.cpp
// TC - O(N*N), SC - O(N)

class Solution {
public:
    void MakeGraph(TreeNode* root, TreeNode*parent, unordered_map<TreeNode*, vector<TreeNode*>> &adj, unordered_set<TreeNode*> &st)
    {
        if(root == NULL) return;
        if(root->left == NULL && root ->right == NULL)
        {
            st.insert(root);
        }

        if(parent)
        {
            adj[parent].push_back(root);
            adj[root].push_back(parent);
        }

        MakeGraph(root->left, root, adj, st);
        MakeGraph(root->right, root, adj, st);
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;
        MakeGraph(root, NULL, adj, st);

        int PairCount = 0;
        for(auto& leaf:st)
        {
            queue<TreeNode*>q;
            q.push(leaf);
            unordered_set<TreeNode*> visited;
            visited.insert(leaf);
            int level = 0;
            while(!q.empty() && level <=  distance)
            {
                int sz = q.size();
                while(sz--)
                {
                    TreeNode* u = q.front();
                    q.pop();

                    if(u != leaf && st.contains(u))
                        PairCount++;
                
                    for(auto v:adj[u])
                    {
                        if(!visited.contains(v))
                        {
                            q.push(v);
                            visited.insert(v);
                        }
                    }
                }    
                level++;
            }
        }
        return PairCount/2;
    }
};
