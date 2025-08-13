class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        if (n <= 2) return n; // already valid

        int left = 2; // next valid write position
        for (int right = 2; right < n; right++) {
            // Compare with element two positions back
            if (nums[right] != nums[left - 2]) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};