class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {//TC=O(n), SC=O(n)
        unordered_map<int, int> map;

        for(int i=0; i<nums.size(); i++) {

            if(map.find(nums[i]) != map.end()) {
                return true;
            }
            map[nums[i]]++;
        }
        return false;
    }
};