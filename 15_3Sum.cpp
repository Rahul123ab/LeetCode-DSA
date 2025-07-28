class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { //TC = O(nlogn + n^2)  SC=O(unique triplets)
        
        sort(nums.begin(),nums.end()); //sorts the array so as to avoid duplicate triplets
        vector<vector<int>> ans;

        for(int i=0; i<nums.size(); i++) {
            //first element at arr[i]
            //Applying two pointer approach to handle better TC
            int j=i+1;
            int k=nums.size()-1;

            if(i>0 && nums[i]==nums[i-1]) {//to skip the repeating elements at the begining
                continue;
            }

            while (j < k) {

                if(nums[i]+nums[j]+nums[k] < 0) {//meaning we need to add larger element to get 0
                    j++;
                } else if(nums[i]+nums[j]+nums[k] > 0) {//meaning we need to add smaller element to get 0
                    k--;
                } else {//meaning the sum is already 0
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j]==nums[j-1]) {//to skip the repeating elements in the middle
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};