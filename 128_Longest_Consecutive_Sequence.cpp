class Solution {
public:
    int longestConsecutive(vector<int>& nums) {//TC=SC=O(n) hash set
        unordered_set<int> numset(nums.begin(), nums.end());//intializing hash set with nums values

        int longest = 0;
        for(int val : numset) {
            //check if it's a sequence start
            if(numset.find(val - 1) == numset.end()) {
                int length = 1;
                //count the streak
                while(numset.find(val+length) != numset.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
        
    }
};