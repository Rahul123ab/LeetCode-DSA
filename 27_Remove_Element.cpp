class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        vector<int> ans;
        for(int cur: nums) {
            if(cur != val) {
                ans.push_back(cur);
            }   
        }
        int elementCount=ans.size();

        for(int i=0; i<nums.size(); i++) {

            if(i<elementCount) {
                nums[i]=ans[i];
            } else {
                nums[i]=-1;
            }
        }
        return elementCount;
    }
};