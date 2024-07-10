//https://leetcode.com/problems/kth-missing-positive-number/description/
//1539. Kth Missing Positive Number

//--------Approach-I------
// TC - O(n), SC - O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        int i = 0;
        while(i < arr.size())
        {
            if(num != arr[i])
            {
                num++;
                k--;
                if(k == 0)
                    break;
            }
            else
            {
                i++;//5
                num++;//8
            }
        }

        while(k--)
            num++;
        return num - 1;
    }
};

//--------Approach-I------
// TC - O(logn), SC - O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size()-1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            int missingnumbers = arr[mid] - (mid + 1);
            if(missingnumbers < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l + k;
    }
};
