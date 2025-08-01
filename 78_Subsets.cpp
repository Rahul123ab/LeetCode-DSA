class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) { //TC=O(n * 2^n)
        if(i==nums.size()){
            //store subset
            allSubsets.push_back({ans});
            return;
        }

        //include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i+1, allSubsets);
        //backtrack
        ans.pop_back();
        //exclude
        getAllSubsets(nums, ans, i+1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};