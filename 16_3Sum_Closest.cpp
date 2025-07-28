class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //difference of sum and target is minimum

        sort(nums.begin(),nums.end());

        int closet_sum=nums[0] + nums[1] + nums[2];
        int min_diff=abs(closet_sum - target);

        for(int i=0; i<nums.size()-2; i++) {
            int j=i+1;
            int k=nums.size()-1;
            
            while (j < k) {
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    return sum;
                }

                int diff = abs(sum - target);

                if (diff < min_diff) {
                    min_diff = diff;
                    closet_sum = sum;
                }
            }
        }
        return closet_sum;
    }
};