//https://leetcode.com/problems/sqrtx/description/
//69. Sqrt(x)
//TC - O(logn), SC - O(1)

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        
        int lo = 2, hi = x/2, res = 1;

        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            
            if((long)mid * mid <= x)
            {
                res = mid;
                lo = mid+1;
            }
            else
                hi = mid - 1;
        }
        return res;
    }
};
