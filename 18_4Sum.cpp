class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {//TC= O(nlogn + n^3)  SC= O(unique groups)
    
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {//fixing the first element at arr[i]

            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }

            for(int j=i+1; j<n; ) {//fixing the second element at arr[j]
                //apply two pointer approach

                int k=j+1;
                int l=n-1;

                while (k < l) {
                    long long sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
                    if(sum < target) {
                        k++;
                    } else if(sum > target) {
                        l--;
                    } else {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;

                        while (k < l && nums[k]==nums[k-1]) {
                            k++;
                        }
                    }
                }
                j++;
                while(j < k && nums[j]==nums[j-1]) {
                    j++;
                }
            }
        }
        return ans;
    }
};