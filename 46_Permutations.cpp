class Solution {
public:

    void getPermutation(vector<int>& nums, int idx, vector<vector<int>>& ans) { //TC=O(n! * n), SC=O(n)

        if(idx == nums.size()) {
            ans.push_back({nums});
            return;
        }

        for(int i=idx; i<nums.size(); i++) {

            swap(nums[idx],nums[i]); //idx place = choice of ith element
            getPermutation(nums, idx+1, ans);

            swap(nums[idx],nums[i]); //backtracking
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutation(nums, 0, ans);
        return ans;
    }
};