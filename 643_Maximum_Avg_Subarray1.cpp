class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowSum=0;

        for(int i=0; i<k; i++) {
            windowSum +=nums[i];
        }
        double maxSum=windowSum;

        for(int j=k;j<nums.size();j++) {
            windowSum = windowSum - nums[j-k] + nums[j];
            maxSum= max(maxSum,windowSum);
        }
        return maxSum/k;
    }
};