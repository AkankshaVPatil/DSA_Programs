//https://leetcode.com/problems/range-sum-query-mutable/description/
//307. Range Sum Query - Mutable
//O(logn)
class NumArray {
public:
    vector<int>SegmentTree;
    int n;
    void buildTree(int l, int r, int i, vector<int>&nums)
    {
        if(l == r)
        {
            SegmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l)/2;

        buildTree(l, mid, 2*i+1, nums);
        buildTree(mid+1, r, 2*i+2, nums);

        SegmentTree[i] = SegmentTree[2*i+1] + SegmentTree[2*i+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        SegmentTree.resize(4*n);
        buildTree(0, n-1, 0, nums);
    }
    
    void updateTree(int l, int r, int i, int index, int val)
    {
        if(l == r)
        {
            SegmentTree[i] = val;
            return;
        }

        int mid = l + (r - l)/2;
        if(index <= mid)
            updateTree(l, mid, 2*i+1, index, val);
        else
            updateTree(mid+1, r, 2*i+2, index, val);

        SegmentTree[i] = SegmentTree[2*i+1] + SegmentTree[2*i+2];
    }

    void update(int index, int val) {
        updateTree(0, n-1, 0, index, val);
    }
    
    int query(int start, int end, int l, int r, int i)
    {
        if(l > end || r < start)
            return 0;

        if(l >= start && r <= end)
            return SegmentTree[i];

        int mid = l + (r - l)/2;
        return query(start, end, l, mid, 2*i+1) + query(start, end, mid+1, r, 2*i+2);
    }

    int sumRange(int left, int right) {
        return query(left, right, 0, n-1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
