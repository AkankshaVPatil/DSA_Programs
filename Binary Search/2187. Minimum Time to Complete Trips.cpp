//https://leetcode.com/problems/minimum-time-to-complete-trips/
//  2187. Minimum Time to Complete Trips
// TC - O(n * logn), SC - O(1)

class Solution {
public:
    bool posibleToCompleteAllTrips(vector<int>& time, int totalTrips, long long mid)
    {
        long long sum = 0;
        for(auto t:time)
        {
            sum += mid / t;
        }
        if(sum >= totalTrips)
            return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 1;
        long long hi = (long long)*min_element(time.begin(), time.end()) * totalTrips;

        while(lo < hi)//1 < 3
        {
            long long mid = lo + (hi - lo)/2;//2

            if(posibleToCompleteAllTrips(time, totalTrips, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
