class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {//TC=O(nlog)
        
        //sort the input array and apply sliding window
        sort(nums.begin(),nums.end());

        long left = 0, right = 0;
        long result = 0, total = 0;
        //calculate the total as we move the right pointer
        while(right < nums.size()) {
            total += nums[right];
            //remove the element from left to keep window valid
            while(nums[right] * (right - left + 1) > total + k) {
                total -= nums[left];
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};