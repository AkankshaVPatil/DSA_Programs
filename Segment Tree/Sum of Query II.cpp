//https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1
//Sum of Query II
// ToBuildSegmentree : TC - O(N), SC - O(N)
// query : TC - O(log n), SC - O(log n)

class Solution{
public:
    void buildSegmentTree(int l, int r, int i, vector<int>&segmentTree, int arr[])
    {
        if(l == r)
        {
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r-l)/2;
        
        buildSegmentTree(l, mid, 2*i+1, segmentTree, arr);
        buildSegmentTree(mid+1, r, 2*i+2, segmentTree, arr);
        
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    
    int query(int start, int end, int l, int r, int i, vector<int>&segmentTree)
    {
        if(r < start || l > end)
            return 0;
            
        else if(start <= l && end >= r)
            return segmentTree[i];
            
        int mid = l + (r-l)/2;
        return query(start, end, l, mid, 2*i+1, segmentTree) 
                + query(start, end, mid+1, r, 2*i+2, segmentTree);
    }
    
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int>segmentTree(4*n);
        
        buildSegmentTree(0, n-1, 0, segmentTree, arr);
        
        vector<int> ans;
        for(int i = 0; i < 2*q; i+=2)
        {
            int start = queries[i] - 1;
            int end = queries[i+1] - 1;
            
            ans.push_back(query(start, end, 0, n-1, 0, segmentTree));
        }
        
        return ans;
    }
};
