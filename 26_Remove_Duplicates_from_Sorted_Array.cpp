class Solution {
public:
    int removeDuplicates(vector<int>& nums) {//TC=O(n), SC=O(1)
        int left = 0, right = 1;

        for(int i = right; i < nums.size(); i++) {
            
            if(nums[left] == nums[right]) {
                right++;
            } else if(nums[right] > nums[left]) {
                left++;
                swap(nums[left],nums[right]);
                right++;
            }
        }
        return left+1;
    }
};