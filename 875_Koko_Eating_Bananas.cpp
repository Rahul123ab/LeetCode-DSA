class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());

        int res = right;
        while (left <= right) {
            int mid = left + (right - left)/2;

            long long hours = 0;

            for(long long val : piles) {
                //hours += ceil((double)(val)/mid);
                hours += (val + mid - 1)/mid;
            }

            if(hours <= h) {
                res = min(res, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;        
    }
};