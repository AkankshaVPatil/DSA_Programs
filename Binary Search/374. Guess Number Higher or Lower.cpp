//https://leetcode.com/problems/guess-number-higher-or-lower/description/
//374. Guess Number Higher or Lower
// TC - O(logn), SC - O(n)
class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;

        while(l <= r)// 6 <= 7
        {
            int mid = l + (r - l)/2; //6
            int gs = guess(mid);
            if(gs == 1)
                l = mid + 1;
            else if(gs == -1)
                r = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};
