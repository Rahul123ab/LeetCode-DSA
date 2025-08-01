class Solution {
public:
    int majorityElement(vector<int>& nums) { //O(n)

        int ans;
        int count=0;
        for(int i=0; i<nums.size(); i++) {

            if(count==0) {
                ans=nums[i];
            }

            if(nums[i]==ans) {
                count++;
            }else {
                count--;
            }
        }
        return ans;
    }
};