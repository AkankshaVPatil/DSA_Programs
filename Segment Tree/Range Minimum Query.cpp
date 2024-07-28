//https://www.geeksforgeeks.org/problems/range-minimum-query/1
//Range Minimum Query

//O(n)
void buildSegmentTree(int l, int r, int i, int arr[], int SegmentTree[])
{
    if(l == r)
    {
        SegmentTree[i] = arr[l];
        return;
    }
    
    int mid = l + (r - l)/2;
    
    buildSegmentTree(l, mid, 2*i+1, arr, SegmentTree);
    buildSegmentTree(mid+1, r, 2*i+2, arr, SegmentTree);
    
    SegmentTree[i] = min(SegmentTree[2*i+1], SegmentTree[2*i+2]);
}
/* The functions which 
builds the segment tree */
int *constructST(int arr[],int n)
{
  int *SegmentTree = new int[4 * n];
  
  buildSegmentTree(0, n-1, 0, arr, SegmentTree);
  
  return SegmentTree;
}

//O(logn)
int query(int start, int end, int l, int r, int i, int st[])
{
    if(l > end || r < start)
        return INT_MAX;
    
    if(l >= start && r <= end)
        return st[i];
        
    int mid = l + (r - l)/2;
    
    return min(query(start, end, l, mid, 2*i+1, st), query(start, end, mid+1, r, 2*i+2, st));
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
    
    return query(a, b, 0, n-1, 0, st);
}
