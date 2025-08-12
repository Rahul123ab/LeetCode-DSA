class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {//TC=O(n), SC=O(n)

        //count the freq of each element in the input vector
        unordered_map<int,int> count;
        for(int val : nums) {
            count[val]++;
        }

        //hash map + Bucket sort approach
        //arrange the map as per the key #count of the element and value# list of elements
        vector<vector<int>> freq(nums.size() + 1);
        for (pair<int,int> i : count) {
            freq[i.second].push_back(i.first);
        }

        vector<int> result;
        for(int i= freq.size() - 1; i>0; i--) {
            for(int n : freq[i]) {
                result.push_back(n);
                if(result.size() == k) {
                    return result;
                }
            }
        }
        return result;
        
    }
};