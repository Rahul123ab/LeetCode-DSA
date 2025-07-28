class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curr_Sum = 0;
        int maxSum = INT_MIN;

        for (int val : nums) { //o(n)

            curr_Sum += val;
            maxSum = max(maxSum, curr_Sum);

            if (curr_Sum < 0) {
                curr_Sum = 0;
            }
        }
        
        return maxSum;
    }
};